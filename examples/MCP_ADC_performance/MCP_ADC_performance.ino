//
//    FILE: MCP_ADC_performance.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: simple performance measurement.
//    DATE: 2020-08-14

// Note the deltaRead() does 1 or 2 differential reads depending
// on positive of negative delta between 2 pins.
// Therefor timing might differ substantially.


#include "MCP_ADC.h"

MCP3002 ADC2;
MCP3004 ADC4;
MCP3008 ADC8;
MCP3202 ADC22;
MCP3204 ADC24;
MCP3208 ADC28;

uint32_t start, stop;

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);

  ADC2.begin(10);
  ADC4.begin(9);
  ADC8.begin(8);

  Serial.println();

  Serial.println("ADC\tCHAN\tMAXVALUE");
  Serial.print("ADC2\t");
  Serial.print(ADC2.channels());
  Serial.print("\t");
  Serial.println(ADC2.maxValue());

  Serial.print("ADC4\t");
  Serial.print(ADC4.channels());
  Serial.print("\t");
  Serial.println(ADC4.maxValue());

  Serial.print("ADC8\t");
  Serial.print(ADC8.channels());
  Serial.print("\t");
  Serial.println(ADC8.maxValue());

  Serial.print("ADC22\t");
  Serial.print(ADC22.channels());
  Serial.print("\t");
  Serial.println(ADC22.maxValue());

  Serial.print("ADC24\t");
  Serial.print(ADC24.channels());
  Serial.print("\t");
  Serial.println(ADC24.maxValue());

  Serial.print("ADC28\t");
  Serial.print(ADC28.channels());
  Serial.print("\t");
  Serial.println(ADC28.maxValue());


  Serial.println("\nTiming in micros().\n");
  delay(10);

  test_1();
  test_2();
  test_3();

  Serial.println("***************************************\n");
  for (int s = 1; s <= 16; s++)
  {
    Serial.println(s * 1000000);
    ADC8.setSPIspeed(s);
    test_3();
  }

  Serial.println("done...");
}

void loop()
{
}

void test_1()
{
  uint32_t val = 0;

  start = micros();
  for (int channel = 0 ; channel < ADC2.channels(); channel++)
  {
    val += ADC2.analogRead(channel);
  }
  stop = micros();
  Serial.print("ADC2.analogRead()\t2x: \t");
  Serial.println(stop - start);
  delay(10);

  start = micros();
  for (int channel = 0 ; channel < ADC2.channels(); channel++)
  {
    val += ADC2.differentialRead(channel);
  }
  stop = micros();
  Serial.print("ADC2.differentialRead() 2x: \t");
  Serial.println(stop - start);
  delay(10);

  start = micros();
  for (int channel = 0 ; channel < ADC2.channels(); channel++)
  {
    val += ADC2.deltaRead(channel);
  }
  stop = micros();
  Serial.print("ADC2.deltaRead()\t2x: \t");
  Serial.println(stop - start);
  Serial.println();
  delay(10);
}

void test_2()
{
  uint32_t val = 0;

  start = micros();
  for (int channel = 0 ; channel < ADC4.channels(); channel++)
  {
    val += ADC4.analogRead(channel);
  }
  stop = micros();
  Serial.print("ADC4.analogRead()\t4x: \t");
  Serial.println(stop - start);
  delay(10);

  start = micros();
  for (int channel = 0 ; channel < ADC4.channels(); channel++)
  {
    val += ADC4.differentialRead(channel);
  }
  stop = micros();
  Serial.print("ADC4.differentialRead() 4x: \t");
  Serial.println(stop - start);
  delay(10);

  start = micros();
  for (int channel = 0 ; channel < ADC4.channels(); channel++)
  {
    val += ADC4.deltaRead(channel);
  }
  stop = micros();
  Serial.print("ADC4.deltaRead()\t4x: \t");
  Serial.println(stop - start);
  Serial.println();
  delay(10);
}

void test_3()
{
  uint32_t val = 0;

  start = micros();
  for (int channel = 0 ; channel < ADC8.channels(); channel++)
  {
    val += ADC8.analogRead(channel);
  }
  stop = micros();
  Serial.print("ADC8.analogRead()\t8x: \t");
  Serial.println(stop - start);
  delay(10);

  start = micros();
  for (int channel = 0 ; channel < ADC8.channels(); channel++)
  {
    val += ADC8.differentialRead(channel);
  }
  stop = micros();
  Serial.print("ADC8.differentialRead() 8x: \t");
  Serial.println(stop - start);
  delay(10);

  start = micros();
  for (int channel = 0 ; channel < ADC8.channels(); channel++)
  {
    val += ADC8.deltaRead(channel);
  }
  stop = micros();
  Serial.print("ADC8.deltaRead()\t8x: \t");
  Serial.println(stop - start);
  Serial.println();
  delay(10);
}


// -- END OF FILE --
