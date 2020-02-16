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
