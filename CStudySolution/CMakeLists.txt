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
    "${CMAKE_SOURCE_DIR}/Project1/DataStructure/Graph/*.cpp"
    "${CMAKE_SOURCE_DIR}/Project1/LeetCode/*.cpp"
    "${CMAKE_SOURCE_DIR}/Project1/LeetCode/ArrayAndString/*.cpp"
    "${CMAKE_SOURCE_DIR}/Project1/LeetCode/LinkedList/*.cpp"
)

add_executable(Project1 ${PROJECT_SOURCES})
target_include_directories(Project1 PRIVATE ${CMAKE_SOURCE_DIR})
set_property(TARGET Project1 PROPERTY CXX_STANDARD 23)