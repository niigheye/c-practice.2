cmake_minimum_required(VERSION 3.26)
set(project "laba2")
project(${project})
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(train)
add_subdirectory(planet)


set(SOURCES
        main.cpp
        planet/planet.cpp
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/planetdata.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/traindata.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(${project} ${SOURCES})

target_link_libraries(${project} planet)
target_link_libraries(${project} train)

