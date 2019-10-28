#ifndef NMEA2000_ADAPTERS_HPP
#define NMEA2000_ADAPTERS_HPP

#include <nmea2000/Message.hpp>
#include <nmea2000/PGNLibrary.hpp>
#include <nmea2000/Receiver.hpp>
#include <canbus/Driver.hpp>

namespace canbus {
    class Driver;
}

namespace nmea2000 {
    class ActisenseDriver;

    /**
     * Ready-to-use classes for NMEA2000 access
     *
     * While the rest of the library are the "building blocks" to handle
     * NMEA2000, this namespace contains the basic classes that allow to
     * access the bus through the various means (CAN and/or Actisense)
     */
    namespace adapters {
        struct Unsupported : std::runtime_error {
            using std::runtime_error::runtime_error;
        };

        /** Base interface */
        class Interface {
        protected:
            base::Time m_read_timeout = base::Time::fromSeconds(5);

        public:
            Interface();
            virtual ~Interface();

            void setReadTimeout(base::Time const& timeout);

            virtual void writeMessage(Message const& msg) = 0;
            virtual Message readMessage() = 0;

            void queryProductInformation(int target);

            void queryAddressClaim();
        };

        /** CAN interface */
        class CAN : public Interface {
            canbus::Driver* m_driver = nullptr;
            PGNLibrary m_library;
            Receiver m_receiver;

        public:
            /** Open a CAN interface
             *
             * @param type the interface type. One of socket, hico, hico_pci,
             *      net_gateway, easy_sync. See
             *      drivers/canbus (https://github.com/rock-drivers/drivers-canbus)
             *      for more information
             */
            CAN(std::string const& name, std::string const& type = "socket");
            ~CAN();

            void writeMessage(Message const& msg);
            Message readMessage();
        };

        /** CAN interface */
        class Actisense : public Interface {
            ActisenseDriver* m_driver = nullptr;

        public:
            /** Open an Actisense interface
             *
             * @param uri the URI to the actisense, as understood by iodrivers_base,
             *    e.g. serial:///dev/ttyUSB0:115200
             */
            Actisense(std::string const& uri);

            ~Actisense();

            void writeMessage(Message const& msg);
            Message readMessage();
        };
    };
}

#endif