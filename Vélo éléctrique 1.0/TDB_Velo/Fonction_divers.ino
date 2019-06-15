#define POT A6
     

void AdaptTensionLeds()
{
  tensionLeds = (batterie+5)/10;
}


uint8_t NumberOfFloat(float var)
{
  uint8_t tempA = 0;
  if(var<0)
  {
    tempA = 1;
    var = -var;
  }
  if(var < 100)
    return 4 + tempA;
  else if(var < 1000)
    return 6 + tempA;
  else if(var < 10000)
    return 8 + tempA;
  else
    return 10 + tempA;    
}


uint8_t NumberOfDigit(int32_t var)
{
  uint8_t tempB = 0;
  if(var<0)
  {
    tempB = 1;
    var = -var;
  }
  if(var<10)
    return 2 + tempB;
  else if(var < 100)
    return 4 + tempB;
  else if(var < 1000)
    return 6 + tempB;
  else if(var < 10000)
    return 8 + tempB;
  else
    return 10 + tempB;    
}

int GetConsigne()
{
  static int consigne;
  int16_t tempC = analogRead(POT);
  
  if(tempC > 950) //on considère un court circuit au 5v
      consigne = 0;
  else
  {
  //Ci dessous, on applique le filtre passe bas
    float x = (float)(tempC - consigne)/4; // divisé par 4
    //Ici, on limite la vitesse de montée de la consigne
    if(x>20)
      x = 20;
    consigne += (int) x;
  }
  return consigne;
}


void debug()
{
  Serial.print("input 2 : ");
  Serial.println(input2);
  Serial.print("dim : ");
  Serial.println(dim);
  Serial.print("tension : ");
  Serial.println(batterie);
  Serial.print("courant : ");
  Serial.println(courant);
  Serial.print("puissance : ");
  Serial.println(puissance);
  Serial.print("puissance moteur : ");
  Serial.println(puissanceMoteur);
  Serial.print("consommation : ");
  Serial.println(consommation);
  
}

