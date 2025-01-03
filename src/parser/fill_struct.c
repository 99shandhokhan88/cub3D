
#include "../include/cub3D.h"

int	direction(t_parser *parsed, t_file *init, char *dir, char **path)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (init->line && init->line[i] == ' ')
		i++;
	if (ft_strncmp(&init->line[i], dir, len_str(dir)) == 0)
	{
		i += 2;
		while (init->line[i] == ' ')
			i++;
		if (*path != NULL)
			parser_errors(parsed, "This dir already exists\n");
		while (init->line[i])
		{
			i++;
			len++;
		}
		*path = ft_substr(init->line, i - len, len - 1);
		if (*path == NULL)
			parser_errors(parsed, "Substr error malloc\n");
		return (1);
	}
	return (0);
}

int fill_ceiling(t_parser *parsed, t_file *init, int *index)
{
    parsed->ceiling.red = my_atoi(&init->line[*index]);
    if (parsed->ceiling.red > 255 || parsed->ceiling.red < 0 \
        || !ft_isdigit(init->line[*index]))
        parser_errors(parsed, "Wrong red code\n");
    
    *index = skip_spaces(*index, parsed, init);
    parsed->ceiling.green = my_atoi(&init->line[*index]);
    if (parsed->ceiling.green > 255 || parsed->ceiling.green < 0 \
        || !ft_isdigit(init->line[*index]))
        parser_errors(parsed, "Wrong green code\n");
    
    *index = skip_spaces(*index, parsed, init);
    parsed->ceiling.blue = my_atoi(&init->line[*index]);
    if (parsed->ceiling.blue > 255 || parsed->ceiling.blue < 0 \
        || !ft_isdigit(init->line[*index]))
        parser_errors(parsed, "Wrong blue code\n");
    
    return (0);
}

int fill_floor(t_parser *parsed, t_file *init, int *index)
{
    parsed->floor.red = my_atoi(&init->line[*index]);
    if (parsed->floor.red > 255 || parsed->floor.red < 0 \
        || !ft_isdigit(init->line[*index]))
        parser_errors(parsed, "Wrong red code\n");
    
    *index = skip_spaces(*index, parsed, init);
    parsed->floor.green = my_atoi(&init->line[*index]);
    if (parsed->floor.green > 255 || parsed->floor.green < 0 \
        || !ft_isdigit(init->line[*index]))
        parser_errors(parsed, "Wrong green code\n");
    
    *index = skip_spaces(*index, parsed, init);
    parsed->floor.blue = my_atoi(&init->line[*index]);
    if (parsed->floor.blue > 255 || parsed->floor.blue < 0 \
        || !ft_isdigit(init->line[*index]))
        parser_errors(parsed, "Wrong blue code\n");
    
    return (0);
}

void	the_checker(t_parser *parsed, t_file *init, int i)
{
	int	count;

	count = 0;
	while (init->line[i] != '\n')
	{
		if (count >= 3)
			parser_errors(parsed, "error color or ceiling\n");
		if (ft_isdigit(init->line[i]) == 0 && init->line[i] != '\n')
			parser_errors(parsed, "error color or ceiling\n");
		count++;
		i++;
	}
}

int	background_fill(t_parser *parsed, t_file *init, char platform, int *flag)
{
	int	i;

	i = 0;
	while (init->line && init->line[i] == ' ')
		i++;
	i++;
	if (init->line[i - 1] == platform)
	{
		if (*flag == 0)
			*flag = 1;
		else
			parser_errors(parsed, "There is already a background.\n");
		while (init->line && init->line[i] == ' ')
			i++;
		if (init->line[i] < '0' && init->line[i] > '9')
			parser_errors(parsed, "Wrong color code\n");
		if (platform == 'F')
			fill_floor(parsed, init, &i);
		if (platform == 'C')
			fill_ceiling(parsed, init, &i);
		the_checker(parsed, init, i);
		return (1);
	}
	return (0);
}

void	struct_filler(t_parser *parsed, t_file *init)
{
	int	check;
	int	count;
	int	ceiling;
	int	floor;

	count = 0;
	ceiling = 0;
	floor = 0;
	parsed->init = init;
	while (init && count < 6)
	{
		check = 0;
		check += direction(parsed, init, "NO", &parsed->textures_parse.north);
		check += direction(parsed, init, "EA", &parsed->textures_parse.east);
		check += direction(parsed, init, "SO", &parsed->textures_parse.south);
		check += direction(parsed, init, "WE", &parsed->textures_parse.west);
		check += background_fill(parsed, init, 'F', &floor);
		check += background_fill(parsed, init, 'C', &ceiling);
		if (check <= 0)
			parser_errors(parsed, "Lacks something\n");
		count++;
		init = init->next;
	}
	fill_map(parsed, init);
}
