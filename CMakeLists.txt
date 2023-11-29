cmake_minimum_required(VERSION 3.21)
project(AI_Project C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(AI_Project
        data_types.h
        GRAPH_SEARCH.c
        GRAPH_SEARCH.h
        HashTable.c
        HashTable.h
        SpecificToProblem.c
        Standart_Search.c)
