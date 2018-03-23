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

t_space		*space_init(char *filename)
{
	t_space *space;
	//todo parse
	space = (t_space*)malloc(sizeof(t_space));
	space->figures = sphere_init(vector_init(0, 0, 3), 1, 0xaa0000, 3);
//	space->figures->next = sphere_init(vector_init(0, -5001, 0), 5000, 0xaaaa00, 2);
//	space->figures->next->next = sphere_init(vector_init(2, 0, 4), 1, 0xaa00, 10);
//	space->figures->next->next->next = sphere_init(vector_init(-2, 0, 4), 1, 0x0000aa, 100);
	space->lights = light_init(LIGHT_TYPE_POINT, vector_init(1, 1, 0), 0.8);
//	space->lights->next = light_init(LIGHT_TYPE_AMBIENT, vector_init(-1, 1, 0), 0);
	return (space);
	filename = NULL;
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
	free(space);
}
