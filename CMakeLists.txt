cmake_minimum_required(VERSION 3.9)
project(RTv1 C)

set(CMAKE_C_STANDARD 99)

set(LIBFT ${CMAKE_SOURCE_DIR}/libft/libft.a)

find_library(MLX mlx)
find_library(OPENGL OpenGL)
find_library(APPKIT AppKit)

AUX_SOURCE_DIRECTORY(libft LIBFT_SRC)
set(SOURCE_FILES
        includes/rtv1.h
        src/main.c
        includes/rtv1.h
        src/vector/vector.c
        src/figure/sphere.c
        src/figure/figure.c
        src/vector/vector2.c
        src/light/light.c
        src/do_rt.c
        src/color/color.c
        src/space.c
        src/vector/rotate.c)

add_library(ft ${LIBFT_SRC})
add_executable(RTv1 ${SOURCE_FILES})
target_link_libraries(RTv1 ft ${OPENGL} ${APPKIT} ${MLX} ${OPENCL})
include_directories(includes libft/includes /usr/local/include)