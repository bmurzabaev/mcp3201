# MCP3201
Arduino library for MCP3201 IC (ADC chip) that does Analog-to-Digital conversion. The library uses hardware SPI.

## Description
This library retreves the result of ADC conversion made by the MCP3201. The `MCP3201` Class has a `MCP3201` constructor and two methods `uint16 readAdc()` and `float readVin(float)`. The constructor requires the CS pin to be passed as an argument. The method `readAdc()` returns 12 bits of analog-to-digital conversion result, whereas `readVin()` internally invokes `readAdc()`, then converts 12 bits ADC into corresponding voltage with respect to the reference votage that the MCP3201 is referenced by. The reference voltage has to be passed as an argument for this function to work properly. 
## SPI implementation
The MCP3201 IC requires the SPI interface. The SPI implementation in the library is as follows. Whenever any of above two methods is invoked, the SPI communication is established based on the specifications of the MCP3201. The SPI bus is "locked". When the ADC conversion is done and its result is received, the SPI communication is closed, the SPI bus is released, so the microcontroller can use its hardware SPI bus to communicate with other SPI devices. 
## Examples
The two examples are provided in the examples folder demonstrating how above two methods could be used. 
## Testing
The library has been tested with Arduino Uno. The MCP3201 IC was:
| DigiKey Part Number | MCP3201-CI/P-ND |
| ------------------- | ----------------|
| Manufacturer | Microchip Technology |
| Manufacturer Product Number | MCP3201-CI/P |
| Description | 12 Bit Analog to Digital Converter 1 Input 1 SAR 8-PDIP |
