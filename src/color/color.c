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

#include "rtv1.h"

int		set_brightness(int color, double brightness, double bbrightness)
{
	t_color	color_t;
	int		d;

	brightness += bbrightness;
	brightness = brightness > 1 ? 1 : brightness;
	bbrightness = bbrightness > 1 ? 1 : bbrightness;
	color_t.color = color;
	d = (int)(color_t.spectrum.red * brightness);
	d = d > 255 ? 255 : d;
	d = d < 0 ? 0 : d;
	color_t.spectrum.red = (unsigned char)(d + (int)((255 - color_t.spectrum.red) * bbrightness));
	d = (int)(color_t.spectrum.green * brightness);
	d = d > 255 ? 255 : d;
	d = d < 0 ? 0 : d;
	color_t.spectrum.green = (unsigned char)(d + (int)((255 - color_t.spectrum.green) * bbrightness));
	d = (int)(color_t.spectrum.blue * brightness);
	d = d > 255 ? 255 : d;
	d = d < 0 ? 0 : d;
	color_t.spectrum.blue = (unsigned char)(d + (int)((255 - color_t.spectrum.blue) * bbrightness));
	return (color_t.color);
}