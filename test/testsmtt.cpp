#define BOOST_TEST_SYN_LINK

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(testsmttsuite)

BOOST_AUTO_TEST_SUITE(testsmtt)

BOOST_AUTO_TEST_CASE(shouldNotDetectMatrix)
{
    BOOST_CHECK_EQUAL(true, true);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
