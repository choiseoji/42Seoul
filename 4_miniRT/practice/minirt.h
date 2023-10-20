/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:57:49 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/20 20:49:38 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include "mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# define EPSILON 1e-6

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef	struct s_ray
{
	t_vec	origin;  // 원점 좌표
	t_vec	dir;  // 방향 벡터
}	t_ray;

// -------------sphere----------------

typedef struct s_hit_record
{
	t_vec	p;  // ray와 구가 만나는 지점
	t_vec	normal;  // 법선벡터
	double	t;   // 카메라에서 ray와 구가 만나는 첫 지점까지의 거리
	t_vec	albedo;  // 반사율
}	t_hit_record;

typedef struct s_sphere
{
	t_vec	center; // 구의 정점 좌표
	double	r;  // 구의 반지름
	t_vec	albedo;  // 반사율
	struct s_sphere *next;
}	t_sphere;

// -------------light----------------

typedef struct s_light
{
	t_vec	origin;  // 광원의 원점
	t_vec	light_color;  // 광원의 색
	double	bright_ratio;  // 밝기 정보
}	t_light;

// -------------mlx----------------

typedef struct s_vars
{
	void		*mlx;
	void		*win;
}	t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// vec3.c
t_vec	vec(double x, double y, double z);
t_vec	vec_add(t_vec v1, t_vec v2);
t_vec	vec_sub(t_vec v1, t_vec v2);
t_vec	vec_mul(t_vec v1, double t);
t_vec	vec_div(t_vec v1, double t);
double	length_squared(double x, double y, double z);
double	vec_length(t_vec v1);
double	vec_dot(t_vec v1, t_vec v2);
t_vec	vec_cross(t_vec v1, t_vec v2);
t_vec	vec_unit(t_vec v);
t_vec	ray_at(t_ray ray, double t);

// lighting.c
t_vec   phong_lighting(t_vec ambient, t_sphere *sp, t_hit_record rec, t_ray ray);

// sphere.c
int		hit(t_sphere *sphere, t_ray ray, t_hit_record *rec, double t_min, double t_max);
double	hit_sphere(t_vec center, double radius, t_ray ray);

#endif