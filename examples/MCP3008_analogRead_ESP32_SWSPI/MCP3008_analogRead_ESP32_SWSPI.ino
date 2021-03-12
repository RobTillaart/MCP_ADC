//
//    FILE: MCP3008_analogRead_ESP32_SWSPI.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: demo
//    DATE: 2021-03-12

#include "MCP_ADC.h"


// ESP32 PINS
// For HSPI
// CLK:  14
// MOSI: 13
// MISO: 12
//
// For VSPI (id = 2):
// CLK: 18,
// MOSI: 23,
// MISO: 19,


MCP3008 mcp1(23, 19, 21);      // ESP32 use SWSPI  dataIn, dataOut, Clock
// MCP3008 mcp1;               // use HWSPI  on ESP32 (apparently VSPI)
// MCP3008 mcp1(6, 7, 8);      // UNO   use SWSPI  dataIn, dataOut, Clock


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);

  mcp1.begin(5);

  Serial.println();
  Serial.println("ADC\tCHAN\tMAXVALUE");
  Serial.print("mcp1\t");
  Serial.print(mcp1.channels());
  Serial.print("\t");
  Serial.println(mcp1.maxValue());
}

void loop()
{
  Serial.print(millis());
  Serial.print("\tmcp1:\t");
  for (int channel = 0 ; channel < mcp1.channels(); channel++)
  {
    uint16_t val = mcp1.analogRead(channel);
    Serial.print(val);
    Serial.print("\t");
    delay(1);       // added so single reads are better visible on a scope
  }
  Serial.println();

  delay(1000);
}

// -- END OF FILE --
