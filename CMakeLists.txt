cmake_minimum_required(VERSION 3.5)

project(Encryption LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_EXPERIMENTAL_OPENGL_BACKEND ON)

include(cmake/CPM.cmake)
CPMAddPackage(
	NAME matplotplusplus
	GITHUB_REPOSITORY alandefreitas/matplotplusplus
	GIT_TAG origin/master
)


CPMAddPackage(
	NAME mini-gmp
	GIT_REPOSITORY https://github.com/chfast/mini-gmp.git
	GIT_TAG 95c194c8b1a475939d9fa29ff6b9a30b71dcbf48
)
include_directories(${mini-gmp_SOURCE_DIR}/mini-gmp)
include_directories(${glfw3_SOURCE_DIR}/include)
include_directories(${glad_BUILD_DIR}/include)

add_executable(encryption main.cpp
	ellipticcurve.cpp ellipticcurve.h
	utility.cpp utility.h
	BigNum.cpp BigNum.h
	ECCurve.cpp ECCurve.h
	ECPoint.cpp ECPoint.h
	${mini-gmp_SOURCE_DIR}/mini-gmp/mini-gmp.c)
target_link_libraries(encryption PUBLIC matplot mini-gmp matplot_opengl)
