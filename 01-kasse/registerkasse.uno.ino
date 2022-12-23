/* 
 This sketch uses LCD Display, keyboard, passive buzzer and rfid reader to
 create a small example of a cash register device with electronic payment.

 Special characters for Display
 lcd.print(" \xE1 ") =ä
 lcd.print(" ? ") =ö
 lcd.print(" ? ") =ü

 */

// include the library code:
#include <LiquidCrystal.h>
#include "pitches.h"

// static variables
// notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int pitchDuration = 300;  // 500 miliseconds

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

  scrollText(27,16)

  playTones();
}

void playTones(){
    for (int thisNote = 0; thisNote < 8; thisNote++) {
    // pin8 output the voice, every scale is 0.5 sencond
      tone(13, melody[thisNote], pitchDuration);
     
    // Output the voice after several minutes
    delay(1000);
  } 
} 

void scrollText(unsigned short textLength, unsigned short displayLength){
  for (int positionCounter = 0; positionCounter < textLength; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(700);
  }


  // scroll string length + display length to the right
  // to move it offscreen right:
  unsigned short scrollLength = textLength + displayLength;
  for (int positionCounter = 0; positionCounter < scrollLength; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(700);
  }
}
