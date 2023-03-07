#include "pitches.h"
 
 
 //const int ledPin = 13;
 const int photocellPin = 0;  // the cell and 10K pulldown are connected to a0

 int photocellReading;     // the analog reading from the sensor divider
 int duration =250;  // 500 miliseconds

 const int solenoidPin = 5;

 int melody[] = {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};


void setup(void) 
{
  Serial.begin(9600);   
  //pinMode(ledPin, OUTPUT);
  pinMode(solenoidPin,OUTPUT);
  digitalWrite(solenoidPin,HIGH);
}
 
void loop(void) 
{
  photocellReading = analogRead(photocellPin); 
  Serial.print("Light sensor reading: ");
  Serial.println(photocellReading);
  
  if(photocellReading > 100) 
  {
    delay(5000);
      
    for(int repetitions = 0; repetitions < 2; repetitions++)
    {
      for (int thisNote = 0; thisNote < 8; thisNote++) 
      {
        tone(8, melody[thisNote], duration);
        delay(200);
      }
    } 
    delay(1000);
    digitalWrite(solenoidPin,LOW);
    delay(100);
    digitalWrite(solenoidPin,HIGH);
    delay(100);
    delay(5000);
  }
  else 
  {
  //digitalWrite(ledPin, LOW);
  delay(100);
  }
}
