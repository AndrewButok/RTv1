cmake_minimum_required(VERSION 3.9)
project(RTv1 C)

set(CMAKE_C_STANDARD 99)

set(LIBFT ${CMAKE_SOURCE_DIR}/libft/libft.a)

find_library(MLX mlx)
find_library(OPENGL OpenGL)
find_library(APPKIT AppKit)

set(SOURCE_FILES
        includes/rtv1.h srcs/main.c includes/rtv1.h includes/vector.h srcs/vector/vector.c includes/figure.h srcs/figure/sphere.c srcs/figure/gl.c includes/color.h includes/light.h srcs/vector/vector2.c srcs/light/light.c srcs/do_rt.c srcs/color/color.c)


add_executable(RTv1 ${SOURCE_FILES})
target_link_libraries(RTv1 ${LIBFT} ${OPENGL} ${APPKIT} ${MLX} ${OPENCL})
include_directories(includes libft/includes /usr/local/include)