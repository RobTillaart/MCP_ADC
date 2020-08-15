//
//    FILE: MCP3008_analogRead.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: demo
//    DATE: 2020-08-13

#include "MCP_ADC.h"

MCP3008 ADC1;       // use HWSPI
MCP3004 ADC2(6, 7); // use SWSPI

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);

  ADC1.begin(10);
  ADC2.begin(5);

  Serial.println();
  Serial.println("ADC\tCHAN\tMAXVALUE");
  Serial.print("ADC1\t");
  Serial.print(ADC1.channels());
  Serial.print("\t");
  Serial.println(ADC1.maxValue());
  Serial.print("ADC2\t");
  Serial.print(ADC2.channels());
  Serial.print("\t");
  Serial.println(ADC2.maxValue());
}

void loop()
{
  Serial.print("ADC1:\t");
  for (int channel = 0 ; channel < ADC1.channels(); channel++)
  {
    uint16_t val = ADC1.analogRead(channel);
    Serial.print(val);
    Serial.print("\t");
  }
  Serial.println();
  Serial.print("ADC2:\t");
  for (int channel = 0 ; channel < ADC2.channels(); channel++)
  {
    uint16_t val = ADC2.analogRead(channel);
    Serial.print(val);
    Serial.print("\t");
  }
  Serial.println();

  delay(1000);
}

// -- END OF FILE --
