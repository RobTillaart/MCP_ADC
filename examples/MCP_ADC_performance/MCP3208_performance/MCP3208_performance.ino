//
//    FILE: MCP3208_performance.ino
//  AUTHOR: Rob Tillaart, Alex Uta
// PURPOSE: simple performance measurement for MCP3208
//    DATE: 2023-08-13
//


#include "MCP_ADC.h"

MCP3208 mcp28;
#define MCP3208_CS_PIN 25

uint32_t start, stop, 
         analog_read_time,
         analog_read_multiple_time;

const uint8_t num_channels = 8;
uint8_t channels_list[num_channels] = {
    0,1,2,3,4,5,6,7
};


void setup()
{
  Serial.begin(115200);


  Serial.println();
  Serial.println("ADC\tCHAN\tMAXVALUE");
  Serial.print("mcp28\t");
  Serial.print(mcp28.channels());
  Serial.print("\t");
  Serial.println(mcp28.maxValue());

  Serial.println("\nTiming in micros().\n");
  delay(10);

  Serial.println("***************************************\n");
  for (int s = 1; s <= 16;s++)
  {
    Serial.println(s * 1000000UL);
    mcp28.setSPIspeed(s * 1000000UL);
    mcp28.begin(MCP3208_CS_PIN);
    test();
  }

  Serial.println("done...");
}


void loop()
{
}


void test()
{
  uint32_t val = 0;

  start = micros();
  for (int channel = 0; channel < mcp28.channels(); channel++)
  {
    val += mcp28.analogRead(channel);
  }
  stop = micros();
  analog_read_time = stop - start;
  
  Serial.print("mcp28.analogRead()\t8x: \t");
  Serial.println(analog_read_time);
  delay(10);


  start = micros();
  int16_t readings[num_channels];
  
  mcp28.analogReadMultiple(channels_list, num_channels, readings);
  stop = micros();
  analog_read_multiple_time = stop - start;

  Serial.print("mcp28.analogReadMultiple()\t8x: \t");
  Serial.println(stop - start);

  Serial.print("analogRead() time / analogReadMultiple() time \t");
  Serial.println(analog_read_time / analog_read_multiple_time);
  delay(10);


  start = micros();
  for (int channel = 0; channel < mcp28.channels(); channel++)
  {
    val += mcp28.differentialRead(channel);
  }
  stop = micros();
  Serial.print("mcp28.differentialRead() 8x: \t");
  Serial.println(stop - start);
  delay(10);

  start = micros();
  for (int channel = 0; channel < mcp28.channels(); channel++)
  {
    val += mcp28.deltaRead(channel);
  }
  stop = micros();
  Serial.print("mcp28.deltaRead()\t8x: \t");
  Serial.println(stop - start);
  Serial.println();
  delay(10);

}


// -- END OF FILE --
