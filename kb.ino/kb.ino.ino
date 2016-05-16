



// kb.ino - Koch Box sketch

//#include <Wire.h>
#include <SoftwareSerial.h>
/*#include <SPI.h>
#include <SD.h>
#include <rgb_lcd.h>            // library from GITHUB/Seeed-Studio/Grove_LCD_RGB_Backlight
#include <RTClib.h>             // library from GITHUB/adafruit/RTClib
#include <Adafruit_DRV2605.h>   // library from GITHUB/adafruit/Adafruit_DRV2605_Library
#include <Adafruit_TPA2016.h>   // library from GITHUB/adafruit/Adafruit-TPA2016-Library
#include <GY80.h>               // library from GITHUB/muggn/GY80
*/
SoftwareSerial mySerial(10, 11); // RX, TX

/*
// LCD
rgb_lcd lcd;
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
*/
/*
// SD card
// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;
// change this to match your SD shield or module;
// Arduino Ethernet shield: pin 4
// Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
const int chipSelect = 4;
*/

/*
// RTC
RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// haptic chip 
Adafruit_DRV2605 drv;

// audio i2c amplifier
Adafruit_TPA2016 audioamp = Adafruit_TPA2016();

// GY80 sensor board
GY80 sensor = GY80(); //create GY80 instance
*/

void setup() {
  // Open serial communications and wait for port to open:
/*  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  */
/*

  Serial.print("\nInitializing SD card...");

  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card inserted?");
    Serial.println("* is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
    return;
  } else {
    Serial.println("Wiring is correct and a card is present.");
  }

  // print the type of card
  Serial.print("\nCard type: ");
  switch (card.type()) {
    case SD_CARD_TYPE_SD1:
      Serial.println("SD1");
      break;
    case SD_CARD_TYPE_SD2:
      Serial.println("SD2");
      break;
    case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC");
      break;
    default:
      Serial.println("Unknown");
  }

  // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
  if (!volume.init(card)) {
    Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
    return;
  }


  // print the type and size of the first FAT-type volume
  uint32_t volumesize;
  Serial.print("\nVolume type is FAT");
  Serial.println(volume.fatType(), DEC);
  Serial.println();

  volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
  volumesize *= volume.clusterCount();       // we'll have a lot of clusters
  volumesize *= 512;                            // SD card blocks are always 512 bytes
  Serial.print("Volume size (bytes): ");
  Serial.println(volumesize);
  Serial.print("Volume size (Kbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);
  Serial.print("Volume size (Mbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);


  Serial.println("\nFiles found on the card (name, date and size in bytes): ");
  root.openRoot(volume);

  // list all files in the card with date and size
  root.ls(LS_R | LS_DATE | LS_SIZE);
*/
//  mySerial.begin(4800);
//  mySerial.println("Hello, world?");
/*
      // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
    lcd.print("hello, world!");
*/
    delay(1000);
/*
      if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  
  */
  
  /*
   
   drv.begin();
  
  drv.selectLibrary(1);
  
  // I2C trigger by sending 'go' command 
  // default, internal trigger when sending GO command
  drv.setMode(DRV2605_MODE_INTTRIG); 
*/

/*

 audioamp.begin();
 
 // Dump register map, for debugging purposes.
 /*
 for (uint8_t i=1; i<8; i++) {
   Serial.print("Register #"); Serial.print(i); 
   Serial.print(": 0x");
   Serial.println(audioamp.read8(i), HEX);
 }
 */

 /*
  // Turn off AGC for the gain test
  audioamp.setAGCCompression(TPA2016_AGC_OFF);
  // we also have to turn off the release to really turn off AGC
  audioamp.setReleaseControl(0);
  
  // We can update the gain, from -28dB up to 30dB
  for (int8_t i=-28; i<=30; i++) {
    Serial.print("Gain = "); Serial.println(i); 
    audioamp.setGain(i);
    delay(500);
  }
  
  // Each channel can be individually controlled
  Serial.println("Left off");
  audioamp.enableChannel(true, false);
  delay(1000);
  Serial.println("Left On, Right off");
  audioamp.enableChannel(false, true);
  delay(1000);
  Serial.println("Left On, Right On");
  audioamp.enableChannel(true, true);
  delay(1000);

  // OK now we'll turn the AGC back on and mess with the settings :)
  
  // AGC can be TPA2016_AGC_OFF (no AGC) or
  //  TPA2016_AGC_2 (1:2 compression)
  //  TPA2016_AGC_4 (1:4 compression)
  //  TPA2016_AGC_8 (1:8 compression)
  Serial.println("Setting AGC Compression");
  audioamp.setAGCCompression(TPA2016_AGC_2);

  // See Datasheet page 22 for value -> dBV conversion table
  Serial.println("Setting Limit Level");
  audioamp.setLimitLevelOn();
  // or turn off with setLimitLevelOff()
  audioamp.setLimitLevel(25);  // range from 0 (-6.5dBv) to 31 (9dBV)
  
  // See Datasheet page 23 for value -> ms conversion table
  Serial.println("Setting AGC Attack");
  audioamp.setAttackControl(5);
  
  // See Datasheet page 24 for value -> ms conversion table
  Serial.println("Setting AGC Hold");
  audioamp.setHoldControl(0);
  
  // See Datasheet page 24 for value -> ms conversion table
  Serial.println("Setting AGC Release");
  audioamp.setReleaseControl(11);
  */
}


uint8_t effect = 1;


void loop(void) {

  /*
  Serial.print("Effect #"); Serial.println(effect);

// set the effect to play
  drv.setWaveform(0, effect);  // play effect 
  drv.setWaveform(1, 0);       // end waveform

  // play the effect!
  drv.go();

  // wait a bit
  delay(500);

  effect++;
  if (effect > 117) effect = 1;

      GY80_scaled val = sensor.read_scaled();       //get values from all sensors
    // print out values

    Serial.print("Mag:");                         //magnetometer values
    Serial.print(val.m_x,2);
    Serial.print(',');
    Serial.print(val.m_y,2);
    Serial.print(',');
    Serial.print(val.m_z,2);
    Serial.print(' ');
    Serial.print("Acc:");                         //accelerometer values
    Serial.print(val.a_x,3);
    Serial.print(',');
    Serial.print(val.a_y,3);
    Serial.print(',');
    Serial.print(val.a_z,3);
    Serial.print(' ');
    Serial.print("Gyro:");                        //gyroscope values
    Serial.print(val.g_x,1);
    Serial.print(',');
    Serial.print(val.g_y,1);
    Serial.print(',');
    Serial.print(val.g_z,1);
    Serial.print(' ');
    Serial.print("P:");                           //pressure values
    Serial.print(val.p,5);
    Serial.print(' ');
    Serial.print("T:");                           //temperature values
    Serial.println(val.t,1);


    delay(250);        // delay in between reads for stability

    */
}
