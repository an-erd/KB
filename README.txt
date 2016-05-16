# KB
Seeed Studio Grove - LCD RGB Backlight; http://www.seeedstudio.com/depot/Grove-LCD-RGB-Backlight-p-1643.html ; 5V
Adafruit MicroSD card breakout board+; https://www.adafruit.com/products/254 ; 5V/3.3V 
Adafruit DS1307 Real Time Clock breakout board kit; https://www.adafruit.com/products/264 ; 5V, 5/3.3V logic
GY-80 (L3G4200D ADXL345 HMC5883L BMP085) ; 5V/3.3V
Adafruit DRV2605L Haptic Motor Controller; https://www.adafruit.com/products/2305 ; 2-5.2V
Adafruit Stereo 2.8W Class D Audio Amplifier - I2C Control AGC - TPA2016; https://www.adafruit.com/products/1712 ; 2.7-5.5V
ESP8266, ESP-01

Components and input power for specific board
=============================================
Pro Trinket 3V, w/LiPoly Backpack and 3,7 LiPoly battery attached to be chararged using USB
LCD         5V (using a level shifter and step-up regulator)
Haptic Con  3V from Pro Trinket
Amplifier   3V from Pro Trinket
MicroSD     3V from Pro Trinket

GY-80       3V from Pro Trinket
RTC         5V (using a level shifter and step-up regulator)
ESP8266     3V from Pro Trinket

PRO TRINKET
===========
  0         (RX) (+ESP8266 TX)
  1         (TX) (+ESP8266 RX)
  2         (USB)
  3~        PS/2 Keyboard CLK
  4         ROT ENC Push Button
  5~        speaker PWM tone output (L channel)
  6~        speaker PWM tone output (R channel)				
  7         (USB)
  8         PS/2 Keyboard DATA
  9~        ON/OFF Switch LED Red
  10~       (SS)
  11~       (MOSI)
  12        (MISO)
  13        (SCK)
  A0/14     ROT ENC Pin A
  A1/15     ROT ENC Pin B
  A2/16     ROT ENC LED Red
  A3/17     - available
  A4/18     (I2C SDA)
  A5/19     (I2C SCL)
  A6        - available, analog input only pin 
  A7        - available, analog input only pin
  RST       ESP8266  GPIO0 
  
Micro SD card breakout board
============================
  CLK       <->   PRO TRINKET 13 (SCK)
  DO        <->   PRO TRINKET 12 (MISO)
  DI        <->   PRO TRINKET 11 (MOSI)
  CS        <->   PRO TRINKET 10 (SS)
  CD        <->   (unused / card detection)
  
Rotary Encoder
==============
  A         <->   PRO TRINKET A0/14
  B         <->   PRO TRINKET A1/15
  LED R     <->   PRO TRINKET A2/16
( LED G     <->   unused )
( LED B     <->   unused )
  BUTTON    <->   PRO TRINKET 4
(the Pro Trinket is powered w/3V, which is not enough for the green and blue leds, so only red will be used).  
  
PS/2 Keyboard
=============
  1         <->   PRO TRINKET 8 - DTÀTA
  3         <->   GND
  4         <->   +5V
  5         <->   PRO TRINKET 3 / INT1 - CLK

ESP8266
=======
  UTXD      <->   PRO TRINKET 0 / RX
  URXD      <->   PRO TRINKET 1 / TX
  GPIO0     <->   PRO TRINKET RST

I2C devices
===========
LCD display:
  LCD address                                       0x7C
  RGB address                                       0xC4
Stereo Audio Amplifier
  Controller address                                0xXXX
Haptic Motor Controller
  Controller address                                0x5A

10-DOF GY-80:
  3 Axis Gyro ST Microelectronics L3G4200D          0x69
  3 Axis Accelerometer: Analog Devices ADXL345      0x53
  3 Axis Magnetometer; Honeywell MC5883L            0x1E
  Barometer + Thermometer; Bosch BMP085             0x77
Real time clock:  
  RTC address                                       0x68


Additional information/Docks
============================
- https://github.com/jeelabs/esp-link
