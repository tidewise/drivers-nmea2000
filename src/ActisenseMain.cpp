#include <iostream>
#include <nmea2000/ActisenseDriver.hpp>
#include <nmea2000/PGNs.hpp>

using namespace std;
using namespace nmea2000;

void usage(ostream& stream) {
    cerr << "usage: nmea2000_actisense_ctl URI CMD\n";
    cerr << "where CMD is:";
    cerr << "  log    display the received NMEA messages";
    cerr << "  enumerate    display the devices present on the bus";
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

    if (cmd == "enumerate") {
        ActisenseDriver driver;
        driver.setReadTimeout(base::Time::fromSeconds(1));
        driver.openURI(uri);
        driver.sendStartupSequence();

        base::Time refresh_deadline = base::Time();

        while (true) {
            if (refresh_deadline < base::Time::now()) {
                driver.queryDeviceEnumeration();
                refresh_deadline = base::Time::now() + base::Time::fromSeconds(10);
            }

            try {
                auto msg = driver.readMessage();
                if (msg.pgn == pgns::ISOAddressClaim::ID) {
                    auto info = pgns::ISOAddressClaim::fromMessage(msg);
                    std::cout
                        << "Bus ID: " << msg.source
                        << "Industry Group: " << info.industry_group
                        << "Device Class: " << info.device_class
                        << "Device Function: " << info.device_function
                        << "\n\n";
                }
                if (msg.pgn == pgns::ProductInformation::ID) {
                    auto info = pgns::ProductInformation::fromMessage(msg);
                    std::cout
                        << "Bus ID: " << msg.source
                        << "Product Code: " << info.product_code
                        << "Firmware Version: " << info.software_version_code
                        << "NMEA2000 Version: " << info.nmea_2000_version
                        << "Load Equivalency: " << info.load_equivalency
                        << "Model Version: " << info.model_version
                        << "Model ID: " << info.model_id
                        << "Model S/N: " << info.model_serial_code
                        << "\n\n";
                }
            }
            catch (iodrivers_base::TimeoutError&) {
            }
        }
    }
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
