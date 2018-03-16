/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:13:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/16 13:13:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef union			u_color
{
	int		color;
	struct
	{
		unsigned char	blue;
		unsigned char	green;
		unsigned char	red;
		unsigned char	alpha;
	}		spectrum;
}						t_color;

#endif