cmake_minimum_required(VERSION 3.21)
project(COMP_LEX_2_NUM C)

set(CMAKE_C_STANDARD 11)

add_executable(COMP_LEX_2_NUM main.c State.h Token.h Token.c State.c utils.h utils.c)
