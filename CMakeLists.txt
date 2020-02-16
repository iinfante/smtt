cmake_minimum_required(VERSION 3.13)

project(
    StaticMatrixTypeTraits
    DESCRIPTION
        "Type traits for static matrix implemented by structures"
    LANGUAGES
        CXX
)

find_package(
    Boost 1.67 EXACT
    REQUIRED COMPONENTS
        unit_test_framework
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wpedantic -Wall -Wextra -Wconversion -Werror)

add_library(
    smtt
    SHARED
        ${StaticMatrixTypeTraits_SOURCE_DIR}/include/smtt/static_matrix_type_traits.hpp
        ${StaticMatrixTypeTraits_SOURCE_DIR}/src/static_matrix_type_traits.cpp
)

target_include_directories(
    smtt
    PUBLIC
        ${StaticMatrixTypeTraits_SOURCE_DIR}/include
)

add_executable(
    testsmtt
        ${StaticMatrixTypeTraits_SOURCE_DIR}/test/testmain.cpp
        ${StaticMatrixTypeTraits_SOURCE_DIR}/test/testsmttdetail.cpp
        ${StaticMatrixTypeTraits_SOURCE_DIR}/test/testsmtt.cpp
)

target_link_libraries(
    testsmtt
    PRIVATE
        smtt
        Boost::unit_test_framework
)

enable_testing()

add_test(
    NAME
        testsmttdetail
    COMMAND
        testsmtt --run_test=testsmttsuite/testsmttdetail
)

add_test(
    NAME
        testsmtt
    COMMAND
        testsmtt --run_test=testsmttsuite/testsmtt --report_level=short
)
