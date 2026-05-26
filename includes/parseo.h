/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:28 by juan-her          #+#    #+#             */
/*   Updated: 2026/05/26 14:20:18 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSEO_H
#define PARSEO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef struct s_line
{
	char *text;
	struct s_line *next;
}	t_line;


typedef struct s_header
{
	char	*text_no;
	char	*text_so;
	char	*text_we;
	char	*text_ea;
	char	*color_f;
	char	*color_c;

} t_header;

typedef struct s_map
{
	char	**map;
	int		height;
	int		len_max;

} t_map;

typedef struct s_parseo
{
	t_header	*header;
	t_map		*map;
	float		player_x;
	float		player_y;
	int			i;
	int			fd;
	char		player_dir;
} t_parseo;

//**************PARSE*****************************
int		ft_init_parse(t_parseo *parse);
char	*get_next_line(int fd);
int		ft_parse(t_parseo *parse);
char	*ft_header(t_parseo *parse);
int		ft_inst_header(t_header **head, const char *line);
int		ft_check_header(t_header *h);
int		ft_read_map(t_parseo *parse, t_line **list);
char	**ft_norm_map(t_line *lst, t_parseo *parse);
int		ft_val_map(char **map, int height, int width);

//**************UTILS*****************************
void	ft_skip_spc(const char *line, int *i);
int		ft_len_dir(const char *line, int start);
t_line	*ft_new_line(char *line);
void	ft_add_line(t_line **lst, t_line *new);
int		ft_len_lines(t_line *list);
int		ft_is_valid(char c);
int		ft_check_each_space(char **map, int y, int x);
int		ft_is_space(char c);
int		ft_check_inside(char **map, int y, int x);

//**************CLEAN*****************************
void	ft_free_split(char **split);
void	ft_del_list(t_line **list);

#endif

