include(${CMAKE_SOURCE_DIR}/cmake/CPM.cmake)
CPMAddPackage(
        NAME mini-gmp
        GIT_REPOSITORY https://github.com/chfast/mini-gmp.git
        GIT_TAG 95c194c8b1a475939d9fa29ff6b9a30b71dcbf48
)
include_directories(${mini-gmp_SOURCE_DIR}/mini-gmp)

add_library(encryption SHARED
        ellipticcurve.cpp ellipticcurve.h
        utility.cpp utility.h
        BigNum.cpp BigNum.h
        Curve.cpp Curve.h
        Point.cpp Point.h
        ECDH.cpp ECDH.h
        ${mini-gmp_SOURCE_DIR}/mini-gmp/mini-gmp.c
        ${mini-gmp_SOURCE_DIR}/mini-gmp/mini-gmp.h
)
target_link_libraries(encryption PUBLIC mini-gmp)
target_include_directories (encryption PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${mini-gmp_SOURCE_DIR}/mini-gmp)
