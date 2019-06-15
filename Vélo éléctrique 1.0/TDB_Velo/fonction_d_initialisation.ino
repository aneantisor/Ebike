void InitLights()
{
  pinMode(OUTPUT_LEFT, OUTPUT);
  pinMode(OUTPUT_RIGHT, OUTPUT);
  pinMode(OUTPUT_PHARE, OUTPUT);
}



void InitLed()
{
  int tab[15]={1,2,3,4,5,6,7,8,9,10,0,10,0,10};
  int j = 0, k=0;
  for(j=0; j<17 ; j++)
    {
      for(k=0;k<10;k++)
      {
        tensionLeds = tab[j];
        delay(10);
      }
    }
}

void InitPot()
{
  pinMode(POT, INPUT_PULLUP);
}

