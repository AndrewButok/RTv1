/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:40:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/22 20:15:45 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**	todo parse
*/

void		space_init(char *filename, t_view *view)
{
	view->space = (t_space*)malloc(sizeof(t_space));
	view->space->cam = ray_init(vector_init(0, -1, -8), vector_init(0, 0, 0));
	view->space->figures = plane_init(vector_init(0, -1, 0), -3, 0xaaaa00, 200);
	view->space->figures->next = sphere_init(vector_init(0, -1, 3), 1, 0xaa0000, 100);
	view->space->figures->next->next = sphere_init(vector_init(2, 0, 4), 1, 0xaa00, 100);
	view->space->figures->next->next->next = sphere_init(vector_init(-2, 0, 4), 1, 0x0000aa, 100);
	view->space->figures->next->next->next->next =sphere_init(vector_init(0, 1, 3), 0.5, 0x9900aa, 100);
	view->space->figures->next->next->next->next->next = cone_init(ray_init(
			(t_vector){0, 0, 6}, (t_vector){0, -1, 0}), 0.25, 0xffff, 100);
	view->space->figures->next->next->next->next->next->next = cylinder_init
			(ray_init((t_vector){-5, 0, 6},(t_vector){0, -1, 0}), 1,
					0x00ff00, 200);
	view->space->lights = light_init(LIGHT_TYPE_POINT, vector_init(6, 6, -8), 0.8);
	//view->space->lights->next = light_init(LIGHT_TYPE_AMBIENT, vector_init(-1, 1,
			//0), 0.1);
//	view->space->lights->next = light_init(LIGHT_TYPE_POINT, vector_init(6,
//			10, 2), 0.3);
	parse_space(filename, view);
}

void		cam_rotate(t_ray *ray, t_vector vector)
{
	vector = vk_multiple(vector, M_PI / 180);
	if (vector.x != 0)
		rotate_x(&ray->v, vector.x);
	if (vector.y != 0)
		rotate_y(&ray->v, vector.y);
	if (vector.z != 0)
		rotate_z(&ray->v, vector.z);
}

void		space_destroy(t_space *space)
{
	t_figure	*figure;
	t_light		*light;

	while (space->figures != NULL)
	{
		figure = space->figures->next;
		free(space->figures);
		space->figures = figure;
	}
	while (space->lights != NULL)
	{
		light = space->lights->next;
		free(space->lights);
		space->lights = light;
	}
	free(space->cam);
	free(space);
}
