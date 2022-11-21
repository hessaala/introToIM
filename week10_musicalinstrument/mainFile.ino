#include "pitches.h"
#define ACTIVATED LOW

const int POTENTIOMETER_PIN = A0;
const int PIEZO = 11;
const int LED = 13;

const int BUTTON_C = 6;
const int BUTTON_B = 4;
const int BUTTON_A = 3;
const int BUTTON_G = 2;
const int BUTTON_D = 8;


void setup()
{
  Serial.begin(9600);
  //pinMode(LED, OUTPUT);
  pinMode(BUTTON_C, INPUT);
  digitalWrite(BUTTON_C,HIGH);
  pinMode(BUTTON_B, INPUT);
  digitalWrite(BUTTON_B,HIGH);
  pinMode(BUTTON_A, INPUT);
  digitalWrite(BUTTON_A,HIGH);
  pinMode(BUTTON_G, INPUT);
  digitalWrite(BUTTON_G,HIGH);
  pinMode(BUTTON_D, INPUT);
  digitalWrite(BUTTON_D,HIGH);
  
  //digitalWrite(LED,LOW);
}




void loop()
{
  int analogValue = analogRead(POTENTIOMETER_PIN);
  if(analogValue > 500){
   while(digitalRead(BUTTON_C) == ACTIVATED)
  {
    digitalWrite(PIEZO, HIGH);
    tone(PIEZO,NOTE_C5);
    //digitalWrite(LED,HIGH);
  }
  while(digitalRead(BUTTON_B) == ACTIVATED)
  {
    tone(PIEZO,NOTE_B4);
     digitalWrite(PIEZO, HIGH);
   // digitalWrite(LED,HIGH);
  }

  while(digitalRead(BUTTON_A) == ACTIVATED)
  {
    tone(PIEZO,NOTE_A4);
     digitalWrite(PIEZO, HIGH);
    //digitalWrite(LED,HIGH);
  }
  
  while(digitalRead(BUTTON_G) == ACTIVATED)
  {
    tone(PIEZO,NOTE_G4);
     digitalWrite(PIEZO, HIGH);
   // digitalWrite(LED,HIGH);
  }
  
  while(digitalRead(BUTTON_D) == ACTIVATED)
  {
    tone(PIEZO,NOTE_D5);
     digitalWrite(PIEZO, HIGH);
   // digitalWrite(LED,HIGH);
  }
  }
  noTone(PIEZO);
 // digitalWrite(LED,LOW);

}
