cmake_minimum_required(VERSION 3.26)
project(Po_C_mon C)

set(CMAKE_C_STANDARD 17)

add_executable(Po_C_mon main.c
        map.c
        map.h
        pokemon.c
        pokemon.h
        perlin.c
        perlin.h)
