

# Performance test  

Test sketch  MCP3208_performance.ino

Max clock frequency tested 16 MHz, ESP32 WROVER Module

### Library version: 0.1.9

|  Action                       | HW 1 MHz | HW 2 MHz | HW 4 MHz | HW 8 MHz | HW 10 MHz | HW 12 MHz | HW 14 MHz | HW 16 MHz | notes     |
|:------------------------------|---------:|---------:|---------:|---------:|:---------:|:---------:|:---------:|:---------:|
| mcp28.analogRead()            |   389.0  |  242.0   |  186.0   |  157.0   |  152.00   |  208.00   |  206.00   |  145.00   |
| mcp28.analogReadMultiple()    |   282.0  |  155.0   |  99.00   |  70.00   |  65.000   |  61.000   |  59.000   |  56.000   |
|                               |          |          |          |          |           |           |           |           |
| mcp28.differentialRead()      |   356.0  |  238.0   |  183.0   |  154.0   |  148.00   |  145.00   |  143.00   |  139.00   |
| mcp28.deltaRead()             |   709.0  |  476.0   |  364.0   |  307.0   |  296.00   |  289.00   |  285.00   |  278.00   |

### Notes

For this test I used the ESP32 WROVER Module (ESP32-WROVER-IE-N16R8) with MCP3208-CI/SL (IC ADC 12BIT SAR 16SOIC)

A good compromise was the 12 MHz.
By running multiple tests I was able to see a difference in the reading value of 13-16 and it was easily fixed from the software side.
