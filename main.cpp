#include <iostream>
#include "core/bot_connect.hpp"

using namespace std;

BOOST_AUTO_TEST_SUITE(MainTests)

    Server _server("localhost", 10127);

    BOOST_AUTO_TEST_CASE(Constructor){
        BOOST_REQUIRE_EQUAL("localhost", _server.get_address());
        BOOST_REQUIRE_EQUAL(10127, _server.get_port());
    }


BOOST_AUTO_TEST_SUITE_END()

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
