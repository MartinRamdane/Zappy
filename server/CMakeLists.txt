cmake_minimum_required(VERSION 3.5)
project(zappy_server C)

file(GLOB SOURCES src/*.c)
file(GLOB HEADERS include/*.h)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(zappy_server ${SOURCES} ${HEADERS})
