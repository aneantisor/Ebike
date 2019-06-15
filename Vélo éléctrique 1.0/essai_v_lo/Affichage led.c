int dim = 50;

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
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
}

void changeDim()
{
  dim*=1.5;
    if(dim>950)
      dim=50;
}

void Led1()
{
    digitalWrite(4, 0);
    digitalWrite(5, 1);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    delayMicroseconds(dim);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    delayMicroseconds(1000-dim);
}
void Led2()
{
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    delayMicroseconds(dim);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    delayMicroseconds(1000-dim);
}
void Led3()
{
    digitalWrite(4, 0);
    digitalWrite(6, 1);
    pinMode(4, OUTPUT);
    pinMode(6, OUTPUT);
    delayMicroseconds(dim);
    pinMode(4, INPUT);
    pinMode(6, INPUT);
    delayMicroseconds(1000-dim);
}
void Led4()
{
    digitalWrite(4, 1);
    digitalWrite(6, 0);
    pinMode(4, OUTPUT);
    pinMode(6, OUTPUT);
    delayMicroseconds(dim);
    pinMode(4, INPUT);
    pinMode(6, INPUT);
    delayMicroseconds(1000-dim);
}
void Led5()
{
    digitalWrite(4, 0);
    digitalWrite(7, 1);
    pinMode(4, OUTPUT);
    pinMode(7, OUTPUT);
    delayMicroseconds(dim);
    pinMode(4, INPUT);
    pinMode(7, INPUT);
    delayMicroseconds(1000-dim);
}
void Led6()
{
    digitalWrite(4, 1);
    digitalWrite(7, 0);
    pinMode(4, OUTPUT);
    pinMode(7, OUTPUT);
    delayMicroseconds(dim);
    pinMode(4, INPUT);
    pinMode(7, INPUT);
    delayMicroseconds(1000-dim);
}
void Led7()
{
    digitalWrite(5, 0);
    digitalWrite(7, 1);
    pinMode(5, OUTPUT);
    pinMode(7, OUTPUT);
    delayMicroseconds(dim);
    pinMode(5, INPUT);
    pinMode(7, INPUT);
    delayMicroseconds(1000-dim);
}
void Led8()
{
    digitalWrite(5, 1);
    digitalWrite(7, 0);
    pinMode(5, OUTPUT);
    pinMode(7, OUTPUT);
    delayMicroseconds(dim);
    pinMode(5, INPUT);
    pinMode(7, INPUT);
    delayMicroseconds(1000-dim);
}
void Led9()
{
    digitalWrite(6, 0);
    digitalWrite(7, 1);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    delayMicroseconds(dim);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    delayMicroseconds(1000-dim);
}
void Led10()
{
    digitalWrite(6, 1);
    digitalWrite(7, 0);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    delayMicroseconds(dim);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    delayMicroseconds(1000-dim);
}
