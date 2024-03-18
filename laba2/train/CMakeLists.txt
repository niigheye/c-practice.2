cmake_minimum_required(VERSION 3.26)

set(project "train")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        train.cpp
)

set(HEADERS
        train.h
)

add_library(${project} STATIC ${SOURCES} ${HEADERS})