include(${CMAKE_SOURCE_DIR}/cmake/CPM.cmake)
add_executable(demo main.cpp)
target_link_libraries(demo encryption)
