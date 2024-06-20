include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.10)

link_libraries(son8::overglad glfw)
include_directories(include)
add_library(examples examples.cxx)
link_libraries(examples)
add_executable(overglad_example window/example.cxx)
