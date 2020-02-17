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

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
