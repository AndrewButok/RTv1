/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:16:00 by abutok            #+#    #+#             */
/*   Updated: 2018/03/16 10:16:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

double			vscalar_multiple(t_vector a, t_vector b);
t_vector		vk_multiple(t_vector vector, double k);
t_vector		vvector_multiple(t_vector a, t_vector b);
t_vector		vector_sum(t_vector a, t_vector b);
t_vector		vector_sub(t_vector a, t_vector b);
t_vector		vector_normalize(t_vector a);
double			vector_len(t_vector a);

#endif
