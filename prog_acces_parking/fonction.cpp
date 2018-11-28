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
  Wire.endTransmission(MECANISME);  //Fin de transmission avec MECANISME
}

void fermer()
{
  Wire.beginTransmission(MECANISME);
  Wire.write(FERMER);
  Wire.endTransmission(MECANISME);
}
