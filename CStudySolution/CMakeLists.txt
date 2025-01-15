
cmake_minimum_required(VERSION 3.20)
project(Project1 C CXX)

include(CTest)
enable_testing()

# Collect all source files
file(GLOB_RECURSE PROJECT_SOURCES 
    "${CMAKE_SOURCE_DIR}/Project1/*.cpp"
    "${CMAKE_SOURCE_DIR}/Project1/Bank/*.cpp"
    "${CMAKE_SOURCE_DIR}/Project1/CommonClass/*.cpp"
    "${CMAKE_SOURCE_DIR}/Project1/DataStructure/List/*.cpp"
    "${CMAKE_SOURCE_DIR}/Project1/DataStructure/Matrix/*.cpp"
    "${CMAKE_SOURCE_DIR}/Project1/DataStructure/Queue/*.cpp"
    "${CMAKE_SOURCE_DIR}/Project1/DataStructure/Tree/*.cpp"
)

add_executable(Project1 ${PROJECT_SOURCES})
set_property(TARGET Project1 PROPERTY CXX_STANDARD 23)