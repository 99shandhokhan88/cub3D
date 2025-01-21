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

char	*null_dest(char *dst)
{
	dst = (char *)malloc(1 * sizeof(char));
	if (!dst)
		return (NULL);
	dst[0] = '\0';
	return (dst);
}

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

int	matrix_len(char **map)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}
