//www.elegoo.com
//2016.12.9

/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

lcd.print(" \xE1 ") =ä
lcd.print(" ? ") =ö
lcd.print(" ? ") =ü

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>
#include "pitches.h"
 
// notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int duration = 300;  // 500 miliseconds
 

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // Display löschen
  lcd.clear();
  lcd.home();
  
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  // lcd.print("Brieftr\xE1ger \xE1rgern");
  
  lcd.print("lieblingsmenschen sind toll");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // lcd.setCursor(5, 1);
  // print the number of seconds since reset:
  // lcd.print(millis() / 1000);

  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {

    // scroll one position left:

    lcd.scrollDisplayLeft();

    // wait a bit:

    delay(700);

  }


  // scroll 29 positions (string length + display length) to the right

  // to move it offscreen right:

  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {

    // scroll one position right:

    lcd.scrollDisplayRight();

    // wait a bit:

    delay(700);
  }

  playTones();
}

void playTones()
  {
    for (int thisNote = 0; thisNote < 8; thisNote++) {
    // pin8 output the voice, every scale is 0.5 sencond
      tone(13, melody[thisNote], duration);
     
    // Output the voice after several minutes
    delay(1000);
  }  
}
