cmake_minimum_required(VERSION 3.17)
project(learning C)

set(CMAKE_C_STANDARD 99)

add_executable(learning EX_10_17/main.c EX_10_17/User/Src/seqlist.c EX_10_17/User/Inc/seqlist.h EX_10_17/User/Inc/node.h EX_10_17/User/Src/node.c EX_10_17/User/Inc/array.h EX_10_17/User/Src/array.c EX_10_17/User/Inc/tree.h EX_10_17/User/Src/tree.c)