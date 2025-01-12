#include "cub3D.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *test;
	size_t i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
		len = 0;
	test = malloc((len + 1) * sizeof(char));
	if (test == NULL)
		return (NULL);
	while (i < len && s[i])
	{
		test[i] = s[start];
		i++;
		start++;
	}
	test[i] = '\0';
	return (test);
}

char *null_dest(char *dst)
{
	dst = (char *)malloc(1 * sizeof(char));
	if (!dst)
		return (NULL);
	dst[0] = '\0';
	return (dst);
}

char *strjoin(char *dst, char *s)
{
	char *res;
	int i;
	int j;

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

int skip_spaces(int i, t_parser *parsed, t_file *init)
{
	int temp;

	temp = i;
	while (init->line[i] && init->line[i] != ',' &&
		   ft_isdigit(init->line[i]))
		i++;
	if (i - temp >= 4 || (ft_isdigit(init->line[i]) == 0 &&
						  init->line[i] != ','))
		parser_errors(parsed, "error rgb code\n");
	i++;
	while (init->line[i] && init->line[i] == ' ')
		i++;
	return (i);
}

void free_map2(char **map)
{
	int i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
		free(map);
	}
}

int matrix_len(char **map)
{
	int len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}

int is_empty(char c)
{
	if (c && c != ' ' && c != '	' && c != '1' && c != '\n')
		return (1);
	return (0);
}
