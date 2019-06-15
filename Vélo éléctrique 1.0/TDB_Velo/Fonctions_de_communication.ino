int valueToSend;
boolean stringComplete = false;
extern byte eclairage;

#define BUF_SIZE 50
char buf[BUF_SIZE];
uint8_t bufPos = 0;

void CheckSerial()
{
  if(stringComplete) 
   { 
      //Serial.println(buf);
      
      stringComplete = false;
      
      if(buf[0]=='#')  //On vérifie le début de la trame
      {
        vitesse =     bufToInt(true);
        RPMPedale =   bufToInt(false);      
        odometre =    bufToInt(false);        
        trip =        bufToInt(false);         
        batterie =    bufToInt(false);                                 
        puissance =   bufToInt(false);       
        distanceParTour = bufToInt(false);  
        nbreMagRoue = bufToInt(false);                              
        nbreMagPedale =   bufToInt(false);          //on récupère le nombre d'aimant sur le pedalier
      }
      else
        Serial.println("no valid data");
  }
  //Envoie des données au microcontroller host
  Serial.write('C');
  Serial.print(GetConsigne());
  Serial.write('E');
  Serial.print(eclairage);
  if(eclairage > 0b00000111)
  {
    eclairage = eclairage & 0b00000111;
    Serial.write('S');
    Serial.print(valueToSend);
    valueToSend = 0;
  }
  Serial.write('\n');
}

long bufToInt(boolean init)
{
  static uint8_t index;
  
  if(init)
    index = 0;
    
  while(buf[index] != ' ')
        index++;
  long tempD = atol(&buf[index]);
  index++;
  return tempD;    
}

void SendCommandToHost(byte mask, int var)
{
  //Serial.print("avant : ");
  //Serial.println(eclairage);
  eclairage += mask;
  //Serial.print("après : ");
  //Serial.println(eclairage);
  valueToSend = var;
  AfficheCommand("Command sended");
  delay(500);
}


void serialEvent() 
{
    while(Serial.available())
    {
      char c = Serial.read();
      //gestion du début de la trame et du buffer circulaire
      
      if((c == '#') || (bufPos >= BUF_SIZE))
        bufPos = 0;
        
      buf[bufPos] = c;
      bufPos++;
      // Set flag if received '\n'
      if(c == '\n')
        stringComplete = true;
    }
    
    
      
}
