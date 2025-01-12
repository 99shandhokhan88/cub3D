#include "cub3D.h"

int	back_slash_trimmer(t_file *init)
{
	t_file	*trimmed;
	t_file	*tmp;

	trimmed = init;
	if (!trimmed)
		return (1);
	if (!trimmed->next)
	{
		free(trimmed->line);
		free(trimmed);
		return (1);
	}
	while (trimmed->next && trimmed->line[0] != '1')
	{
		if (trimmed->next->line[0] == '\n')
		{
			free(trimmed->next->line);
			tmp = trimmed->next->next;
			free(trimmed->next);
			trimmed->next = tmp;
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

void	init_empty(t_file *init)
{
	if (back_slash_trimmer(init) == 1)
	{
		printf(RED BOLD "Error\n" RESET);
		printf("Empty file\n");
		exit(0);
	}
	if (size_lst(init) < 9)
	{
		free_struct(init);
		parser_errors(NULL, "File too small\n");
	}
}
