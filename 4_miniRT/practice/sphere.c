/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:17:59 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/16 22:12:05 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere *sphere_init(t_vec	center, t_vec albedo, double r)
{
	t_sphere *sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	sphere->center = center;
	sphere->albedo = albedo;
	sphere->r = r;
	return (sphere);
}

// 법선 벡터의 방향을 판별하는 함수
// 카메라의 위치 표시하는 플래그 값 저장해두기
t_vec	set_face_normal(t_vec normal, t_ray ray)
{
	if (vec_dot(ray.dir, normal) > 0.0)
	{
		return (vec(-normal.x, -normal.y, -normal.z));  // 내각한 결과가 양수이면 카메라가 구의 안쪽에 있다는 뜻. 법선벡터의 방향 바꿔주기
	}
	return (normal);  // 카메라가 구의 바깥에 있으면 그대로 리턴하기
}

// hit_record에 저장 (리턴 : 0이면 저장 못 함)
int	hit(t_sphere *sphere, t_ray ray, t_hit_record *rec, double t_min, double t_max)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;  // 카메라에서 ray와 구가 만나는 첫 지점까지의 거리
	t_vec	oc;
	t_vec	normal;
	
	oc = vec_sub(ray.origin, sphere->center);
	a = vec_dot(ray.dir, ray.dir);
	b = 2.0 * vec_dot(oc, ray.dir);
	c = vec_dot(oc, oc) - sphere->r * sphere->r;
	discriminant = b * b - 4 * a * c;
	sqrtd = sqrt(discriminant);
	root = (-b - sqrtd) / (2 * a);  // 첫번째 해
	if (discriminant < 0)
		return (0);
	if (root < t_min || root > t_max)
	{
		root = (-b + sqrtd) / (2 * a);  // 두번째 해
		if (root < t_min || root > t_max)
			return (0);   // return (false)
	}
	rec->albedo = sphere->albedo;   // 광원 정보 추가
	rec->t = root;
	rec->p = ray_at(ray, rec->t);
	// 법선 벡터의 방향을 계산해서 써줘야 함.
	normal = vec_div((vec_sub(rec->p, sphere->center)), sphere->r);
	rec->normal = set_face_normal(normal, ray);
	return (1);  // return (true)
}
