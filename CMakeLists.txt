cmake_minimum_required(VERSION 3.8)

project(overglad VERSION 0.0.1)

add_library(${PROJECT_NAME} INTERFACE)

add_subdirectory(libs/glad)
target_link_libraries(${PROJECT_NAME} INTERFACE glad)
