#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <smtt/static_matrix_type_traits.hpp>
#include <vector>
#include <string>


using std::vector;
using std::string;

BOOST_AUTO_TEST_SUITE(testsmttsuite)

BOOST_AUTO_TEST_CASE(shouldNotDetectedDataField)
{
    BOOST_CHECK_EQUAL(false, smtt::has_data_field<void>::value);
    BOOST_CHECK_EQUAL(false, smtt::has_data_field<int>::value);
    BOOST_CHECK_EQUAL(false, smtt::has_data_field<int[]>::value);

    BOOST_CHECK_EQUAL(false, smtt::has_data_field<string>::value);
    BOOST_CHECK_EQUAL(false, smtt::has_data_field<vector<string>>::value);

    struct S
    {
        int data;
    };
    BOOST_CHECK_EQUAL(false, smtt::has_data_field<S>::value);

}

BOOST_AUTO_TEST_SUITE_END()
