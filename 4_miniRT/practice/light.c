/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:17:59 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/20 21:30:27 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 광원 초기화
t_light *light_init(t_vec light_origin, t_vec light_color, double bright_ratio)
{
    t_light *light;

    light = (t_light *)malloc(sizeof(t_light));
    light->origin = light_origin;
    light->light_color = light_color;
    light->bright_ratio = bright_ratio;
    return (light);
}

// diffuse lighting 계산 (난반사 조명 : 빛의 강도 * (오브젝트의 법선 벡터와 빛의 방향 벡터 간의 내적))
t_vec   get_diffuse(t_hit_record rec)
{
    t_vec   diffuse_color;
    t_vec   light_dir;
    double  kd;  // 난반사 조명의 강도

    // 난반사 원점 (0, 5, 0)으로 설정함
    light_dir = vec_unit(vec_sub(vec(0, 5, 0), rec.p));  // 오브젝트와 ray만나는 그 지점에서와 조명의 원점을 빼면 방향벡터 나옴
    kd = vec_dot(light_dir, rec.normal);
    diffuse_color = vec_mul(vec(1, 1, 1), kd);
    return (diffuse_color);
}

t_vec   get_specular(t_hit_record rec, t_ray ray)
{
    t_vec   specular;
    t_vec   view_dir;
    t_vec   light_dir;
    t_vec   reflect_dir;
    double  ksn;
    double  ks;
    double  spec;
    
    light_dir = vec_unit(vec_sub(vec(0, 5, 0), rec.p));
    view_dir = vec_unit(vec_mul(ray.dir, -1));
    // 여기 식  고치기
    reflect_dir = vec_sub(vec_mul(vec_mul(rec.normal, vec_dot(light_dir, rec.normal)), 2), light_dir);
    ksn = 64;
    ks = 0.5;  // 강도
    spec = pow(fmax(vec_dot(view_dir, reflect_dir), 0.0), ksn);
    specular = vec_mul(vec_mul(vec(1, 1, 1), ks), spec);
    return (specular);
}

// phong lighting 을 통해 색을 결정해주는 함수
// 조명 정보가 여러개 있을텐데
// diffuse + specular을 다 해주고 마지막에 ambient 더해줌
// 다 더한 값에 (빛의 총량) * (오브젝트 반사율) 해주면 색을 결정할 수 있음.
// 만약 vec(1, 1, 1)을 넘긴다면 vec(1, 1, 1) 반환
t_vec   phong_lighting(t_vec ambient, t_sphere *sp, t_hit_record rec, t_ray ray, t_sphere *sp_list)
{
    t_vec   light_color;  // 광원 색상 설정
    double  brightness;

    // shadow
    double  light_len;
    t_ray   light_ray;
    t_vec   light_dir;

    light_color = vec(0, 0, 0);  // 빛이 없는 경우로 초기화
    // shadow
    light_dir = vec_sub(vec(0, 10, 0), rec.p);
    light_len = vec_length(light_dir);
    light_ray.dir = light_dir;
    light_ray.origin = vec_add(rec.p, vec_mul(rec.normal, EPSILON));
    double t_min = 0;
    double t_max = light_len;
    for(int i = 0; i < 3; i++)
    {
        if (!(sp->center.x == sp_list->center.x && sp->center.y == sp_list->center.y
        && sp->center.z == sp_list->center.z))
        {
            if (hit(sp_list, light_ray, &rec, t_min, t_max))
                return (light_color);
        }
        sp_list = sp_list->next;
    }

    // 조명 정보가 하나 있다고 가정
    light_color = vec_add(light_color, get_diffuse(rec));
    light_color = vec_add(light_color, get_specular(rec, ray));
    brightness =  0.5 * 3;  // 밝기 비율 * 밝기 강도 
    light_color = vec_mul(light_color, brightness);
    // 최종으로 ambient 더해줌
    light_color = vec_add(light_color,ambient);
    // (빛의 총량 * 오브젝트의 반사율)을 곱해줌
    light_color = vec(light_color.x * sp->albedo.x,
    light_color.y * sp->albedo.y,
    light_color.z * sp->albedo.z);
    // (1, 1, 1)보다 큰 경우는 아직 추가하지 않음.
    if (light_color.x > 1)
        light_color.x = 1;
    if (light_color.y > 1)
        light_color.y = 1;
    if (light_color.z > 1)
        light_color.z = 1;
    return (light_color);
}
