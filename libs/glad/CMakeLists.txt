cmake_minimum_required(VERSION 3.8)

project(glad)

add_library(${PROJECT_NAME})
add_subdirectory(source)

target_include_directories(${PROJECT_NAME} PUBLIC include)
