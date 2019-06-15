#define C_GAUCHE 0b100
#define PHARE    0b010
#define C_DROIT  0b001

#define OUTPUT_LEFT 8
#define OUTPUT_RIGHT 9
#define OUTPUT_PHARE 10


byte turnLeft = 0, turnRight = 0, veilleuse = 0, detresse = 0;
extern enum Menu monMenu;
int valid = 0;
int delaisClignotant = 0;
boolean clignotantOn = false;
byte eclairage = 0;  //0b010 = phare , 0b100 = clignotant gauche, 0b001 = clignotant droit -->

void SetLights()
{
  delaisClignotant++;
  digitalWrite(OUTPUT_PHARE, veilleuse);
  eclairage = (eclairage & 0b11111101) | veilleuse;
  if(!(delaisClignotant%8))
  {
    if(clignotantOn)
    {
      clignotantOn = false;
      digitalWrite(OUTPUT_LEFT, LOW);
      digitalWrite(OUTPUT_RIGHT, LOW);
      eclairage = (eclairage & 0b11111000) | veilleuse;
    }
    else
    {
      clignotantOn = true;
      digitalWrite(OUTPUT_LEFT, turnLeft);
      digitalWrite(OUTPUT_RIGHT, turnRight);
      eclairage = (eclairage & 0b11111000) | turnLeft | turnRight | veilleuse;
    }
  }
}

void CommandButton()
{
  if(monMenu == EXIT)
  {
    if(buttonLeft)//on ignore si l'appuit est long ou court
    {
      AfficheCommand("Turn left");
      buttonLeft = OFF;
      clignotantOn = false;
      delaisClignotant = 7;
      turnLeft ^= C_GAUCHE; //toggle turnLeft
      turnRight = 0; //shutdown turnRight
    }
    if(buttonRight)//on ignore si l'appuit est long ou court
    {
      AfficheCommand("Turn right");
      buttonRight = OFF;
      clignotantOn = false;
      delaisClignotant = 7;
      turnRight ^= C_DROIT; //toggle turnRight
      turnLeft = 0; //shutdown turnLeft
    } 
    if(buttonMiddle==SHORT_PRESS)
    {
      AfficheCommand("Toggle light");
      buttonMiddle = OFF;
      veilleuse ^= PHARE; //toggle phare
    } 
    if(buttonMiddle==LONG_PRESS && vitesse)
    {
      AfficheCommand("Toggle warning");
      buttonMiddle = OFF;
      clignotantOn = false;
      delaisClignotant = 7;
      if(turnRight && turnLeft)
        turnRight = turnLeft = 0;
      else
      {
        turnRight = C_DROIT;
        turnLeft = C_GAUCHE; //toggle detresse
      }
      
      
    } 
    if(buttonMiddle==LONG_PRESS && !vitesse)//un appuit long a vitesse nul fait entrer dans le menu
    {
      buttonMiddle = OFF;
      monMenu = PRINCIPALE;
    } 
  }
}











