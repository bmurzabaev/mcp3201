#include "mcp3201.h"

/*  Contructor
    csPin parameter to select/de-select MCP3201 for transfer*/
MCP3201::MCP3201(const byte csPin) {
  _csPin = csPin;                           //  copy pin num. for internal use
}

/*  Reads ADC's Digital Output Code (DOC)
    The method uses hardware SPI*/
uint16_t MCP3201::readAdc() {
  
  //  SPI settings for MCP3201 as per its datasheet
  SPISettings spiSettings(SPI_CLOCK_DIV16,  //  1 MHz (1us) clock
                          MSBFIRST,         //  MSB shifted first
                          SPI_MODE0);       //  SPI Mode 0,0

  SPI.begin();                              //  initialize the SPI bus
                                            //  sets SCK, POCI, CS to output
                                            //  pulls SCK, PICO low, CS high
  SPI.beginTransaction(spiSettings);        //  "lock" the SPI bus for
                                            //  own exclusive usage
  digitalWrite(_csPin, LOW);                //  pull CS low

  //  read 2 bytes ADC value
  byte readingH = SPI.transfer(0);
  byte readingL = SPI.transfer(0);

  digitalWrite(_csPin, HIGH);               //  de-assert CS

  SPI.endTransaction();                     //  "release" the SPI bus
                                            //  to avail it for others
  SPI.end();                                //  disable the SPI bus

  //  combine 2 bytes ADC value into uint16_t
  uint16_t reading = ((readingH & 0b00011111) << 7) +  //  data in LSB 5 bits
                     ((readingL & 0b11111110) >> 1);   //  data in MSB 7 bits

  return reading;
}


/*  Reads ADC's Digital Output Code (DOC) and
    converts to Analog Input Voltage (Vin)
    with respective to ADC's Reference Voltage (Vref)*/
float MCP3201::readVin(const float Vref) {
  
  uint16_t adc = MCP3201::readAdc();        //  get ADC reading
  
  float Vin = Vref * adc / 4096;            //  ADC to Vin conversion
  
  return Vin;                               //  return Vin
}