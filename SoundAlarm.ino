/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 16 March. 2017
 modified 30 March 2017
 by James Coggins

 This example code is in the public domain.

 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = 12;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
#include "rgb_lcd.h"

rgb_lcd lcd;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  lcd.begin(1,1);
  lcd.setRGB(0,255,0);
  //print message
  
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  if (sensorValue > 385)
  {
    
    lcd.print("WARNING TOO LOUD!");
    lcd.setRGB(255,0,0);
  }

  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  
  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2000);
  lcd.setRGB(0,255,0);
  lcd.clear();
 
}
