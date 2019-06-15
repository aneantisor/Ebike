#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans18pt7b.h>
#include <EEPROM.h>
//la taille des lettres de base est de 8pixel de hauteur par 6 de largeur espace inclus
#define HAUTEUR_BASE 8
#define LARGEUR_BASE 6
#define DIM_ADR 0

boolean odo = true;
boolean watt = true;

enum Menu
{
  EXIT,
  PRINCIPALE, 
  DISTANCE_PAR_TOUR, 
  MAG_ROUE, 
  MAG_PEDALE,
  DIM
};

extern int erreur;
extern int dim;
enum Menu monMenu = EXIT;


void InitOled()
{
  EEPROM.get(DIM_ADR, dim);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(0);
  display.setTextColor(WHITE);
  display.setFont(&FreeSans9pt7b);
  display.dim(!(dim-100));
  display.clearDisplay();
}

void DimPlus()
{
  dim += 100;
  if(dim > 900)
    dim = 900;
  EEPROM.put(DIM_ADR, dim);
  display.dim(!(dim-100));
}

void DimMoins()
{
  dim -= 100;
  if(dim < 100)
    dim = 100;
  EEPROM.put(DIM_ADR, dim);
  display.dim(!(dim-100));
}

uint8_t SmartCursorSet(int32_t var)
{
  return (5 * NumberOfDigit(var));
}

uint8_t FloatCursorSet(float var)
{
  return (5 * NumberOfFloat(var));
}

void OledVitesse()
{
    display.setFont(&FreeSans18pt7b);
    display.setTextSize(1);
    display.setCursor(0,30);
    display.println(vitesse);
    display.setFont();
    display.setTextSize(1);
    display.setCursor(10*NumberOfDigit(vitesse),32-HAUTEUR_BASE);
    display.println("km/h");
}

void OledBottomRight()
{
  display.setFont(&FreeSans9pt7b);
  display.setTextSize(1);
  if(watt)
  {
    display.setCursor(120 - SmartCursorSet(puissance),30);
    display.print(puissance);
    display.setFont();
    display.setCursor(128-1*LARGEUR_BASE,32-HAUTEUR_BASE);
    display.println("w");
  }
  else
  {
    display.setCursor(100 - SmartCursorSet(puissance),30);
    display.print(vitesseMoyenne);
    display.setFont();
    display.setCursor(128-4*LARGEUR_BASE,32-HAUTEUR_BASE);
    display.println("km/h");
  }
}

void OledTopRight()
{
  display.setFont(&FreeSans9pt7b);
  display.setTextSize(1);
  if(odo)
  {
    display.setCursor(128 - 4*LARGEUR_BASE - FloatCursorSet(odometre),14);
    display.print((float)odometre/10.0,1);
    display.setFont();
    display.setCursor(128-3*LARGEUR_BASE,8-HAUTEUR_BASE);
    display.println("odo");
    display.setCursor(128-3*LARGEUR_BASE,16-HAUTEUR_BASE);
    display.println("km");
  }
  else
  {
    display.setCursor(128 - 5*LARGEUR_BASE - FloatCursorSet(trip),14);
    display.print((float)(trip/10.0),1);
    display.setFont();
    display.setCursor(128-4*LARGEUR_BASE,8-HAUTEUR_BASE);
    display.println("trip");
    display.setCursor(128-4*LARGEUR_BASE,16-HAUTEUR_BASE);
    display.println("km");
  }
  
}

void AfficheCommand(char *chaine)
{
  display.clearDisplay();
  display.setFont(&FreeSans9pt7b);
  display.setTextSize(1);
  display.setCursor(0,22);
  display.print(chaine);
  display.display();
}

void OledRefresh()
{
  display.clearDisplay();
  if(monMenu != EXIT)
  {
    GestionDuMenu();
  }
    
  else
  {
    OledVitesse();
    OledBottomRight();
    OledTopRight();
  }
    display.display();
  //}
  
}

