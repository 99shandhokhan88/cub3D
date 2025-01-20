/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:34:26 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/20 22:53:59 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	init_pars_check(t_game *game, t_file *file)
{
	if (back_slash_trimmer(file) == 1)
		parser_errors(game, "empty file");
	if (size_lst(file) < 9)
		parser_errors(game, "file too small");
}
