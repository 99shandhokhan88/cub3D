
#include "../include/cub3D.h"

char	*ft_strrchr(char const *s, int c)
{
	char	*str;
	int		count;

	str = (char *)s;
	s = (char *)s;
	count = len_str(s) - 1;
	str += count;
	while (count > -1)
	{
		if ((unsigned char)*str == (unsigned char)c)
		{
			s += count;
			return ((char *)s);
		}
		str--;
		count--;
	}
	if (!(unsigned char)c)
	{
		count = len_str(s);
		s += count;
		return ((char *)s);
	}
	return (NULL);
}

char	*ft_strchr(char const *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (!(unsigned char)c)
		return ((char *)s);
	return (NULL);
}


void	*set_to_zero(void *space, int zero, size_t dimension)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)space;
	i = 0;
	while (i < dimension)
		temp[i++] = zero;
	return (space);
}

void	*alloc_with_zero(size_t type_count, size_t size)
{
	void	*res;
	int		len;

	if (type_count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	len = type_count * size;
	res = (void *) malloc(len);
	if (res == NULL)
		return (NULL);
	set_to_zero(res, '\0', len);
	return (res);
}

size_t	len_str(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}



int	my_atoi(const char *str)
{
	int	i;
	int	s;
	int	res;

	s = 1;
	i = 0;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
		i++;
	if (str[i] == '+')
	{
		i++;
	}
	else if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (str[i] - 48) + (res * 10);
		i++;
	}
	return (res * s);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*test;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (len_str(s) < len)
		len = len_str(s);
	if (len + start > len_str(s))
		len = len_str(s) - start;
	if (len_str(s) < start)
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = len_str(s) + 1;
	dest = (char *)malloc(len * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*null_dest(char	*dst)
{
	dst = (char *)malloc(1 * sizeof(char));
	if (!dst)
		return (NULL);
	dst[0] = '\0';
	return (dst);
}

char	*strjoin(char *dst, char *s)
{
	char	*res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!dst)
		dst = null_dest(dst);
	res = (char *)malloc((len_str(s) + len_str(dst) + 1) * sizeof(char));
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

int	skip_spaces(int i, t_parser *parsed, t_file *init)
{
	int	temp;

	temp = i;
	while (init->line[i] && init->line[i] != ',' && \
	ft_isdigit(init->line[i]))
		i++;
	if (i - temp >= 4 || (ft_isdigit(init->line[i]) == 0 && \
	init->line[i] != ','))
		parser_errors(parsed, "error rgb code\n");
	i++;
	while (init->line[i] && init->line[i] == ' ')
		i++;
	return (i);
}

int	file_len(t_file *file)
{
	int	i;

	i = 0;
	if (file == NULL)
		return (i);
	while (file)
	{
		i++;
		file = file->next;
	}
	return (i);
}

void	free_map2(char **map)
{
	int	i;

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

int	matrix_len(char **map)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}

int	is_empty(char c)
{
	if (c && c != ' ' && c != '	' && c != '1' && c != '\n')
		return (1);
	return (0);
}
