/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 12:45:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/17 12:45:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int		set_brightness(int color, double brightness)
{
	t_color color_t;

	brightness = brightness > 1 ? 1 : brightness;
	color_t.color = color;
	color_t.spectrum.red = (unsigned char)(color_t.spectrum.red * brightness);
	color_t.spectrum.green = (unsigned char)(color_t.spectrum.green * brightness);
	color_t.spectrum.blue = (unsigned char)(color_t.spectrum.blue * brightness);
	return (color_t.color);
}