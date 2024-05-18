#include "mcp3201.h"

const byte csPin = 10;                      //  CS pin to select MCP3201

const float Vref = 5.045;                   //  Reference Voltage (Volt)
                                            //  provided to MCP3201

MCP3201 myMCP3201(csPin);                   //  MCP3201 Object

void setup() {
  Serial.begin(115200);                     //  for printing ADC readings
}

void loop() {
  
  float inputVolt = myMCP3201.readVin(Vref);  //  Read ADC and convert to Volt
  
  Serial.print(">Vin:");
  Serial.println(inputVolt, 4);
  
  delay(1000);  //  not necessary, but if you wish less frequent print out
}