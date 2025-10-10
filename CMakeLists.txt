cmake_minimum_required(VERSION 4.0)
project(project C)

set(CMAKE_C_STANDARD 99)

add_executable(project main.c
        matrix.c
        entities/cell.h
        entities/user.h
        settings/playability.h
        settings/labyrinth.h)
