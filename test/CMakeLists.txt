rock_executable(nmea2000_actisense_decode_raw ActisenseDecodeRaw.cpp DEPS nmea2000)

rock_gtest(test_suite
   suite.cpp
      test_ActisenseDriver.cpp
      test_CANWithReceiver.cpp
      test_Message.cpp
      test_PGNLibrary.cpp
      test_PGNs.cpp
      test_Receiver.cpp
   DEPS
      nmea2000
)
