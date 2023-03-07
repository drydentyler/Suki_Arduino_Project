#include <Servo.h>
#include "pitches.h"
 
 
 const int ledPin = 13;
 int photocellPin = 0;  // the cell and 10K pulldown are connected to a0

 int photocellReading;     // the analog reading from the sensor divider
 int duration =250;  // 500 miliseconds

 int melody[] = {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};

 Servo myServ;

void setup(void) 
{
  Serial.begin(9600);   
  pinMode(ledPin, OUTPUT);
  myServ.attach(7);
  myServ.write(0);
}
 
void loop(void) 
{
  photocellReading = analogRead(photocellPin); 
  Serial.print("Light sensor reading: ");
  Serial.println(photocellReading);
  
  if(photocellReading > 100) 
  {
    digitalWrite(ledPin, HIGH);
      
    for(int repetitions = 0; repetitions < 2; repetitions++)
    {
      if(myServ.read() == 0)
        {
          myServ.write(180);
        }
        else
        {
          myServ.write(0);
        }
      for (int thisNote = 0; thisNote < 8; thisNote++) 
      {
        tone(8, melody[thisNote], duration);
          //Serial.print("BRIGHT - song should have played: ");
          //Serial.println(photocellReading);
          // Output the voice after several minutes
        delay(200);
      }
    } 
    delay(1000);
  }
  else 
  {
  // turn LED off:
  digitalWrite(ledPin, LOW);
  //Serial.print("Dark - no song playing: ");
  //Serial.println(photocellReading);
  delay(100);
  }
}
