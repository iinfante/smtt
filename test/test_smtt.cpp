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

using smtt::is_static_matrix;
using std::string;
using std::vector;

BOOST_AUTO_TEST_SUITE(test_smtt_suite)

BOOST_AUTO_TEST_SUITE(test_smtt)

BOOST_AUTO_TEST_CASE(should_not_detect_matrix_for_primitive_types)
{
    BOOST_CHECK_EQUAL(false, is_static_matrix<void>::value);
    BOOST_CHECK_EQUAL(false, is_static_matrix<int>::value);
    BOOST_CHECK_EQUAL(false, is_static_matrix<int[]>::value);
    BOOST_CHECK_EQUAL(false, is_static_matrix<int[][1]>::value);
}

BOOST_AUTO_TEST_CASE(should_not_detect_matrix_for_non_primitive_types)
{
    BOOST_CHECK_EQUAL(false, is_static_matrix<string>::value);
    BOOST_CHECK_EQUAL(false, is_static_matrix<vector<string>>::value);
    BOOST_CHECK_EQUAL(false, is_static_matrix<vector<vector<int>>>::value);

    struct S
    {
        int data;
        int size;
    };
    BOOST_CHECK_EQUAL(false, is_static_matrix<S>::value);
}

BOOST_AUTO_TEST_CASE(should_not_detect_matrix_for_structures_missing_required_fields)
{
    struct T
    {
        int data[1];
        int size;
    };
    BOOST_CHECK_EQUAL(false, is_static_matrix<T>::value);

    struct U
    {
        int data;
        int size[1];
    };
    BOOST_CHECK_EQUAL(false, is_static_matrix<U>::value);
}

BOOST_AUTO_TEST_CASE(should_detect_matrix_for_structures_with_required_fields)
{
    struct T
    {
        int data[6];
        int size[2];
    };
    BOOST_CHECK_EQUAL(true, is_static_matrix<T>::value);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
