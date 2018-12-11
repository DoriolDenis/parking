#include <Arduino.h>
#include <wire.h>
#include "fonction.h"

int lectureBav()
{
  int valeurBit;
  Wire.beginTransmission(MECANISME);
  Wire.write(0xF8);
  Wire.endTransmission(MECANISME);
  Wire.requestFrom(MECANISME, 1);
  if (Wire.available())
  {
    valeurBit = Wire.read();
    valeurBit = bitRead(valeurBit, 6);
    Serial.print("AVAL :");
    Serial.println(valeurBit);
  }
  return valeurBit;
}

int lectureBam()
{
  int valeurBit;
  Wire.beginTransmission(MECANISME);
  Wire.write(0xF8);
  Wire.endTransmission(MECANISME);
  Wire.requestFrom(MECANISME, 1);
  if (Wire.available())
  {
    valeurBit = Wire.read();
    valeurBit = bitRead(valeurBit, 5);
    Serial.print("AMONT :");
    Serial.println(valeurBit);
  }
  return valeurBit;
}


void ouvrir()
{
  Wire.beginTransmission(MECANISME);  //Debut de transmission avec MECANISME
  Wire.write(OUVRIR); //Octet pour ouvrir barriere
  Serial.print("Ouvrir\n");
  Wire.endTransmission(MECANISME);  //Fin de transmission avec MECANISME
}

void fermer()
{
  Wire.beginTransmission(MECANISME);
  Wire.write(FERMER);
  Serial.print("Fermer\n");
  Wire.endTransmission(MECANISME);
}

unsigned char detecterCarte()
{
  unsigned char valBit;
  Wire.beginTransmission(AUXILIAIRE);
  Wire.write(0xF1);
  Wire.endTransmission(AUXILIAIRE);
  Wire.requestFrom(AUXILIAIRE, 1);
  if (Wire.available())
  {
    valBit = Wire.read();
    valBit = bitRead(valBit, 0);
  }
  return valBit;
}

unsigned char activerBus()
{
  Wire.beginTransmission(AUXILIAIRE);
  Wire.write(0xF2);
  Wire.endTransmission(AUXILIAIRE);
}

unsigned char desactiverBus()
{
  Wire.beginTransmission(AUXILIAIRE);
  Wire.write(0xF1);
  Wire.endTransmission(AUXILIAIRE);
}

unsigned char lectureCarte()
{
  unsigned char valeurCarte;
  Wire.requestFrom(0x50, 5);
  while (Wire.available())
  {
    valeurCarte = Wire.read();
    Serial.print("CODE :");
    Serial.println(valeurCarte);
  }
  return valeurCarte;
}

int lectureClavier()
{

  int colonne, ligne;
  Wire.beginTransmission(0x22);
  Wire.write(0x0F);
  Wire.endTransmission();
  Wire.requestFrom(0x22, 1);

  while (Wire.available())
  {
    colonne = Wire.read();
    //Serial.print("Affiche la colonne : ");
    //Serial.println(colonne);
  }
  if (colonne != 240)
  {
    Wire.beginTransmission(0x22);
    Wire.write(0xF0);
    Wire.endTransmission();
    Wire.requestFrom(0x22, 1);
 
  while (Wire.available())
  {
    ligne = Wire.read();
    // Serial.print("Affiche la ligne");
    // Serial.println(ligne);
  }

  return colonne+ligne;

  
 }
}

char convertiseurClavier()
{
  int c=lectureClavier();
  char touchesClavier;
  
  
  switch (c)
  {
    case 215 :
    touchesClavier='0';
    Serial.print("Le nombre est : ");
    Serial.println(touchesClavier);
      break;
          case 238 :
    touchesClavier='1';
    Serial.print("Le nombre est : ");
    Serial.println(touchesClavier);
      break;
          case 222 :
    touchesClavier='2';
    Serial.print("Le nombre est : ");
    Serial.println(touchesClavier);
      break;
          case 190 :
    touchesClavier='3';
    Serial.print("Le nombre est : ");
    Serial.println(touchesClavier);
      break;
          case 237 :
    touchesClavier='4';
    Serial.print("Le nombre est : ");
    Serial.println(touchesClavier);
      break;
          case 221 :
    touchesClavier='5';
    Serial.print("Le ombre est : ");
    Serial.println(touchesClavier);
      break;
          case 189 :
    touchesClavier='6';
    Serial.print("Le nombre est : ");
    Serial.println(touchesClavier);
      break;
          case 235 :
    touchesClavier='7';
    Serial.print("Le nombre est : ");
    Serial.println(touchesClavier);
      break;
          case 219 :
    touchesClavier='8';
    Serial.print("Le nombre est : ");
    Serial.println(touchesClavier);
      break;
          case 187 :
    touchesClavier='9';
    Serial.print("Le nombre est : ");
    Serial.println(touchesClavier);
      break;
          case 183 :
    touchesClavier='#';
    Serial.print("Le nombre est : ");
    Serial.println(touchesClavier);
      break;
          case 231 :
    touchesClavier='*';
    Serial.print("Le nombre est : ");
    Serial.println(touchesClavier);
      break;

  }

  
}
