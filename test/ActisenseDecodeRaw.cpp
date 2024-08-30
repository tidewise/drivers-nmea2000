#include <fstream>
#include <iostream>
#include <nmea2000/ActisenseDriver.hpp>

using namespace nmea2000;
using namespace std;

int main(int argc, char** argv)
{
    if (argc < 2) {
        cerr << "usage: " << argv[0] << " RAW STREAM\n";
        cerr <<
            "This tool parses a file containing traffic coming from a NMEA2000-USB adapter\n"
            "from actisense, and displays the byte offsets and reason of every rejected packet\n"
            "It is meant as a way to debug the driver, verifying whether the rejected data\n"
            "was really meant to be rejected\n";
        return 1;
    }
    string path = argv[1];
    ifstream file(path);

    file.seekg(0, ios::end);
    streamsize size = file.tellg();
    file.seekg(0, ios::beg);

    vector<uint8_t> buffer(size);
    if (!file.read(reinterpret_cast<char*>(buffer.data()), size)) {
        cerr << "Failed to read raw data in buffer" << endl;
        return 1;
    }

    size_t offset = 0;
    size_t current_skip_offset = 0;
    size_t current_skip_size = 0;
    size_t good_rx = 0;
    size_t bad_rx = 0;
    while (offset < buffer.size()) {
        uint8_t const* current_buffer = buffer.data() + offset;
        size_t remaining_size = buffer.size() - offset;

        int packet_size =
            ActisenseDriver::protocolExtractFramedPacket(current_buffer, remaining_size);
        if (packet_size < 0) {
            if (current_skip_size == 0) {
                current_skip_offset = offset;
            }
            current_skip_size += -packet_size;
            offset += -packet_size;
            bad_rx += -packet_size;
        }
        else if (packet_size == 0) {
            cerr << "got packet_size == 0, end of file ? (offset=" << offset
                      << ", size=" << buffer.size() << ")" << endl;
            break;
        }
        else {
            if (current_skip_size) {
                cout << "offset=" << current_skip_offset
                          << " size=" << current_skip_size << ": bad framing"
                          << endl;
                current_skip_size = 0;
            }

            int validated_size =
                ActisenseDriver::protocolValidateFramedPacket(current_buffer,
                    packet_size);

            if (validated_size > 0) {
                cout << "offset=" << offset << " size=" << packet_size
                          << ": good rx of size " << validated_size << endl;
                offset += validated_size;
                good_rx += validated_size;
            }
            else {
                cout << "offset=" << offset << " size=" << packet_size
                          << ": invalid packet in valid framing (" << validated_size
                          << ")" << endl;
                offset += packet_size;
                bad_rx += packet_size;
            }
        }
    }

    std::cerr << "Total: good=" << good_rx << " bad=" << bad_rx << std::endl;
}
