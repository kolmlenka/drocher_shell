cmake_minimum_required(VERSION 3.23)
project(testC C)

set(CMAKE_C_FLAGS "-lm -O2 -fsanitize=leak -fsanitize=undefined -fsanitize=address -Wall -Werror=vla -D_GNU_SOURCE")
set(CMAKE_C_STANDARD 17)

add_executable(testC main.c command_exec.c)