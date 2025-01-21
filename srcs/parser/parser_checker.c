/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:38:22 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:38:05 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* 
 * Function: check_file
 * ---------------------
 * Checks if the given file has the correct name and extension.
 * The file must end with ".cub".
 *
 * game: The game structure (for error handling).
 * file: The file path to check.
 * 
 * This function exits the program
 * if the file name or extension is incorrect.
 */

void	check_file(t_game *game, char *file)
{
	char	*file_checker;
	size_t	len;

	file_checker = ft_strrchr(file, '.');
	if (file_checker == 0)
	{
		parser_errors(game, "wrong file name");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(file_checker);
	if (len < 4)
		len = 4;
	if (!file_checker || ft_strncmp(file_checker, ".cub", len) != 0 || len == 0)
	{
		parser_errors(game, "wrong file extension");
		exit(EXIT_FAILURE);
	}
}

/* 
 * Function: check_cub
 * --------------------
 * Reads the map file and stores its contents in a linked list.
 * It skips any empty lines at the beginning of the file.
 *
 * mat: Pointer to the linked list that will hold the map data.
 * file: The file path to read.
 */

void	check_cub(t_file **mat, char *file)
{
	int		fd;
	char	*line_map;
	t_file	*new_file;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		handle_escape_file(*mat);
	line_map = get_next_line_map(fd);
	while (line_map && line_map[0] == '\n')
	{
		free(line_map);
		line_map = get_next_line_map(fd);
	}
	while (line_map)
	{
		new_file = list_new(line_map);
		list_add_back(mat, new_file);
		line_map = get_next_line_map(fd);
	}
	close(fd);
}

/* 
 * Function: back_slash_trimmer
 * -----------------------------
 * This function removes empty lines at the beginning
 * of the file or trims
 * unnecessary lines before the first line with '1'.
 * 
 * file: The linked list of lines to trim.
 * Returns: 0 if trimming is successful,
 * 1 if the file is empty or the last line.
 */

int	back_slash_trimmer(t_file *file)
{
	t_file	*trimmed;
	t_file	*temp;

	trimmed = file;
	if (!trimmed)
		return (1);
	if (!trimmed->next)
	{
		free(trimmed->line);
		free(trimmed);
		return (1);
	}
	while ((trimmed->next) && (trimmed->line[0] != '1'))
	{
		if (trimmed->next->line[0] == '\n')
		{
			free(trimmed->next->line);
			temp = trimmed->next->next;
			free(trimmed->next);
			trimmed->next = temp;
		}
		else
			trimmed = trimmed->next;
	}
	return (0);
}

/* 
 * Function: size_lst
 * -------------------
 * Calculates the number of nodes (lines) in the linked list.
 *
 * lst: The linked list whose size is to be calculated.
 * Returns: The size of the list (number of nodes).
 */

int	size_lst(t_file *lst)
{
	int	check;

	check = 0;
	while (lst != NULL)
	{
		check++;
		lst = lst->next;
	}
	return (check);
}

/* 
 * Function: init_pars_check
 * ---------------------------
 * This function performs basic checks
 * on the map file. It verifies if the file
 * is empty and ensures that the file
 * has enough lines (at least 9).
 *
 * game: The game structure (for error handling).
 * file: The linked list containing the map data.
 * 
 * If the file is empty or too small,
 * it triggers an error and terminates the program.
 */

void	init_pars_check(t_game *game, t_file *file)
{
	if (back_slash_trimmer(file) == 1)
		parser_errors(game, "empty file");
	if (size_lst(file) < 9)
		parser_errors(game, "file too small");
}
