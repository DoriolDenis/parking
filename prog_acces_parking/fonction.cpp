#include "fonction.h"       // Permet de recuperer le prototype des fonctions ainsi que les differentes constantes
#include "arduino.h"        // a ne mettre que si l'on utilise un fichier separee
#include <Wire.h>

void ouvrir()
{
    Wire.beginTransmission(0x20);
    Wire.write(0xFD);
    Wire.endTransmission();
}

void fermer()
{
    Wire.beginTransmission(0x20);
    Wire.write(0xFE);
    Wire.endTransmission();
}


unsigned char lectureBam()
{
  Wire.requestFrom(0x20, 1);
  unsigned char a = Wire.read();
  
  Serial.println(a, DEC);
  return a;

}

unsigned char lectureBav()
{
  Wire.requestFrom(0x20, 1);
  unsigned char a = Wire.read();
  
  Serial.println(a, DEC);
  return a;
}
