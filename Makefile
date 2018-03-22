# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abutok <abutok@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/22 16:24:00 by abutok            #+#    #+#              #
#    Updated: 2018/03/22 18:58:46 by abutok           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
#	C compiler and his default flags
GCC = gcc -Wall -Wextra -Werror
#	Libft linking
LINKLIBFT = -L ./libft -lft
#	Libs linking
LINKLIB = -framework OpenGL -framework AppKit -lmlx $(LINKLIBFT)
#	Sources directories
SRCDIR = ./src/
COLORDIR = ./src/color/
FIGUREDIR = ./src/figure/
LIGHTDIR = ./src/light/
VECTORDIR = ./src/vector/
#	Source files
SRCFILES = do_rt.c, main.c space.c
COLORFILES = color.c
FIGUREFILES = figure.c sphere.c
LIGHTFILES = light.c
VECTORFILES = vector.c vector2.c
