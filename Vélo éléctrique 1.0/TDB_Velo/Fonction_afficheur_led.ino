


#define LED0 A3
#define LED1 A2
#define LED2 A1
#define LED3 A0

#define INPUT1 A2
#define INPUT2 A1
#define INPUT3 A0

#define OFF 0
#define SHORT_PRESS 1
#define LONG_PRESS 50


#define PERIOD 1000

int input1 = 0;
int input2 = 0;
int input3 = 0;
boolean keepLeft = false;
boolean keepMiddle = false;
boolean keepRight = false;


int dim;
int leds = 10;
int ledOff = 0;
boolean ledOn = false;

int buttonLeft = OFF, buttonMiddle = OFF, buttonRight = OFF;

void BoucleLed()
{
  if(leds > ledOff){LedOff();}
  else if(leds == 10){Led10();}
  else if(leds == 9){Led9();}
  else if(leds == 8){Led8();}
  else if(leds == 7){Led7();}
  else if(leds == 6){Led6();}
  else if(leds == 5){Led5();}
  else if(leds == 4){Led4();}
  else if(leds == 3){Led3();}
  else if(leds == 2){Led2();}
  else if(leds == 1){Led1();}
  else
  {
    ledOff = tensionLeds;
    leds = 10;
    Bouton();
  }
}

void LedOff()
{
    Timer1.setPeriod(PERIOD);
    leds--;
}
void Led1()
{
    if(!ledOn)
    {
      digitalWrite(LED0, LOW);
      digitalWrite(LED1, HIGH);
      pinMode(LED0, OUTPUT);
      pinMode(LED1, OUTPUT);
      Timer1.setPeriod(dim);
      ledOn = true;
    }
    else
    {
      pinMode(LED0, INPUT);
      pinMode(LED1, INPUT);
      Timer1.setPeriod(PERIOD-dim);
      ledOn = false;
      leds--;
    }
    
}
void Led2()
{
  if(!ledOn)
    {
      digitalWrite(LED0, HIGH);
      digitalWrite(LED1, LOW);
      pinMode(LED0, OUTPUT);
      pinMode(LED1, OUTPUT);
      Timer1.setPeriod(dim);
      ledOn = true;
    }
  else
    {
      pinMode(LED0, INPUT);
      pinMode(LED1, INPUT);
      Timer1.setPeriod(PERIOD-dim);
      ledOn = false;
      leds--;
    }
}
void Led3()
{
  if(!ledOn)
    {
      digitalWrite(LED0, LOW);
      digitalWrite(LED2, HIGH);
      pinMode(LED0, OUTPUT);
      pinMode(LED2, OUTPUT);
      Timer1.setPeriod(dim);
      ledOn = true;
    }
  else
    {
      pinMode(LED0, INPUT);
      pinMode(LED2, INPUT);
      Timer1.setPeriod(PERIOD-dim);
      ledOn = false;
      leds--;
    }
}
void Led4()
{
  if(!ledOn)
    {
      digitalWrite(LED0, HIGH);
      digitalWrite(LED2, LOW);
      pinMode(LED0, OUTPUT);
      pinMode(LED2, OUTPUT);
      Timer1.setPeriod(dim);
      ledOn = true;
    }
  else
    {
      pinMode(LED0, INPUT);
      pinMode(LED2, INPUT);
      Timer1.setPeriod(PERIOD-dim);
      ledOn = false;
      leds--;
    }
}
void Led5()
{
  if(!ledOn)
    {
      digitalWrite(LED0, LOW);
      digitalWrite(LED3, HIGH);
      pinMode(LED0, OUTPUT);
      pinMode(LED3, OUTPUT);
      Timer1.setPeriod(dim);
      ledOn = true;
    }
  else
    {
      pinMode(LED0, INPUT);
      pinMode(LED3, INPUT);
      Timer1.setPeriod(PERIOD-dim);
      ledOn = false;
      leds--;
    }
}
void Led6()
{ 
  if(!ledOn)
    {
      digitalWrite(LED0, HIGH);
      digitalWrite(LED3, LOW);
      pinMode(LED0, OUTPUT);
      pinMode(LED3, OUTPUT);
      Timer1.setPeriod(dim);
      ledOn = true;
    }
  else
    {
      pinMode(LED0, INPUT);
      pinMode(LED3, INPUT);
      Timer1.setPeriod(PERIOD-dim);
      ledOn = false;
      leds--;
    }
}
void Led7()
{
  if(!ledOn)
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED3, HIGH);
      pinMode(LED1, OUTPUT);
      pinMode(LED3, OUTPUT);
      Timer1.setPeriod(dim);
      ledOn = true;
    }
  else
    {
      pinMode(LED1, INPUT);
      pinMode(LED3, INPUT);
      Timer1.setPeriod(PERIOD-dim);
      ledOn = false;
      leds--;
    }
}
void Led8()
{
  if(!ledOn)
    {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED3, LOW);
      pinMode(LED1, OUTPUT);
      pinMode(LED3, OUTPUT);
      Timer1.setPeriod(dim);
      ledOn = true;
    }
  else
    {
      pinMode(LED1, INPUT);
      pinMode(LED3, INPUT);
      Timer1.setPeriod(PERIOD-dim);
      ledOn = false;
      leds--;
    }
}
void Led9()
{
  if(!ledOn)
    {
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      pinMode(LED2, OUTPUT);
      pinMode(LED3, OUTPUT);
      Timer1.setPeriod(dim);
      ledOn = true;
    }
  else
    {
      pinMode(LED2, INPUT);
      pinMode(LED3, INPUT);
      Timer1.setPeriod(PERIOD-dim);
      ledOn = false;
      leds--;
    }
}
void Led10()
{
  if(!ledOn)
    {
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      pinMode(LED2, OUTPUT);
      pinMode(LED3, OUTPUT);
      Timer1.setPeriod(dim);
      ledOn = true;
    }
  else
    {
      pinMode(LED2, INPUT);
      pinMode(LED3, INPUT);
      Timer1.setPeriod(PERIOD-dim);
      ledOn = false;
      leds--;
    }
}

void Bouton()
{
  pinMode(INPUT1, INPUT_PULLUP);
  pinMode(INPUT2, INPUT_PULLUP);
  pinMode(INPUT3, INPUT_PULLUP);

  if(!digitalRead(INPUT1))
  {
    input1++;
    if(input1>=LONG_PRESS)
    {
      input1 = LONG_PRESS;
      keepLeft = true;
    }
      
  }
  else
  {
    keepLeft = false;
    if(input1>=LONG_PRESS)
      buttonLeft = LONG_PRESS;
    else if(input1)
      buttonLeft = SHORT_PRESS;
    input1 = 0;
  }
  if(!digitalRead(INPUT2))
  {
    input2++;
    if(input2>=LONG_PRESS)
    {
      input2 = LONG_PRESS;
      keepMiddle = true;
    }
  }
  else
  {
    keepMiddle = false;
    if(input2>=LONG_PRESS)
      buttonMiddle = LONG_PRESS;
    else if(input2)
      buttonMiddle = SHORT_PRESS;
    input2 = 0;
  }
  if(!digitalRead(INPUT3))
  {
    input3++;
    if(input3>=LONG_PRESS)
    {
      input3 = LONG_PRESS;
      keepRight = true;
    }
  }
  else
  {
    keepRight = false;
    if(input3>=LONG_PRESS)
      buttonRight = LONG_PRESS;
    else if(input3)
      buttonRight = SHORT_PRESS;
    input3 = 0;
  }

  pinMode(INPUT1, INPUT);
  pinMode(INPUT2, INPUT);
  pinMode(INPUT3, INPUT);
}

