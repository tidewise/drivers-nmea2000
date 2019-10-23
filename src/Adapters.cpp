#include <nmea2000/Adapters.hpp>
#include <nmea2000/ActisenseDriver.hpp>
#include <canbus/Driver.hpp>
#include <iostream>

using namespace base;
using namespace nmea2000::adapters;

Interface::Interface() {
}

Interface::~Interface() {
}

void Interface::setReadTimeout(base::Time const& timeout) {
    m_read_timeout = timeout;
}

void Interface::queryAddressClaim() {
    writeMessage(Receiver::queryAddressClaim());
}

void Interface::queryProductInformation(int target) {
    writeMessage(Receiver::queryProductInformation(target));
}

CAN::CAN(std::string const& name, std::string const& type)
    : m_driver(canbus::openCanDevice(name, type))
    , m_library(pgns::getLibrary())
    , m_receiver(m_library) {
}

CAN::~CAN() {
    m_driver->close();
    delete m_driver;
}

void CAN::writeMessage(Message const& message) {
    if (message.size > 8) {
        throw Unsupported("writing to CAN does not suoport fast packet messages");
    }

    m_driver->write(message.toCAN());
}

nmea2000::Message CAN::readMessage() {
    auto deadline = Time::now() + m_read_timeout;
    Time remaining = m_read_timeout;
    while (true) {
        m_driver->setReadTimeout(remaining.toMilliseconds());

        canbus::Message msg = m_driver->read();
        auto state = m_receiver.process(Message::fromCAN(msg));
        if (state.first >= Receiver::COMPLETE) {
            return state.second;
        }

        remaining = deadline - Time::now();
        if (remaining < Time()) {
            throw iodrivers_base::TimeoutError(
                iodrivers_base::TimeoutError::PACKET,
                "timed out reading CAN"
            );
        }
    }
}

Actisense::Actisense(std::string const& uri)
    : m_driver(new ActisenseDriver()) {

    m_driver->openURI(uri);
    m_driver->sendStartupSequence();
}

Actisense::~Actisense() {
    m_driver->close();
    delete m_driver;
}

void Actisense::writeMessage(Message const& message) {
    m_driver->writeMessage(message);
}

nmea2000::Message Actisense::readMessage() {
    return m_driver->readMessage();
}