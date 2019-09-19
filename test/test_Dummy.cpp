#include <boost/test/unit_test.hpp>
#include <nmea2000/Dummy.hpp>

using namespace nmea2000;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    nmea2000::DummyClass dummy;
    dummy.welcome();
}
