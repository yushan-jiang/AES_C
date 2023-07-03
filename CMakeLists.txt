cmake_minimum_required(VERSION 3.24)
project(AES_C C)

set(CMAKE_C_STANDARD 11)

add_executable(AES_C main.c aes.c aes.h utils.c utils.h)
