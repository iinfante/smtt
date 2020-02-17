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

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <smtt/static_matrix_type_traits.hpp>
#include <string>
#include <vector>

using smtt::detail::has_data_field;
using smtt::detail::has_size_field;
using std::string;
using std::vector;

BOOST_AUTO_TEST_SUITE(test_smtt_suite)

BOOST_AUTO_TEST_SUITE(test_smtt_detail)

BOOST_AUTO_TEST_CASE(should_not_detect_data_field_for_primitive_types)
{
    BOOST_CHECK_EQUAL(false, has_data_field<void>::value);
    BOOST_CHECK_EQUAL(false, has_data_field<int>::value);
    BOOST_CHECK_EQUAL(false, has_data_field<int[]>::value);
}

BOOST_AUTO_TEST_CASE(should_not_detect_data_field_for_non_primitive_types)
{
    BOOST_CHECK_EQUAL(false, has_data_field<string>::value);
    BOOST_CHECK_EQUAL(false, has_data_field<vector<string>>::value);

    struct S
    {
        int data;
    };
    BOOST_CHECK_EQUAL(false, has_data_field<S>::value);
}

BOOST_AUTO_TEST_CASE(should_not_detect_size_field_for_primitive_types)
{
    BOOST_CHECK_EQUAL(false, has_size_field<void>::value);
    BOOST_CHECK_EQUAL(false, has_size_field<int>::value);
    BOOST_CHECK_EQUAL(false, has_size_field<int[]>::value);
}

BOOST_AUTO_TEST_CASE(should_not_detect_size_field_for_non_primitive_types)
{
    BOOST_CHECK_EQUAL(false, has_size_field<string>::value);
    BOOST_CHECK_EQUAL(false, has_size_field<vector<string>>::value);

    struct S
    {
        int size;
    };
    BOOST_CHECK_EQUAL(false, has_size_field<S>::value);
}

BOOST_AUTO_TEST_CASE(should_detect_data_field_for_structures_with_required_field)
{
    struct S
    {
        int data[1];
    };
    BOOST_CHECK_EQUAL(true, has_data_field<S>::value);

    struct T
    {
        string data[3];
    };
    BOOST_CHECK_EQUAL(true, has_data_field<T>::value);
}


BOOST_AUTO_TEST_CASE(should_detect_size_field_for_structures_with_required_field)
{
    struct S
    {
        int size[1];
    };
    BOOST_CHECK_EQUAL(true, has_size_field<S>::value);

    struct T
    {
        string size[3];
    };
    BOOST_CHECK_EQUAL(true, has_size_field<T>::value);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
