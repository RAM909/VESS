#VESS

COMPONENTS USED

Arduino uno
Sd card module
Potentiometer

CONNECTION
SD CARD

CS-----pin4
SCK----pin13
MOSI----pin11
MISO----pin12
VCC
GND
POTENTIOMETER
Signal pin---A0
VCC
GND

SPEAKER
Speaker out---pin9

INSERTING AUDIOFILE IN SDCARD 
The audiofile should be in wav extention for converting into wav format you can use the following link
https://audio.online-convert.com/convert-to-wav
simply after opening the website upload your song and apply the following settings
BIT RESOLUTION---8bit
AUDIO FREQUENCY---16000hz
AUDIO CHANNEL---mono
PCM FORMAT---U8
Then download the song or sound .
Save this song in formatted SD card not in any folder

CODE

For this I have used TMRPCM library and made some changes in that .You will find this library below or either You can do the following changes yourself
Create a function in the TMRpcm.cpp file I called this ‘changespeed’, so my function declaration was this:
void TMRpcm::changespeed(unsigned int newspeed){
    unsigned long newSR = map(newspeed, 0, 1023, 8000, 44100);

    if (bitRead(optionByte,6)) *ICRn[tt] = 10 * (800000 /  newSR);
	else *ICRn[tt] = 10 * (1600000 / newSR);
}
and I put this at line 448, just before the area marked
//***************************************************************************************
//********************** Functions for single track playback ****************************
(though I could probably have put this anywhere in the tmrpcm.cpp file).
Then, I modified the ‘TMRpcm.h’ file accordingly, to add the new function to the list of available functions or the compiler gets confused if you don’t. Again, I added this before the play function (line 31)
 	void changespeed(unsigned int newspeed);
Now, I can call this function from anywhere in my code whenever I want to change the playback speed, if I want to control if from analog0, I just call tmrpcm.changespeed(analogRead(A0));





From this you can control the playback speed accordingly I am using pot right now as analog sensor 
And to control the playback speed.


  



