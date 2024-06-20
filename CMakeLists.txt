cmake_minimum_required(VERSION 3.8)

project(overglad VERSION 0.0.1)
set(SON8PROJECT son8${PROJECT_NAME})

add_library(${SON8PROJECT} INTERFACE)
add_subdirectory(source)

add_subdirectory(libs/glad)
target_link_libraries(${SON8PROJECT} INTERFACE glad)
target_include_directories(${SON8PROJECT} INTERFACE include)
