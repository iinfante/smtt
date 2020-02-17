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
    smtt_demo
        ${StaticMatrixTypeTraits_SOURCE_DIR}/src/smtt_demo.cpp
)

target_link_libraries(
    smtt_demo
    PRIVATE
        smtt
)

add_executable(
    test_smtt
        ${StaticMatrixTypeTraits_SOURCE_DIR}/test/test_main.cpp
        ${StaticMatrixTypeTraits_SOURCE_DIR}/test/test_smtt_detail.cpp
        ${StaticMatrixTypeTraits_SOURCE_DIR}/test/test_smtt.cpp
        ${StaticMatrixTypeTraits_SOURCE_DIR}/test/test_smtt_dimension.cpp
)

target_link_libraries(
    test_smtt
    PRIVATE
        smtt
        Boost::unit_test_framework
)

enable_testing()

add_test(
    NAME
        test_smtt_detail
    COMMAND
        test_smtt --run_test=test_smtt_suite/test_smtt_detail --report_level=short
)

add_test(
    NAME
        test_smtt
    COMMAND
        test_smtt --run_test=test_smtt_suite/test_smtt --report_level=short
)

add_test(
    NAME
        test_smtt_dimension
    COMMAND
        test_smtt --run_test=test_smtt_suite/test_smtt_dimension --report_level=short
)
