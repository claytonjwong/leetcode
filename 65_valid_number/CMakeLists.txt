cmake_minimum_required(VERSION 3.16)
project(65_valid_number)

set(CMAKE_CXX_STANDARD 17)

include_directories("${PROJECT_SOURCE_DIR}/boost")
add_executable(65_valid_number main.cpp)

