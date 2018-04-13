/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 22:38:00 by abutok            #+#    #+#             */
/*   Updated: 2018/04/09 22:38:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	check_braces(const char *str, t_view *view)
{
	int	sb_up;
	int	fb_up;
	int	q_up;

	sb_up = 0;
	fb_up = 0;
	q_up = 0;
	if (str == NULL)
		null_str_error(view);
	while (*str)
	{
		sb_up += *str == '[';
		sb_up -= *str == ']';
		fb_up += *str == '{';
		fb_up -= *str == '}';
		q_up += *str == '"';
		str++;
	}
	if (sb_up != 0)
		sb_up_error(view);
	if (fb_up != 0)
		fb_up_error(view);
	if (q_up % 2)
		q_up_error(view);
}


static char	*read_space(char *filename, t_view *view)
{
	char	*rslt;
	char	*a;
	char	*b;
	int		fd;
	int		e;

	errno = 0;
	fd = open(filename, O_RDONLY);
	if (errno != 0)
		read_error(view);
	rslt = NULL;
	b = NULL;
	while ((e = get_next_line(fd, &b)) > 0)
	{
		a = rslt;
		rslt = ft_strjoin(a, b);
		ft_strdel(&a);
		ft_strdel(&b);
	}
	ft_strdel(&b);
	if (e == -1)
		read_error(view);
	close(fd);
	return (rslt);
}

void	parse_space(char *filename, t_view *view)
{
	char	*str;
	char	*lights;
	char	*figures;
	char	*cam;
	char	**figures_a;
	char	**lights_a;

	str = read_space(filename, view);
	check_braces(str, view);
	figures = get_figures_str(str, view);
	lights = get_lights_str(str, view);
	cam = get_cam_str(str, view);
	ft_strdel(&str);
	figures_a  = get_strarr_members(figures, view);
	lights_a = get_strarr_members(lights, view);

	while (*figures_a!= NULL)
	{
		printf("%s\n", *figures_a);
		figures_a++;
	}

	while (*lights_a!= NULL)
	{
		printf("%s\n", *lights_a);
		lights_a++;
	}
	ft_strdel(&figures);
	ft_strdel(&lights);
	ft_strdel(&cam);
}
