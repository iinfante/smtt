#define BOOST_TEST_MODULE StaticMatrixTypeTraits
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_NO_MAIN

#include <boost/test/unit_test.hpp>

using boost::unit_test::unit_test_main;

auto main(int argc, char * argv[]) -> int
{
    return unit_test_main(&init_unit_test, argc, argv);
}
