/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:12:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/16 10:12:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "libft.h"
# include "get_next_line.h"
# include "vector.h"
# include "figure.h"
# include "light.h"
# include <errno.h>
# include <stdio.h>
# include <mlx.h>
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct	s_view
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*scene;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

}				t_view;

#endif
