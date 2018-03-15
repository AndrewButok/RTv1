cmake_minimum_required(VERSION 3.9)
project(RTv1 C)

set(CMAKE_C_STANDARD 99)

set(LIBFT ${CMAKE_SOURCE_DIR}/libft/libft.a)

find_library(MLX mlx)
find_library(OPENGL OpenGL)
find_library(APPKIT AppKit)

set(SOURCE_FILES
        includes/RTv1.h srcs/main.c)


add_executable(RTv1 ${SOURCE_FILES})
target_link_libraries(RTv1 ${LIBFT} ${OPENGL} ${APPKIT} ${MLX} ${OPENCL})
include_directories(includes libft/includes /usr/local/include)