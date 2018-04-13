/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_global_getter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 22:14:00 by abutok            #+#    #+#             */
/*   Updated: 2018/04/10 22:14:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char	*ft_strtrimarr(const char *s)
{
	size_t	start;
	size_t	size;

	if (s == NULL)
		return (NULL);
	if (*s == '\0')
		return (ft_strnew(0));
	start = 0;
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t' ||
			s[start] == '{' || s[start] == ',')
			&& s[start] != '\0')
		start++;
	size = ft_strlen(s);
	if (start == size)
		return (ft_strnew(0));
	while (s[size] == ' ' || s[size] == '\n' || s[size] == '\t'
			|| s[size] == '\0')
		size--;
	return (ft_strsub(s, (unsigned int)start, (size - start + 1)));
}

char	**get_strarr_members(const char *str, t_view *view)
{
	char	**buf;
	char	**members;
	size_t	i;

	buf = ft_strsplit(str, '}');
	i = 0;
	while (*(buf + i) != NULL)
		i++;
	members = (char**)malloc(sizeof(char*) * (i + 1));
	i = 0;
	while (*(buf + i) != NULL)
	{
		*(members + i) = ft_strtrimarr(*(buf + i));
		ft_strdel(buf + i);
		i++;
	}
	*(members + i) = NULL;
	free(buf);
	return (members);
}

char	*get_cam_str(const char *str, t_view *view)
{
	char			*buf;
	unsigned int	start;
	size_t			size;
	int				c;

	buf = ft_strstr(str, "cam");
	if (buf == NULL)
		return (NULL);
	buf += 5;
	while (*buf == ' ' || *buf == '\n' || *buf == '\t'|| *buf == '\0')
		buf++;
	start = (unsigned int)(buf - str);
	size = 1;
	c = 1;
	if (*buf != '{')
		cam_class_error(view);
	while (c != 0)
	{
		c += buf[size] == '{' ? 1 : 0;
		c -= buf[size] == '}' ? 1 : 0;
		size++;
	}
	return (ft_strsub(str, start + 1, size - 2));
}


char	*get_figures_str(const char *str, t_view *view)
{
	char			*buf;
	unsigned int	start;
	size_t			size;
	int				c;

	buf = ft_strstr(str, "figures");
	if (buf == NULL)
		figures_arr_error(view);
	buf += 9;
	while (*buf == ' ' || *buf == '\n' || *buf == '\t'|| *buf == '\0')
		buf++;
	start = (unsigned int)(buf - str);
	size = 1;
	c = 1;
	if (*buf != '[')
		figures_arr_error(view);
	while (c != 0)
	{
		c += buf[size] == '[' ? 1 : 0;
		c -= buf[size] == ']' ? 1 : 0;
		size++;
	}
	return (ft_strsub(str, start + 1, size - 2));
}

char	*get_lights_str(const char *str, t_view *view)
{
	char			*buf;
	unsigned int	start;
	size_t			size;
	int				c;

	buf = ft_strstr(str, "lights");
	if (buf == NULL)
		lights_arr_error(view);
	buf += 8;
	while (*buf == ' ' || *buf == '\n' || *buf == '\t'|| *buf == '\0')
		buf++;
	start = (unsigned int)(buf - str);
	size = 1;
	c = 1;
	if (*buf != '[')
		lights_arr_error(view);
	while (c != 0)
	{
		c += buf[size] == '[' ? 1 : 0;
		c -= buf[size] == ']' ? 1 : 0;
		size++;
	}
	return (ft_strsub(str, start + 1, size - 2));
}
