## Include Catch2 testing framework
cmake_policy(SET CMP0110 OLD)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(TEST_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(TEST_SOURCE_DIR ${ROOT_DIR} )

set(CATCH_INCLUDE_DIR "${TEST_ROOT_DIR}/extern")

find_path(CATCH_INCLUDE_DIR "catch.hpp")
include_directories(${INCLUDE_DIRECTORIES} ${CATCH_INCLUDE_DIR} ${TEST_SOURCE_DIR})

## Build tests
include(CTest)
include(ParseAndAddCatchTests)

add_executable(tests main.cpp bignum_test.cpp curve_test.cpp)
target_link_libraries(tests encryption)
ParseAndAddCatchTests(tests)





