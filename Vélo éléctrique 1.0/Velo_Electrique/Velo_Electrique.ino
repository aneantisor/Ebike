#include <Servo.h>

Servo moteur;
int potpin = A4;
int consigne;
int i = 0;

void setup() 
{
  Serial.begin(115200);
  moteur.attach(9);
  pinMode(A5,OUTPUT);
  digitalWrite(A5, HIGH);
  pinMode(13, OUTPUT);
}

void loop() 
{
  Serial.println(consigne);
  consigne = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  consigne = map(consigne, 0, 1023, 20, 180);     // scale it to use it with the servo (value between 0 and 180)
  moteur.write(consigne); 
  Serial.println(consigne); 
  i++;
  digitalWrite(13, !(i%consigne/10));
  delay(15);                         

}
