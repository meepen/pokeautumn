cmake_minimum_required(VERSION 3.16)

project(pokeautumn VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS "src/*.cpp")

include(GenerateExportHeader)
add_library(libpokeautumn SHARED ${LIB_SOURCES})
generate_export_header(libpokeautumn EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/src/pokeautumn/export.h)
target_include_directories(libpokeautumn PUBLIC src)

add_executable(pokeautumn src/main.cxx)
target_link_libraries(pokeautumn libpokeautumn)