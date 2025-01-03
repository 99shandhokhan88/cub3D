
#include "../include/cub3D.h"

void	check_cub(t_file **init, char *file)
{
	int		fd;
	t_file	*new;
	char	*line_map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("ROMAAAAA\n");
		parsing_handle_escape(*init);
	}
	line_map = get_next_line_map(fd);
	while (line_map && line_map[0] == '\n')
	{
		free(line_map);
		line_map = get_next_line_map(fd);
	}
	while (line_map)
	{
		new = lstnew(line_map);
		lstadd_back(init, new);
		line_map = get_next_line_map(fd);
	}
	//if (errno != 0)
	//{
	//	printf("BARIIIII\n");
	//	parsing_handle_escape(*init);
	//}
	close(fd);
}
