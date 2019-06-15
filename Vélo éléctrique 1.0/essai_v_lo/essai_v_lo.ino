int var = 10;
int sept = 0;
int cinq = 0;
int six = 0;
int dim = 500;
int i = 0;


void setup() {
  Serial.begin(115200);

}

void loop() 
{
  //allume les 4 leds les une a la suite
  BoucleLed(var);
  Bouton();
    

  delay(1);
}

void Bouton()
{
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);

  if(!digitalRead(7))
  {
    sept = 1;
  }
  else
    {
      if(sept)
      {
        var++;
        sept = 0;
      }
    }
    if(!digitalRead(5))
  {
    cinq = 1;
  }
  else
    {
      if(cinq)
      {
        dim*=1.5;
        if(dim>950)
          dim=50;
        cinq = 0;
      }
    }
    if(!digitalRead(6))
  {
    six = 1;
  }
  else
    {
      if(six)
      {
        var=0;
        six = 0;
      }
    }

  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
}

void BoucleLed(int leds)
{
  if(leds<10)
    delay(10-leds);
  switch(leds)
  {
    case 10:
      Led10();
      leds--;
    case 9:
      Led9();
      leds--;
    case 8:
      Led8();
      leds--;
    case 7:
      Led7();
      leds--;
    case 6:
      Led6();
      leds--;
    case 5:
      Led5();
      leds--;
    case 4:
      Led4();
      leds--;
    case 3:
      Led3();
      leds--;
    case 2:
      Led2();
      leds--;
    case 1:
      Led1();
      leds--;
    break;
    default:
    break;
  }
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void Led1()
{
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    delayMicroseconds(dim);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    delayMicroseconds(1000-dim);
}
void Led2()
{
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    delayMicroseconds(dim);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    delayMicroseconds(1000-dim);
}
void Led3()
{
    digitalWrite(4, LOW);
    digitalWrite(6, HIGH);
    pinMode(4, OUTPUT);
    pinMode(6, OUTPUT);
    delayMicroseconds(dim);
    pinMode(4, INPUT);
    pinMode(6, INPUT);
    delayMicroseconds(1000-dim);
}
void Led4()
{
    digitalWrite(4, HIGH);
    digitalWrite(6, LOW);
    pinMode(4, OUTPUT);
    pinMode(6, OUTPUT);
    delayMicroseconds(dim);
    pinMode(4, INPUT);
    pinMode(6, INPUT);
    delayMicroseconds(1000-dim);
}
void Led5()
{
    digitalWrite(4, LOW);
    digitalWrite(7, HIGH);
    pinMode(4, OUTPUT);
    pinMode(7, OUTPUT);
    delayMicroseconds(dim);
    pinMode(4, INPUT);
    pinMode(7, INPUT);
    delayMicroseconds(1000-dim);
}
void Led6()
{
    digitalWrite(4, HIGH);
    digitalWrite(7, LOW);
    pinMode(4, OUTPUT);
    pinMode(7, OUTPUT);
    delayMicroseconds(dim);
    pinMode(4, INPUT);
    pinMode(7, INPUT);
    delayMicroseconds(1000-dim);
}
void Led7()
{
    digitalWrite(5, LOW);
    digitalWrite(7, HIGH);
    pinMode(5, OUTPUT);
    pinMode(7, OUTPUT);
    delayMicroseconds(dim);
    pinMode(5, INPUT);
    pinMode(7, INPUT);
    delayMicroseconds(1000-dim);
}
void Led8()
{
    digitalWrite(5, HIGH);
    digitalWrite(7, LOW);
    pinMode(5, OUTPUT);
    pinMode(7, OUTPUT);
    delayMicroseconds(dim);
    pinMode(5, INPUT);
    pinMode(7, INPUT);
    delayMicroseconds(1000-dim);
}
void Led9()
{
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    delayMicroseconds(dim);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    delayMicroseconds(1000-dim);
}
void Led10()
{
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    delayMicroseconds(dim);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    delayMicroseconds(1000-dim);
}


