
Use esp32 as the mcu for 3D printer motherboard. 

it has  larger memory and more powerful than normal 32bit 3D printer motherboard.

the file upload speed to sd card is also higher than it as a wifi module, it can support more motor drivers with one fast expand GPIO chip.

![](https://gitee.com/markyue/pandapi_wiki/raw/master/imges/esp/15090314.jpg)

Items | Specifications  
--- | --- 
MCU | Two 32-bit MCU ,240MHz
RAM |  520 KBytes SRAM |	
ROM |  4M Bytes Flash memory
EXGPIO | there are 24 more GPIOs(only as output) with a expander, the communication speed is 1.4MHz, and the actual speed of gpio output is 70kHz that can drive the X/Y axis to speed 900mm/s.
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

[Wiki Guides](https://github.com/markniu/PandaZHU/wiki)

### Flashing firmware
To flash firmware by directly connecting to your computer with usb line,you will need to insert the sd card to the sdcard slot on the board.before that you should install and compile firmware,[see more](https://github.com/markniu/PandaZHU/wiki/Compile&Flash-firmware)

### PinMap
Name |  GPIO  ||Name |  GPIO 
--- | --- |---| --- | ---  
X_Endstop | 4 | | Y_Endstop | 35
Z_Endstop | 21 | | SERVO(BLTOUCH PWM) |  0
X_Step | 101 | | X_Dir | 100
Y_Step | 103 | | Y_Dir | 102
Z_Step | 105 | | Z_Dir | 104
E0_Step | 107 | | E0_Dir | 106
E1_Step | 115 | | E1_Dir | 114
E2_Step | 112 | | E2_Dir | 113
E3_Step | 110 | | E3_Dir | 111
E4_Step | 121 | | E4_Dir | 122
XYZE_ENABLE | 128 | |  |
Heater Bed |  109 | |  Heater_Hotend0 |  108
Heater_Hotend1 |  123 || |
Fan0(model) |  118 | | Fan1(model) | 119 
Fan2(Hotend0/E0 Auto) | 120 | |   |   
Bed Thermistor |  36 | | Hotend0 Thermistor |  39
Hotend1 Thermistor | 34  | |  |
Filament Runout |  22 || RGB light|  15
DHT11 | 13  | |  |   
LCD_BTN | 32 | | LCD_BTN1 | 33 
LCD_BTN2 |  25 | | LCD_RS |  27
LCD_ENABLE |  26 | | LCD_D4 |  14
Beeper |  129 || |
SD_MOSI | 23 | | SD_MISO | 19
SD_SCK | 18 | | SDSS | 5
SD_DETECT | 2 | |  |
SPEAKER | 25 | |  |

[test video](https://youtu.be/NXPrnBnW2KA)

[Support me by buying](https://www.pandapi3d.com/)
