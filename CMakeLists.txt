cmake_minimum_required(VERSION 3.19)

project(cpp-sfml VERSION 1.0)

set(CMAKE_BUILD_TYPE Debug)

include_directories(
    include
    lib/SFML/include
)

link_directories(lib/SFML/lib)

add_executable(
    ${PROJECT_NAME}
     src/main.cpp
     src/node.cpp
     src/rrt.cpp
     src/application.cpp
     src/vector.cpp
     src/circle.cpp
)
target_link_libraries(
    ${PROJECT_NAME} sfml-graphics sfml-window sfml-system
)
