/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:40:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/18 15:40:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_space		*space_init(char *filename)
{
	t_space *space;
	//todo parse
	space = (t_space*)malloc(sizeof(t_space));
	space->figures = sphere_init(vector_init(-1, -1, 10), 1, 0x9900, -1);
	space->figures->next = sphere_init(vector_init(0, -1, 15), 1, 0x99ff, 200);
	space->figures->next->next = sphere_init(vector_init(1, 0, 5), 0.5, 0x9900, 20);
	space->lights = light_init(LIGHT_TYPE_POINT, vector_init(-2, 0, 0), 0.4);
	space->lights->next = light_init(LIGHT_TYPE_POINT, vector_init(1, 0, 8), 0.4);
	space->lights->next->next = light_init(LIGHT_TYPE_AMBIENT, vector_init(9, 0, 0), 0);
	space->lights->next->next->next = light_init(LIGHT_TYPE_POINT, vector_init(2, 0, 0), 0.4);
	return (space);
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
