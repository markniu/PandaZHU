
PandaZHU use ESP32 as the mcu for 3D printer motherboard. Zhu is Chinese for bamboo

it has  larger memory and more powerful than normal 32bit 3D printer motherboard.

the file upload speed to sd card is also higher than it as a wifi module, it can support more motor drivers with one fast expand GPIO chip.

![](https://gitee.com/markyue/pandapi_wiki/raw/master/imges/esp/15090314.jpg)

Items | Specifications  
--- | --- 
MCU | Two 32-bit MCU ,240MHz
RAM |  520 KBytes SRAM |	
ROM |  4M Bytes Flash memory
EXGPIO | there are 24 more GPIOs(only as output) with a expander, the communication speed is 1.4MHz, and the actual speed of gpio output is 70kHz jitter free stepping that can drive the X/Y axis to speed 900mm/s .
WiFi |  802.11 b/g/n/d/e/i/k/r (802.11n up to 150 Mbps),Bluetooth v4.2
temperature | support 3 thermistors (30degree~260degree)
Bed leveling    | 	  BLtouch/ support wild range voltage 5V~36V Inductive sensor NPN, since it have optocoupler.
LCD   | 	LCD128*64/PandaTouchScreen/DGUS touch screen
RJ11  |  for DGUS touch screen 
Serial chip   | 	CH340G	  
Input   | 	9~28V 20A max	
heater Output   | 3 heaters,	15Amax for each heater (100A mosfet PSMN1R0-30YLC)	 
stepper driver   |  8 drviers(TMC2209/TMC2208/A4988),9 motor connectors(Z0_A and Z0_B are connected to the same driver)
FAN | Support mixed use of 5V/24V fans,3 of them are controllabe fans
Audio |  play music at boot, Error/alarm music..
OS | Real-time operating systems (RTOS)
App | control printer, upload files with web browser ,[see more](https://github.com/luc-github/ESP3D-WEBUI)


### Boards compare
 Name  |  Creality  | SKR MINI E3| SKR Octopus |  SKR E3 RRF | FYSETC E4 | PandaM4 | PandaZHU
--- | --- |---| --- | --- | ---| ---| --- 
MCU | Atmega<br>1284 |STM32F103| STM32F446 |STM32F407 |ESP32|ESP32|ESP32
MCU Bits | 8bit |32bit| 32bit |32bit |32bit|32bit|32bit
Frequency | 20 MHz |72 MHz| 180 MHz |168 MHz |240 MHz|240 MHz|240 MHz
Flash | 128KB |256KB| 512KB |1MB |4MB|4MB|4MB
RAM | 16KB |48KB| 128KB |196KB |520KB|520KB|520KB
ADC | 10bit |12bit| 12bit |12bit |12bit|12bit|12bit
Heaters | 2 |2| 4 |2 |2|2|3
Stepper drivers | 4 |4|8|4|4|4|8
Play audio | no | no | no | no | no | yes |yes
Display | LCD12864 |LCD12864<br>Touchscreen |LCD12864<br>Touchscreen |LCD12864<br>Touchscreen  |no|LCD12864<br>Touchscreen|LCD12864<br>Touchscreen
BLTOUCH | no | yes | yes | yes | no | yes |yes
Wifi speed,Test by <br>  uploading file| 4KB/s <br> Wifi module|4KB/s <br> Wifi module| 4KB/s <br> Wifi module |4KB/s <br> Wifi module |>50KB/s<br>Native wifi|>50KB/s<br>Native wifi|>50KB/s<br>Native wifi
Chip supply | in stock | shortage | shortage | shortage | in stock | in stock |in stock

There is a lot of space to improve the wifi speed of ESP32 as MCU by optimizing the software.


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
