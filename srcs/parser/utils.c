/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:01:37 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:38:48 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Function: file_lines_checker
 * -----------------------------
 * This function verifies that the contents
 * of a given line in the file are
 * valid according to specific rules.
 * It checks for the presence of digits and 
 * ensures that the line does not exceed three characters 
 * (except for the newline).
 *
 * game: The game structure used for error handling.
 * file: The file structure holding the current line to check.
 * i: The starting index in the line to begin checking.
 * 
 * If any of the conditions are violated, 
 * an error is raised by calling `parser_errors`.
 */

void	file_lines_checker(t_game *game, t_file *file, int i)
{
	int	count;

	count = 0;
	while (file->line[i] != '\n')
	{
		if (count >= 3)
			parser_errors(game, "file_lines_checker");
		if (ft_isdigit(file->line[i]) == 0 && file->line[i] != '\n')
			parser_errors(game, "file_lines_checker");
		count++;
		i++;
	}
}

/* 
 * Function: null_dest
 * -------------------
 * Allocates memory for a null-terminated
 * empty string and returns the pointer.
 *
 * dst: The destination string
 * to be replaced with an empty string.
 * 
 * Returns: A pointer to an empty string (`""`), 
 * or `NULL` if memory allocation fails.
 */

char	*null_dest(char *dst)
{
	dst = (char *)malloc(1 * sizeof(char));
	if (!dst)
		return (NULL);
	dst[0] = '\0';
	return (dst);
}

/* 
 * Function: ft_strjoin
 * ---------------------
 * Concatenates two strings (`dst` and `s`)
 * into a new dynamically allocated string.
 * If `dst` is `NULL`, it is treated as an empty string.
 * After the operation, `dst`
 * is freed.
 *
 * dst: The destination string (which is modified 
 * to be the concatenated result).
 * s: The string to append to `dst`.
 * 
 * Returns: A new string containing `dst` 
 * followed by `s`, or `NULL` if memory allocation fails.
 */

char	*ft_strjoin(char *dst, char *s)
{
	char	*res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!dst)
		dst = null_dest(dst);
	res = (char *)malloc((ft_strlen(s) + ft_strlen(dst) + 1) * sizeof(char));
	if (!res)
		return (free(dst), NULL);
	i = -1;
	j = -1;
	if (dst)
	{
		while (dst[++i])
			res[i] = dst[i];
	}
	while (s[++j])
		res[i++] = s[j];
	res[i] = '\0';
	free(dst);
	return (res);
}

/* 
 * Function: skip_spaces
 * ----------------------
 * This function skips through spaces
 * and checks the validity of a portion of
 * the RGB color code in the given line.
 * It ensures the format is correct and
 * no errors are present.
 *
 * i: The current index in the line where spaces or digits may be present.
 * game: The game structure used for error handling.
 * init: The initial file structure containing the line to check.
 * 
 * Returns: The updated index `i`
 * after skipping the necessary spaces and checking
 * the RGB code.
 */

int	skip_spaces(int i, t_game *game, t_file *init)
{
	int	temp;

	temp = i;
	while (init->line[i] && init->line[i] != ','
		&& ft_isdigit(init->line[i]))
		i++;
	if (i - temp >= 4
		|| (ft_isdigit(init->line[i]) == 0 && init->line[i] != ','))
		parser_errors(game, "error rgb code");
	i++;
	while (init->line[i] && init->line[i] == ' ')
		i++;
	return (i);
}

/* 
 * Function: matrix_len
 * --------------------
 * This function calculates the length (number of rows)
 * of a 2D array of strings
 * representing a map.
 *
 * map: The 2D array (array of strings) representing the map.
 * 
 * Returns: The number of strings (rows) in the 2D array.
 */

int	matrix_len(char **map)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}
