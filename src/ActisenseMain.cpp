#include <iostream>
#include <nmea2000/ActisenseDriver.hpp>

using namespace std;
using namespace nmea2000;

void usage(ostream& stream) {
    cerr << "usage: nmea2000_actisense_ctl URI CMD\n";
    cerr << "where CMD is:";
    cerr << "  log    display the received NMEA messages";
    cerr << flush;
}

int main(int argc, char** argv)
{
    if (argc != 3) {
        usage(cerr);
        return 1;
    }

    string uri = argv[1];
    string cmd = argv[2];

    if (cmd == "log") {
        ActisenseDriver driver;
        driver.setReadTimeout(base::Time::fromSeconds(1));
        driver.openURI(uri);
        driver.sendStartupSequence();

        cout << "# time PGN priority size\n";
        while (true) {
            try {
                auto msg = driver.readMessage();
                cout << msg.time << " " << msg.pgn << " "
                     << msg.priority << " " << msg.size << endl;
            }
            catch (iodrivers_base::TimeoutError&) {

            }
        }
    }

    return 0;
}
