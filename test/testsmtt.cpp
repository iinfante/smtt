#define BOOST_TEST_SYN_LINK

#include <boost/test/unit_test.hpp>
#include <smtt/static_matrix_type_traits.hpp>
#include <string>
#include <vector>

using smtt::is_static_matrix;
using std::string;
using std::vector;

BOOST_AUTO_TEST_SUITE(testsmttsuite)

BOOST_AUTO_TEST_SUITE(testsmtt)

BOOST_AUTO_TEST_CASE(shouldNotDetectMatrixForPrimitiveTypes)
{
    BOOST_CHECK_EQUAL(false, is_static_matrix<void>::value);
    BOOST_CHECK_EQUAL(false, is_static_matrix<int>::value);
    BOOST_CHECK_EQUAL(false, is_static_matrix<int[]>::value);
    BOOST_CHECK_EQUAL(false, is_static_matrix<int[][1]>::value);
}

BOOST_AUTO_TEST_CASE(shouldNotDetectMatrixForNonPrimitiveTypes)
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

BOOST_AUTO_TEST_CASE(shouldNotDetectMatrixForStructuresMissingRequiredFields)
{
    struct T
    {
        int data[1];
    };
    BOOST_CHECK_EQUAL(false, is_static_matrix<T>::value);

    struct U
    {
        int size[1];
    };
    BOOST_CHECK_EQUAL(false, is_static_matrix<U>::value);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
