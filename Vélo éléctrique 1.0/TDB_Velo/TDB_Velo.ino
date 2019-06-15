#include <TimerOne.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


int i=0;

int vitesse = 0;          // info <--
int vitesseMoyenne = 0;
int RPMPedale = 0;    // info <--
int batterie = 0;          // info <-- 
int tensionLeds= 0;     
int courant = 0;          // info <--
int puissance = 0;        // info <--
int puissanceMoteur = 0;  // info <--
int consommation = 0;  // info <--
unsigned long odometre = 0;  // info <--
unsigned long trip = 0;  // info <--


byte distanceParTour = 203;
byte nbreMagRoue = 8;
byte nbreMagPedale = 4;

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() 
{
  Serial.begin(115200);
  InitPot();
  InitOled();
  
  Timer1.initialize(1000); // set a timer of length 1000 microseconds
  Timer1.attachInterrupt( BoucleLed );
  
  InitLed();
  InitLights();
}

void loop() 
{
  i++;
  if(!(i%10))//ce qui se passe dans cette boucle se répète 10 fois moins vite
  {
    //debug();
    
  }
  OledRefresh();
  SetLights();
  CommandButton();   
  AdaptTensionLeds();
  CheckSerial();
  
  delay(50);
}


















