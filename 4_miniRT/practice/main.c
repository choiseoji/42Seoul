/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:57:38 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/18 17:49:42 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ray_color(t_ray ray, t_sphere *sphere)
{
	// t_vec	tmp;
	t_vec	color;
	// t_vec	N;
	t_vec	unit_direction;
	t_vec	ambient;  // 주변 조명 (모든 방향에서 균일하게 떨어지는 조명)
	t_hit_record rec;
	int	is_sphere;
	double	t;
	
	int		flag = 0;
	double t_min = 0;
	double t_max = 100;
	ambient = vec_mul(vec(1, 1, 1), 0.1);  // 주광원 색상 * 주광원 강도

	for(int i = 0; i < 3; i++)
	{
		is_sphere = hit(sphere, ray, &rec, t_min, t_max);
		// ray와 구와 만나거나 제일 앞에 있는 경우
		if (is_sphere == 1)  // 구
		{
			flag = 1;  // 플래그 켜주기
			// tmp = ray_at(ray, rec.t);   // 구와 ray가 만나는 지점
			// N = vec_unit(vec(tmp.x - sphere->center.x, tmp.y - sphere->center.y, tmp.z - sphere->center.z)); // tmp에서의 법선벡터 (구와 만나는 지점과 구의 원점 (0, 0, -1)의 벡터이니깐 법선 벡터가 됨)
			// color = vec_mul(vec(N.x + 1, N.y + 1, N.z + 1), 0.5);
			color = phong_lighting(ambient, sphere, rec, ray);
			t_max = rec.t;
		}
		sphere = sphere->next;
	}
	// 아무 구와도 만나지 않으면 그냥 배경색
	if (flag == 0)
	{
		unit_direction = vec_unit(ray.dir);
		t = 0.5 * (unit_direction.y + 1.0);
		color = vec_add(vec_mul(vec(1, 1, 1), 1.0 - t), vec_mul(vec(0.5, 0.7, 1.0), t));
	}
	return ((int)(255.999 * color.x) << 16 | (int)(255.999 * color.y) << 8 | (int)(255.999 * color.z));
}

void print(t_data image, t_sphere *sphere)
{
	// image
	double aspect_ratio = 16.0 / 9.0;   // 화면비
	int image_width = 1000;
	int image_height = (int)((double)image_width / aspect_ratio);
	
	// camera
	double viewport_height = 2.0;
	double viewport_width = aspect_ratio * viewport_height;
	double focal_length = 1.0;
	
	// lower_left_corner 구하기
	// (-focal_length), (-viewport_height / 2), (-viewport_width / 2) 벡터들의 합
	t_vec	vertical = vec(0, -viewport_height, 0);  // (-viewport_height / 2)
	t_vec	horizontal = vec(viewport_width, 0, 0); // (-viewport_width / 2)
	t_vec lower_left_corner = 
	vec(0 + (- horizontal.x / 2) + (-vertical.x / 2) + (0)
		 ,0 + (- horizontal.y / 2) + (- vertical.y / 2) + (0) 
		 ,0 + (- horizontal.z / 2) + (-vertical.z / 2) + (-focal_length));
	
	// ray
	for(int j = image_height - 1; j >= 0; j--)
	{
		for(int i = 0; i < image_width; i++)
		{
			double u = (double)i / (image_width - 1);
			double v = (double)j / (image_height - 1);
			t_ray	r;
			r.origin = vec(0, 0, 0);
			r.dir = vec(lower_left_corner.x + u * horizontal.x + v * vertical.x - r.origin.x,
			lower_left_corner.y + u * horizontal.y + v * vertical.y - r.origin.y,
			lower_left_corner.z + u * horizontal.z + v * vertical.z - r.origin.z);
			// 여기가 포인트 (ray_color)
			my_mlx(&image, i, j, ray_color(r, sphere));
		}
	}
}

int	main(void)
{
	t_vars	vars;
	t_data	image;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 562, "");
	image.img = mlx_new_image(vars.mlx, 1000, 562);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);

	// 구 정보
	t_sphere	*sphere1;
	t_sphere	*sphere2;
	t_sphere	*sphere3;

	sphere1 = (t_sphere *)malloc(sizeof(t_sphere));
	sphere2 = (t_sphere *)malloc(sizeof(t_sphere));
	sphere3 = (t_sphere *)malloc(sizeof(t_sphere));
	sphere1->center = vec(-2, 0, -5);
	sphere1->r = 2;
	sphere1->albedo = vec(0.5, 0, 0);  // 빨강
	sphere2->center = vec(0, -1001, 0);
	sphere2->r = 1;  // 999
	sphere2->albedo = vec(1, 1, 1);  // 검정
	sphere2->next = NULL;
	sphere1->next = sphere2;
	sphere3->center = vec(2, 0, -5);
	sphere3->r = 2;
	sphere3->albedo = vec(0, 0.5, 0);  // 초록
	sphere3->next = NULL;
	sphere2->next = sphere3;
	// 
	print(image, sphere1);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
