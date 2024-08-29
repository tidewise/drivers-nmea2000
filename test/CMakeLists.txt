rock_executable(nmea2000_actisense_decode_raw ActisenseDecodeRaw.cpp DEPS nmea2000)

rock_gtest(test_suite suite.cpp
   test_Message.cpp test_Receiver.cpp test_PGNs.cpp test_ActisenseDriver.cpp
   test_CANWithReceiver.cpp
   DEPS nmea2000)
