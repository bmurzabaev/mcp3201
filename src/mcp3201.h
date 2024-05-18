#ifndef MCP3201_h
#define MCP3201_h

#include <Arduino.h>

#include <SPI.h>

  class MCP3201 {
    public:
      MCP3201(const byte);          //  Constructor. CS pin numb. as parameter
      
      uint16_t readAdc();           //  returns ADC's (raw) Digital Output Code
      
      float readVin(const float);   //  returns Analog Input Voltage (Volt)
                                    //  calculated with respect to Vref (Volt)
                                    //  passed as parameter
    private:
      byte _csPin;
  };

#endif