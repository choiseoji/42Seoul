/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:18:55 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/23 12:46:47 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include "get_next_line.h"

typedef struct s_map {
	double	x;
	double	y;
	double	z;
	int		color;
}t_map;

typedef struct s_vars {
	void	*ptr;
	void	*win;
}t_vars;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_image;

typedef struct s_info {
	int		x_size;
	int		y_size;
	int		gap;
	char	*arr;
	char	**split_arr;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
}t_info;

typedef struct s_trgb {
	int	t;
	int	r;
	int	g;
	int	b;
}t_trgb;

typedef struct s_color {
	int		s_color;
	int		e_color;
	t_trgb	start;
	t_trgb	end;
	t_trgb	cur;
}t_color;

typedef struct s_dda {
	int		i;
	int		j;
	double	s_x;
	double	s_y;
	double	e_x;
	double	e_y;
	double	delta_x;
	double	delta_y;
	double	gradient_x;
	double	gradient_y;
}t_dda;

// check_input
int		get_x(char *str);
char	*strjoin_with_space(char const *s1, char const *s2);
void	check_x_size(int fd, int *x, int *y, t_info *info);
void	invalid_map(char *file, t_info	*info);
void	invalid_file(char **av, t_info *info);
// set_xyz_color
char	check_ch(char *str, char *base);
int		calculate(char *str, char *base, int size, int idx);
int		set_color(char *str);
void	set(int i, int j, t_info *info, t_map **map);
t_map	**set_xyz_color(t_info *info);
// rotate
void	find_min_max(t_info *info, t_map **map, int i, int j);
void	rotate_x(double *x, double *y, double *z);
void	rotate_z(double *x, double *y, double *z);
void	rotate(t_info *info, t_map **map);
// final_set_xy
void	set_start(int *x_start, int *y_start, t_info *info);
void	set_gap(t_info *info);
void	xy_with_gap(t_info *info, t_map **map);
void	final_set_xy(t_info *info, t_map **map);
// draw_line
void	set_next_x(t_dda *set, t_map **map, t_color *color);
void	set_next_y(t_dda *set, t_map **map, t_color *color);
void	draw_line( t_info *info, t_image *image, t_map **map);
// get_trgb
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		make_color_int(int t, int r, int g, int b);
// dda
void	set_color_trgb(t_color *color);
void	set_gradient(t_dda *set, double *dis);
void	set_cur_color(t_color *color, t_dda *set, double cur_x, double cur_y);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	dda(t_dda *set, t_image	*image, t_color *color);
// split
int		count(char const *s, char c);
char	*allocate_word(int idx, char const *s, char c);
char	**free_all(char **result);
char	**ft_split(char const *s, char c);
// utils
void	invalid_file_error(void);
void	swap(double *a, double *b);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_atoi(char *str);

#endif
