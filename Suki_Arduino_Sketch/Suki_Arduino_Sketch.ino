#include "pitches.h"
#include <Servo.h>

const int photocellPin = 0; //sets pin that will be receiving and writing to the serial monitor the light readings
int photocellReading;       //creates the variable the sensor will read to and print on monitor
int duration =250;          //duration between each note of the scale to be played
int melody[] = {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};  //C major scale that will play twice when triggered
Servo myservo;
int pos = 90;               //sets initial servo position to 90

void setup(void) 
{
  Serial.begin(9600);   
  myservo.attach(9);
}
 
void loop(void) 
{
  photocellReading = analogRead(photocellPin); 
  Serial.print("Light sensor reading: ");
  Serial.println(photocellReading);
  if(photocellReading >= 18)                                  //the sensor will take a reading each second and if it is 18 or above, the below will be triggered
  {
    delay(10000);                                             //wait 10 seconds first because of the delay with the camera
    for(int repetitions = 0; repetitions < 2; repetitions++)  //sets the repetitions of the scale to be 2
    {
      for (int thisNote = 0; thisNote < 8; thisNote++)        //plays all 8 notes in the scale
      {
        tone(8, melody[thisNote], duration);
        delay(200);
      }
    } 
  delay(1000);

for(pos = 90; pos >= 0; pos-=1){                              //servo will move in 1 degree increments down to 0 from 90, the servo movements are what dispenses the treat
    myservo.write(pos);
    delay(15);
  }
for (pos = 0; pos <= 180; pos += 1) {                        //servo will move in 1 degree increments to 180
  myservo.write(pos);              
  delay(15);                      
  }
for (pos = 180; pos >= 90; pos -= 1) {                       //servo will move in 1 degree increments back to 90
    myservo.write(pos);              
    delay(15);                       
  }  

delay(5000);                                                  //after triggering, it will wait an additional 5 seconds to see if the camera is still in use
  }
  else 
  {
  delay(1000);                                                //the light sensor will check the light level every second, any shorter and there could be flashes that trigger everything
  }
}
