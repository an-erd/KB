# KB
Seeed Studio Grove - LCD RGB Backlight; http://www.seeedstudio.com/depot/Grove-LCD-RGB-Backlight-p-1643.html
Adafruit MicroSD card breakout board+; https://www.adafruit.com/products/254
Adafruit DS1307 Real Time Clock breakout board kit; https://www.adafruit.com/products/264
GY-80 (L3G4200D ADXL345 HMC5883L BMP085)


PRO TRINKET
===========
  0         (RX)
  1         (TX)
  2         (USB)
  3~        ROT ENC LED Red
  4         ROT ENC Push Button
  5~        ROT ENC LED Green
  6~        ROT ENC LED Blue
  7         (USB)
  8                           - available
  9~        ON/OFF Switch LED Blue
  10        (SS)
  11        (MOSI)
  12        (MISO)
  13        (SCK)
  A0        ROT ENC Pin A
  A1        ROT ENC Pin B
  A2                          - available
  A3                          - available
  A4        (I2C SDA)
  A5        (I2C SCL)
  A6                          - available
  A7                          - available
  
Micro SD card breakout board
============================
  CLK       <->   PRO TRINKET 13 (SCK)
  DO        <->   PRO TRINKET 12 (MISO)
  DI        <->   PRO TRINKET 11 (MOSI)
  CS        <->   PRO TRINKET 10 (SS)
  CD        <->   (unused / card detection)
  
Rotary Encoder
==============
  A         <->   PRO TRINKET A0
  B         <->   PRO TRINKET A1
  LED R     <->   PRO TRINKET 3~
  LED G     <->   PRO TRINKET 5~
  LED B     <->   PRO TRINKET 6~
  BUTTON    <->   PRO TRINKET 4
  
  
I2C devices
===========
Real time clock:  
  RTC address                                       0x68
LCD display:
  LCD address                                       0x7C
  RGB address                                       0xC4
10-DOF GY-80:
  3 Axis Gyro ST Microelectronics L3G4200D          0x69
  3 Axis Accelerometer: Analog Devices ADXL345      0x53
  3 Axis Magnetometer; Honeywell MC5883L            0x1E
  Barometer + Thermometer; Bosch BMP085             0x77
