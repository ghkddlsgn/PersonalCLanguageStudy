cmake_minimum_required(VERSION 3.20)
project(Project1 C CXX)

include(CTest)
enable_testing()

# Collect all source files
file(GLOB_RECURSE PROJECT_SOURCES 
    "${CMAKE_SOURCE_DIR}/Project1/*.cpp"
    
)

add_executable(Project1 ${PROJECT_SOURCES})
target_include_directories(Project1 PRIVATE ${CMAKE_SOURCE_DIR})
set_property(TARGET Project1 PROPERTY CXX_STANDARD 23)