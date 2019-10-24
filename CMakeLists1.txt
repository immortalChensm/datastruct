cmake_minimum_required(VERSION 3.13)
project(client)

set(CMAKE_CXX_STANDARD 14)
link_libraries(ws2_32)
add_executable(client client.c)

