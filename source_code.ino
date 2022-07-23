#include "pitches.h"
#define ACTIVATED LOW


const int PIEZO = 11;
const int LED_A = 13;
const int LED_B = 12;
const int LED_C = 9;
const int LED_D = 7;
const int LED_I = A3;
const int LED_J = A4;
const int LED_K = A5;

int buttonSong = 8;
const int BUTTON_C = 6;
const int BUTTON_AS = 4;
const int BUTTON_A = 3;
const int BUTTON_G = 2;
const int BUTTON_I = A0;
const int BUTTON_J = A1;
const int BUTTON_K = A2;


void setup()
{
  Serial.begin(9600);
  
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B,OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(LED_D, OUTPUT);
  pinMode(LED_I, OUTPUT);
  pinMode(LED_J, OUTPUT);
  pinMode(LED_K, OUTPUT);
  pinMode(BUTTON_C, INPUT);
  digitalWrite(BUTTON_C,LOW);
  pinMode(BUTTON_AS, INPUT);
  digitalWrite(BUTTON_AS,LOW);
  pinMode(BUTTON_A, INPUT);
  digitalWrite(BUTTON_A,LOW);
  pinMode(BUTTON_G, INPUT);
  digitalWrite(BUTTON_G,LOW);
  pinMode(BUTTON_I, INPUT);
  digitalWrite(BUTTON_I,LOW);
  pinMode(BUTTON_J, INPUT);
  digitalWrite(BUTTON_J,LOW);
  pinMode(BUTTON_K, INPUT);
  digitalWrite(BUTTON_K,HIGH);
  pinMode (buttonSong, INPUT);
  digitalWrite(buttonSong, LOW);
  
  digitalWrite(LED_A,LOW);
  digitalWrite(LED_B,LOW);
  digitalWrite(LED_C,LOW);
  digitalWrite(LED_D,LOW);
  digitalWrite(LED_I,LOW);
  digitalWrite(LED_J,LOW);
  digitalWrite(LED_K,LOW);
}


// notes in the melody:
int melody[] = {
NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, 0, 0,
NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_D4, 0, 0, 0, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_D5,
NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_AS3, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_AS4, 
NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_AS3,


NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, 0, 0,
NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_D4, NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_F3, NOTE_AS3, NOTE_A3, NOTE_F3, 
NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_D5,
NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_F3, NOTE_AS3, NOTE_G3, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_AS4, 




};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  
4.5, 2.25, 2.25, 4.5, 2.25, 2.25, 2.25, 2.25, 2.25, 4.5, 3, 9, 4.5, 
4.5, 2.25, 4.5, 2.25, 1.125, 2.25, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2.25, 
4.5, 4.5, 4.5, 2.25, 4.5, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2, 
4.5, 4.5, 4.5, 2.25, 4.5, 4.5,

4.5, 2.25, 2.25, 4.5, 2.25, 2.25, 2.25, 2.25, 2.25, 4.5, 3, 9, 4.5, 
4.5, 2.25, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 3, 3, 4.5, 
2.25, 4.5, 2.25, 4.5, 2.25, 
4.5, 4.5, 4.5, 4.5, 2.25, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2.25, 






} ;


void loop()
{
   while(digitalRead(BUTTON_C) == ACTIVATED)
  {
    
    tone(PIEZO,NOTE_C5);
    digitalWrite(LED_A,HIGH);
    
    
   }

  
  while(digitalRead(BUTTON_AS) == ACTIVATED)
  {
    tone(PIEZO,NOTE_AS4);
    digitalWrite(LED_B,HIGH);
    
    
  }
  

  while(digitalRead(BUTTON_A) == ACTIVATED)
  {
    tone(PIEZO,NOTE_A4);
    digitalWrite(LED_C,HIGH);
    
  }

  

  
  while(digitalRead(BUTTON_G) == ACTIVATED)
  {
    tone(PIEZO,NOTE_G4);
    digitalWrite(LED_D,HIGH);
    
  }

  

  while(digitalRead(BUTTON_I) == ACTIVATED)
  {
    tone(PIEZO,NOTE_G3);
    digitalWrite(LED_I,HIGH);
   
  }

  

  while(digitalRead(BUTTON_J) == ACTIVATED)
  {
    tone(PIEZO,NOTE_G4);
    digitalWrite(LED_J,LOW);
    
  }

  

  while(digitalRead(BUTTON_K) == ACTIVATED)
  {
    tone(PIEZO,NOTE_G4);
    digitalWrite(LED_K,LOW);
     
  }
  
  if(digitalRead(buttonSong) == ACTIVATED) {
    for (int thisNote=0; thisNote <85; thisNote++) {
      int noteDuration = 600 / noteDurations[thisNote];
      tone(11, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.50;
      delay(pauseBetweenNotes);
      noTone(11);
    }
 
    
  }

  noTone(PIEZO);
  digitalWrite(LED_A,LOW);
  digitalWrite(LED_B,LOW);
  digitalWrite(LED_C,LOW);
  digitalWrite(LED_D,LOW);
  digitalWrite(LED_I,LOW);
  digitalWrite(LED_J,LOW);
  digitalWrite(LED_K,LOW);
 
}
