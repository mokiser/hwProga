cmake_minimum_required(VERSION 3.10)
project(LK1 VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(mainConfig.h.in mainConfig.h)
add_subdirectory(LK1_lib)

add_executable(LK1 LK1.cpp)

target_link_libraries(LK1 PUBLIC LK1)
target_include_directories(LK1 PUBLIC
                           "${PROJECT_BINARY_DIR}"
						   "${PROJECT_SOURCE_DIR}/bitwise_lib"
                           )