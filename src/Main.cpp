#include <iostream>
#include <nmea2000/PGNs.hpp>
#include <nmea2000/Adapters.hpp>
#include <iodrivers_base/Driver.hpp>

using namespace std;
using namespace nmea2000;

void usage(ostream& stream) {
    cerr << "usage: nmea2000_ctl TYPE CONNECTION_NAME CMD\n";
    cerr << "\n";
    cerr << "TYPE is either can or actisense\n";
    cerr << "with 'can', the connection name must be the socket-can interface name\n";
    cerr << "with 'actisense', the connection name must be the connection URI (e.g.\n";
    cerr << "   serial:///dev/ttyUSB0:115200)\n";
    cerr << "\n";
    cerr << "CMD is:";
    cerr << "  log    display the received NMEA messages";
    cerr << "  enumerate    display the devices present on the bus";
    cerr << flush;
}

int main(int argc, char** argv)
{
    if (argc < 4) {
        usage(cout);
        return 0;
    }

    string type = argv[1];
    string uri = argv[2];
    string cmd = argv[3];

    adapters::Interface* interface = nullptr;
    if (type == "can") {
        interface = new adapters::CAN(uri, "socket");
    }
    else if (type == "actisense") {
        interface = new adapters::Actisense(uri);
    }
    else {
        cerr << "unknown connection type '" << type << "'\n\n";
        usage(cerr);
        return 1;
    }

    if (cmd == "enumerate") {
        base::Time refresh_deadline = base::Time();

        while (true) {
            if (refresh_deadline < base::Time::now()) {
                interface->queryAddressClaim();
                refresh_deadline = base::Time::now() + base::Time::fromSeconds(10);
            }

            try {
                auto msg = interface->readMessage();
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
        cout << "# time PGN priority size\n";
        while (true) {
            try {
                auto msg = interface->readMessage();
                cout << msg.time << " " << msg.pgn << " "
                     << msg.priority << " " << msg.size << endl;
            }
            catch (iodrivers_base::TimeoutError&) {
            }
        }
    }

    return 0;
}
