/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:02:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/03/16 19:02:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light		*light_init(char type,t_vector o, double intencity, int color)
{
	t_light *new_light;

	new_light = (t_light*)malloc(sizeof(t_light));
	new_light->type = type;
	new_light->o = o;
	new_light->intencity = intencity;
	new_light->color = color;
	return (new_light);
}