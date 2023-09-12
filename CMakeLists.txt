cmake_minimum_required(VERSION 3.16)

project(pokeautumn VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

include_directories(src)
add_executable(pokeautumn src/main.cxx ${SOURCES})