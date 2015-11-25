/*
  MP3FLASH16P.h - Library for the MP3 FLASH 16P module
  Created by /u/Critters
  Released into the public domain
*/

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "MP3FLASH16P.h"
SoftwareSerial MP3Serial(10, 11);

MP3FLASH16P::MP3FLASH16P()
{ 
}

void MP3FLASH16P::init(int PIN_BUSY, int VOLUME)
{
    _PIN_BUSY = PIN_BUSY;
    _VOLUME = (uint8_t)VOLUME;
    MP3Serial.begin(9600);
    pinMode(_PIN_BUSY, INPUT);
    digitalWrite(_PIN_BUSY, LOW);
}

void MP3FLASH16P::playFile(int FILE_NUMBER, int VOLUME)
{   
    if(VOLUME != -1)
    {
        _VOLUME = (uint8_t)VOLUME;
    }
    uint8_t filenumber = (uint8_t)FILE_NUMBER;
    uint8_t play1[8] = { 0X7E, 0XFF, 0X06, 0X22, 0X00, _VOLUME, filenumber, 0XEF };
    for (int i=0; i<8; i++) 
    {
        MP3Serial.write( play1[i] ); 
    }
}

void MP3FLASH16P::playFileAndWait(int FILE_NUMBER, int VOLUME)
{
    playFile(FILE_NUMBER, VOLUME);
    delay(100);
    while(isBusy()){
    }
    delay(250);
}

bool MP3FLASH16P::isBusy()
{
    return digitalRead(_PIN_BUSY) == LOW;
}

void MP3FLASH16P::setVolume(int VOLUME)
{
    _VOLUME = constrain(VOLUME, 0, 30);
}

void MP3FLASH16P::volumeUp()
{
    _VOLUME = min(_VOLUME+5, 30);
}

void MP3FLASH16P::volumeDown()
{
    _VOLUME = max(_VOLUME-5, 0);
}

void MP3FLASH16P::stopPlay()
{   
    uint8_t play1[8] = { 0X7E, 0XFF, 0X06, 0X16, 0X00, 0x00, 0x00, 0XEF };
    for (int i=0; i<8; i++) 
    {
        MP3Serial.write( play1[i] ); 
    }
}



