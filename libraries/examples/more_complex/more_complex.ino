/*
    This example plays a file but leaves the decision as to when to play the next file
    down to this script by using playFile() instead of playFileAndWait(). This is a must
    if you want to continue to execute your Arduino code while the sound is playing.
    
    To demonstrate this, the "Blink without delay" example is used to rapidly flash the
    Arduino LED while the sound plays
*/

#include "SoftwareSerial.h"
#include "MP3FLASH16P.h"
MP3FLASH16P myPlayer;

// Variables used in the "Blink without delay" example
const int ledPin =  13;
int ledState = LOW; 
unsigned long previousMillis = 0;
const long interval = 100; 

void setup() {
    // Init the player with the busy pin connected to Arduino pin 3
    myPlayer.init(3);
    // Pin for the arduino blink code
    pinMode(ledPin, OUTPUT);
}

void loop() {
    
    if(!myPlayer.isBusy())
    {
        delay(250);                             // This delay is to remove a clicking sound if the file plays as soon as the previous one ends
        myPlayer.playFile(random(1, 11), 15);   // Plays 001.mp3/wav at 50% (15/30) volume only if it isn't already playing
        delay(100);                             // This delay is to give the file a chance to start playing so isBusy() returns true
        
        /* 
          If you know it's not going to be asked to play a sound as soon as this one finishes and your not 
          checking to see when this one has finished, you can remove both of these delays to speed up playing
          
          Another idea would be to record the millis() when playFile() was called and then wait until it is >100
          older than current before testing against isBusy(), this would remove any delay
        */
    }
    
    /*
      Below is the blink without delay code, while the file is playing you should see the LED 
      on the Arduino rapidly blink to show that the code is running while the sound is playing
    */
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;   
        if (ledState == LOW)
            ledState = HIGH;
        else
            ledState = LOW;
        digitalWrite(ledPin, ledState);
    }
}
