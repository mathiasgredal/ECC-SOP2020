include(${CMAKE_SOURCE_DIR}/cmake/CPM.cmake)
set(BUILD_EXPERIMENTAL_OPENGL_BACKEND ON)
CPMAddPackage(
        NAME matplotplusplus
        GITHUB_REPOSITORY alandefreitas/matplotplusplus
        GIT_TAG origin/master
)
include_directories(${glfw3_SOURCE_DIR}/include)
include_directories(${glad_BUILD_DIR}/include)

add_executable(demo main.cpp)
target_link_libraries(demo encryption matplot matplot_opengl)
