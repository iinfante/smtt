/*
 * Copyright 2020 Ismael Infante
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#define BOOST_TEST_SYN_LINK

#include <boost/test/unit_test.hpp>
#include <smtt/static_matrix_type_traits.hpp>
#include <string>
#include <vector>

using smtt::is_static_matrix_ndim;
using std::string;
using std::vector;

BOOST_AUTO_TEST_SUITE(test_smtt_suite)

BOOST_AUTO_TEST_SUITE(test_smtt_dimension)

BOOST_AUTO_TEST_CASE(should_not_detect_dimension_for_non_static_matrix)
{
    BOOST_CHECK_EQUAL(false, (is_static_matrix_ndim<int, 1>::value));
    BOOST_CHECK_EQUAL(false, (is_static_matrix_ndim<int[], 1>::value));
    BOOST_CHECK_EQUAL(false, (is_static_matrix_ndim<int[][1], 2>::value));
    BOOST_CHECK_EQUAL(false, (is_static_matrix_ndim<string, 1>::value));
    BOOST_CHECK_EQUAL(false, (is_static_matrix_ndim<vector<string>, 1>::value));

    struct S
    {
        int data[1];
        int size;
    };
    BOOST_CHECK_EQUAL(false, (is_static_matrix_ndim<S, 1>::value));

    struct T
    {
        int data;
        int size[1];
    };
    BOOST_CHECK_EQUAL(false, (is_static_matrix_ndim<T, 1>::value));
}

BOOST_AUTO_TEST_CASE(should_detect_only_static_matrix_with_size_1_as_one_dimension)
{
    struct S
    {
        int data[10];
        int size[1];
    };
    BOOST_CHECK_EQUAL(true, (is_static_matrix_ndim<S, 1>::value));

    struct T
    {
        int data[10];
        int size[2];
    };
    BOOST_CHECK_EQUAL(false, (is_static_matrix_ndim<T, 1>::value));

    struct U
    {
        int data[10];
        int size[3];
    };
    BOOST_CHECK_EQUAL(false, (is_static_matrix_ndim<U, 1>::value));
}

BOOST_AUTO_TEST_CASE(should_detect_only_static_matrix_with_size_2_as_two_dimensions)
{
    struct S
    {
        int data[10];
        int size[1];
    };
    BOOST_CHECK_EQUAL(false, (is_static_matrix_ndim<S, 2>::value));

    struct T
    {
        int data[10];
        int size[2];
    };
    BOOST_CHECK_EQUAL(true, (is_static_matrix_ndim<T, 2>::value));

    struct U
    {
        int data[10];
        int size[3];
    };
    BOOST_CHECK_EQUAL(false, (is_static_matrix_ndim<U, 2>::value));
}

BOOST_AUTO_TEST_CASE(should_detect_only_static_matrix_with_size_3_as_three_dimensions)
{
    struct S
    {
        int data[10];
        int size[1];
    };
    BOOST_CHECK_EQUAL(false, (is_static_matrix_ndim<S, 3>::value));

    struct T
    {
        int data[10];
        int size[2];
    };
    BOOST_CHECK_EQUAL(false, (is_static_matrix_ndim<T, 3>::value));

    struct U
    {
        int data[10];
        int size[3];
    };
    BOOST_CHECK_EQUAL(true, (is_static_matrix_ndim<U, 3>::value));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
