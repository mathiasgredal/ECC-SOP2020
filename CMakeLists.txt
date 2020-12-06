cmake_minimum_required(VERSION 3.5)

project(Encryption LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include(cmake/CPM.cmake)

#set(BUILD_EXPERIMENTAL_OPENGL_BACKEND ON)
#CPMAddPackage(
#	NAME matplotplusplus
#	GITHUB_REPOSITORY alandefreitas/matplotplusplus
#	GIT_TAG origin/master
#)

#include_directories(${glfw3_SOURCE_DIR}/include)
#include_directories(${glad_BUILD_DIR}/include)

enable_testing()
add_subdirectory(src)
add_subdirectory(test)

add_executable(main src/main.cpp)
target_link_libraries(main encryption)

