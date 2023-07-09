#include <SD.h> // need to include the SD library
#define SD_ChipSelectPin 4 //connect pin 4 of arduino to cs pin of sd card
#include <TMRpcm.h> //Arduino library for asynchronous playback of PCM/WAV files
#include <SPI.h> //  need to include the SPI library

TMRpcm tmrpcm; // create an object for use in this sketch
int val;
int potpin= 0;
void setup()
{ 
 
 tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc
 Serial.begin(9600);
 if (!SD.begin(SD_ChipSelectPin)) // returns 1 if the card is present
 {
  Serial.println("SD fail");
  return;
 }
 tmrpcm.setVolume(5);  //sets volume(0 to 7)  
 tmrpcm.play("SONG12.wav"); //the sound file "song" will play each time the arduino powers up, or is reset//i have added the sound of engine so that to get that engine effect
                     
  tmrpcm.loop(1);                   
                     
}


void loop()
{  
    val = analogRead(potpin);            //reading value from any analog sensors for trial i have used pot
val = map(val,0,1023,0,800);//its map tha analog value that is coming from 0 to 1023 TO 0 to 800, or u can map according to you delay(500);
if(val>500)
{
 val=500;
}
if(val<100)
{
  val=100;
}
Serial.println(val);

 tmrpcm.changespeed(val);  //changing tha playback speed.
Serial.flush();
} 


  
