
use esp32 as the mcu for 3D printer motherboard.

it has  larger memory and more powerful than normal 32bit 3D printer motherboard.

the file upload speed to sd card is also higher than it as a wifi module, it can support more motor drivers with one fast expand GPIO chip.

![](https://gitee.com/markyue/pandapi_wiki/raw/master/imges/esp/15090314.jpg)

Items | Specifications  
--- | --- 
MCU | Two 32-bit MCU ,240MHz
RAM |  520 KBytes SRAM |	
ROM |  4M Bytes Flash memory
EXGPIO | there are 24 more GPIOs(only as output) with a expander, the expanded GPIO speed is 70kHz
WiFi |  802.11 b/g/n/d/e/i/k/r (802.11n up to 150 Mbps)
Bluetooth | Bluetooth v4.2
Motors | support 8 Motor drivers
heaters | 3 heaters
temperature | support 3 thermistors (30degree~250degree)
Bed leveling    | 	  BLtouch/ support wild range voltage 5V~36V Inductive sensor NPN, since it have optocoupler.
LCD   | 	LCD128*64/PandaTouchScreen/DGUS touch screen
RJ11  |  for DGUS touch screen 
FAN | Support mixed use of 5V/24V fans,3 of them are controllabe fans
Audio |  play music at boot, Error/alarm music..
OS | Real-time operating systems (RTOS)
App | control printer, upload files with web browser ,[see more](https://github.com/luc-github/ESP3D-WEBUI)

[More details](https://hackaday.io/project/180298-esp32-has-not-enough-gpio)
