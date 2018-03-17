/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:07:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/16 15:07:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "vector.h"
# include "color.h"

enum			e_light
{
	ambient = 0,
	point = 1,
	directional = 2
};

typedef struct	s_light
{
	char		type;
	double		intencity;
	t_color		color;
	t_vector	o;
}				t_light;

t_light		light_init(char type,t_vector o, double intencity, t_color color);

#endif