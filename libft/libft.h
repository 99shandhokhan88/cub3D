/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 00:32:44 by flo-dolc           #+#    #+#             */
/*   Updated: 2025/01/21 01:32:41 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "../incs/cub3D.h"

int		ft_atoi(const char *str);
void	ft_bzero(void *dest, size_t len);
void	*ft_calloc(size_t n, size_t size);
int		ft_isdigit(int arg);
void	*ft_memset(void *dest, int value, size_t len);
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *str, int ch);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
char	*get_next_line_map(int fd);
char	*rest_stash(char *stash);
char	*get_line(char *stat);
char	*put_stash(int fd, char *stash);
int		set_char(char *str);
void	list_add_back(t_file **lst, t_file *new);
t_file	*list_last(t_file *lst);
t_file	*list_new(char *line);

#endif
