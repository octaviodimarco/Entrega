cmake_minimum_required(VERSION 3.12)
project(CLion)

set(CMAKE_CXX_STANDARD 14)

add_executable(MainV1 Proyecto/main.cpp Colisiones/Lista.h Colisiones/OpenHashMap.h)

add_executable(MainV2 Proyecto/mainv2.cpp)
