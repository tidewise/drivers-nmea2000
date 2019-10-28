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
    cerr << "CMD is:\n";
    cerr << "  log    display the received NMEA messages\n";
    cerr << "  enumerate    display the devices present on the bus\n";
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

        bool address_claim = true;
        vector<int> pending_product_info;
        while (true) {
            if (refresh_deadline < base::Time::now()) {
                if (address_claim || pending_product_info.empty()) {
                    interface->queryAddressClaim();

                    // We haven't managed to resolve all product info in a cycle.
                    // Probably one device did not answer. Try again.
                    pending_product_info.clear();
                    address_claim = false;
                }
                else {
                    interface->queryProductInformation(pending_product_info.back());
                    pending_product_info.pop_back();
                }
                address_claim = !address_claim;
                refresh_deadline = base::Time::now() + base::Time::fromSeconds(10);
            }

            try {
                auto msg = interface->readMessage();
                if (msg.pgn == pgns::ISOAddressClaim::ID) {
                    auto info = pgns::ISOAddressClaim::fromMessage(msg);
                    pending_product_info.push_back(msg.source);
                    std::cout
                        << "Bus ID: " << static_cast<int>(msg.source) << "\n"
                        << "Industry Group: "
                            << static_cast<int>(info.industry_group) << "\n"
                        << "Device Class: "
                            << static_cast<int>(info.device_class) << "\n"
                        << "Device Function: "
                            << static_cast<int>(info.device_function) << "\n"
                        << "\n\n";
                }
                if (msg.pgn == pgns::ProductInformation::ID) {
                    auto info = pgns::ProductInformation::fromMessage(msg);
                    std::cout
                        << "Bus ID: " << static_cast<int>(msg.source)
                        << "Product Code: "
                            << static_cast<int>(info.product_code) << "\n"
                        << "Firmware Version: " << info.software_version_code << "\n"
                        << "NMEA2000 Version: "
                            << static_cast<int>(info.nmea_2000_version) << "\n"
                        << "Load Equivalency: "
                            << static_cast<int>(info.load_equivalency) << "\n"
                        << "Model Version: " << info.model_version << "\n"
                        << "Model ID: " << info.model_id << "\n"
                        << "Model S/N: " << info.model_serial_code << "\n"
                        << "\n\n";

                    if (!pending_product_info.empty()) {
                        interface->queryProductInformation(pending_product_info.back());
                        pending_product_info.pop_back();
                    }
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
