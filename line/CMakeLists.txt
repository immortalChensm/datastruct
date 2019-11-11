cmake_minimum_required(VERSION 2.8)
PROJECT(line)
SET(FILE search_half.c)
MESSAGE(STATUS "bitree test"${line_SOURCE_DIR})

FILE(GLOB FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.c")
MESSAGE(STATUS "GLOB FILES IS :"${FILES})
add_executable(line ${FILE})