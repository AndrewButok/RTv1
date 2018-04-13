/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:02:00 by abutok            #+#    #+#             */
/*   Updated: 2018/04/13 13:02:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		check_sign(char *str)
{
	int m;
	int p;

	m = 0;
	p = 0;
	while (*str)
	{
		m += *str == '-' ? 1 : 0;
		p += *str == '+' ? 1 : 0;
		str++;
	}
	if (m == 1 && p == 0)
		return (-1);
	if ((p == 1 || p == 0) && m == 0)
		return (1);
	return (0);
}

static int		check_dstr(char *str)
{
	int f;

	f = 0;
	while (*str)
	{
		if ((f == 0 && !ft_isdigit(*str) && *str != '.' &&
				*str != '+' && *str != '-') ||
				(f == 1 && !ft_isdigit(*str) && *str != '.'))
			return (0);
		if (f == 0 && ft_isdigit(*str))
			f = 1;
		str++;
	}
	return (1);
}

static int		check_strs(char **strs)
{
	int c;

	c = 0;
	while (strs[c] != NULL)
		c++;
	if (c > 2)
		return (0);
	else
		return (1);
}

void			del_strs(char ***strs)
{
	int c;

	c = -1;
	if (strs == NULL || *strs == NULL)
		return ;
	while ((*strs)[++c] != NULL)
		ft_strdel(&((*strs)[c]));
	free(*strs);
	*strs = NULL;
	return ;
}

double			ft_atod(char *str)
{
	char	**strs;
	int		sign;
	double	ret;
	double	d;

	if (str == NULL || !check_dstr(str))
		return (NAN);
	strs = ft_strsplit(str, '.');
	ret = NAN;
	sign = 0;
	if (check_strs(strs))
	{
		ret = (double)ft_atoi(strs[0]);
		sign = check_sign(strs[0]);
		d = strs[1] == NULL ? 0 : (double)ft_atoi(strs[1]);
		while (d >= 1)
			d /= 10;
		ret += d;
	}
	del_strs(&strs);
	ret = sign == 0 ? NAN : ret;
	ret *= ret > 0 && sign == -1 ? sign : 1;
	return (ret);
}
