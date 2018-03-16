/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:58:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/16 11:58:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "figure.h"

double		check_intersection(t_ray ray, t_figure figure)
{
	if (figure.figure == sphere)
		return (check_spere_intersection(ray, figure));
}