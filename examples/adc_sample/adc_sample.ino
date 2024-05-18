#include "mcp3201.h"

const byte csPin = 10;                      //  CS pin to select MCP3201

MCP3201 myMCP3201(csPin);                   //  MCP3201 Object

void setup() {
  Serial.begin(115200);                     //  for printing ADC readings
}

void loop() {
  
  int ADCvalue = myMCP3201.readAdc();       //  read 12bit ADC
                                            //  Digital Output Code
  
  Serial.print(">ADC:");
  Serial.println(ADCvalue);   
    
  delay(1000);  //  not necessary, but if you wish less frequent print out
}