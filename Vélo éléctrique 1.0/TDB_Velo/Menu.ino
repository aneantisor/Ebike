

extern enum Menu monMenu;
int choix = 0;
extern boolean odo;
extern boolean watt;

extern byte distanceParTour;
extern byte nbreMagRoue;
extern byte nbreMagPedale;
extern int dim;

//#define C_GAUCHE 0b100
//#define PHARE    0b010
//#define C_DROIT  0b001
//Les 3 bits de droit servent déjà pour léclairage
#define SET_DIST_TOUR_MASK  0b00001000
#define SET_MAG_ROUE_MASK   0b00010000
#define SET_MAG_PEDALE_MASK 0b00100000
#define SET_TRIP_MASK       0b01000000

void GestionDuMenu()
{
  switch(monMenu)
  {
    case PRINCIPALE:
      AfficheMenu();
      break;
    case DISTANCE_PAR_TOUR:
      MenuReglage();
      break;
    case MAG_ROUE:
      MenuReglage();
      break;
    case MAG_PEDALE:
      MenuReglage();
      break;
    case DIM:
      MenuReglage();
      break;  
    default :
      break;  
  }
}

void AfficheMenu()
{
  display.setFont();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("MENU   ");
  if(choix < 4)
  {
    if(choix==0)display.print("->");
    display.println("Exit");
    if(choix==1)display.print("->");
    display.println("reset trip");
    if(choix==2)display.print("->");
    display.println("switch odo trip");
    if(choix==3)display.print("->");
    display.println("switch watt avg");
  }
  else if(choix < 8)
  {
    if(choix==4)display.print("->");
    display.println("dist/tour");
    if(choix==5)display.print("->");
    display.println("nbre mag roue");
    if(choix==6)display.print("->");
    display.println("nbre mag pedale");
    if(choix==7)display.print("->");
    display.print("batterie : ");
    display.print(batterie);
    display.println("%");
  }
  else if(choix < 12)
  {
    if(choix==8)display.print("->");
    display.println("dim");
    if(choix==9)display.print("->");
    display.println("not implemented");
    if(choix==10)display.print("->");
    display.println("not implemented");
    if(choix==11)display.print("->");
    display.print("not implemented");
  }
  if(buttonLeft)//on ignore si l'appuit est long ou court
    {
      buttonLeft = OFF;
      choix--;
      if(choix<0)
        choix = 0;
    }
  if(buttonRight)//on ignore si l'appuit est long ou court
    {
      buttonRight = OFF;
      choix++;
      if(choix>12)
        choix = 12;
    } 
  if(buttonMiddle==SHORT_PRESS)
    {
      buttonMiddle = OFF;
      SwitchMenu();
    } 
  if(buttonMiddle==LONG_PRESS || vitesse)
    {
      buttonMiddle = OFF;
      monMenu = EXIT;
    } 
}

void SwitchMenu()
{
  switch (choix)
  {
    case 0:
      monMenu = EXIT;
      break;
    case 1:
      ResetTrip();
      choix = 0;
      break;
    case 2:
      SwitchOdoTrip();
      choix = 0;
      break;
    case 3:
      SwitchWattSpeed();
      choix = 0;
      break;
    case 4:
      monMenu = DISTANCE_PAR_TOUR;
      choix = distanceParTour;
      break;
    case 5:
      monMenu = MAG_ROUE;
      choix = nbreMagRoue;
      break;
    case 6:
      monMenu = MAG_PEDALE;
      choix = nbreMagPedale;
      break; 
    case 8:
      monMenu = DIM;
      choix = dim;
      break;   
    default:
      break;  
      
  }
  
}

void MenuReglage()
{
  byte mask;
  display.setFont();
  display.setTextSize(1);
  display.setCursor(0,0);
  if(monMenu == DISTANCE_PAR_TOUR)
  {
    mask = SET_DIST_TOUR_MASK;
    display.println("Distance par tour");
    display.print("Actuel : ");
    display.println(distanceParTour);
  }
  else if(monMenu == MAG_ROUE)
  {
    mask = SET_MAG_ROUE_MASK;
    display.println("Nbre mag roue");
    display.print("Actuel : ");
    display.println(nbreMagRoue);
  }
  else if(monMenu == MAG_PEDALE)
  {
    mask = SET_MAG_PEDALE_MASK;
    display.println("Nbre mag pedale");
    display.print("Actuel : ");
    display.println(nbreMagPedale);
  }
  else if(monMenu == DIM)
  {
    display.print("Dim : ");
    display.println(dim);
  }
  if(monMenu != DIM)
  {
    display.print("Voulue : ");
    display.println(choix);
    display.println("long press -> Save");
  }
  
  
  
  if(buttonLeft)//on ignore si l'appuit est long ou court
    {
      buttonLeft = OFF;
      if(monMenu == DIM)
        DimMoins();
      else
        choix--;
    }
  else if(keepLeft) 
    {
       choix--;
    }
  if(buttonRight)//on ignore si l'appuit est long ou court
    {
      buttonRight = OFF;
      if(monMenu == DIM)
        DimPlus();
      else  
        choix++;
    } 
  else if(keepRight) 
    {
       choix++;
    }
  if(buttonMiddle==SHORT_PRESS)
    {
      buttonMiddle = OFF;
      choix = 0;
      monMenu = EXIT;
    } 
  if(buttonMiddle==LONG_PRESS)
    {
      buttonMiddle = OFF;
      if(monMenu == DIM);
      else
        SendCommandToHost(mask, choix);
      choix = 0;
      monMenu = PRINCIPALE;
      //Save value
    } 
}




void ResetTrip()
{
  SendCommandToHost(SET_TRIP_MASK, 0);
  AfficheCommand("Trip reseted");
  delay(500);
}

void SwitchOdoTrip()
{
  if(odo)
    AfficheCommand("Set to trip");
  else
    AfficheCommand("Set to odo");
  odo ^= true;
  delay(500); 
}

void SwitchWattSpeed()
{
  if(watt)
    AfficheCommand("AVG Speed");
  else
    AfficheCommand("Instant power");
  watt ^= true;
  delay(500); 
}





