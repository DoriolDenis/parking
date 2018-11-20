#include "fonction.h"
#include <Wire.h>
#include "i2c.h"

void setup() {
  Serial.begin(9600);           /// Demarrage de la liaison serie
  Wire.beginTransmission(0x20);
  Wire.write(0xFE);
  Wire.endTransmission();
  /******* Bus I2C *******/
  Wire.begin();
  initI2C(200);
}

void loop() {
  //int nombreVoiture = 0;
  if (lectureBav() == 1 && lectureBam == 0) {
    ouvrir();
    while (lectureBav() == 1 && lectureBam() == 0);
    if (lectureBav() == 1 || lectureBam() == 1) {
      while (lectureBav == 1 || lectureBam == 1);
      /*nombreVoiture--;
        Serial.print("il y a dans le parking : ");
        Serial.print(nombreVoiture);
        Serial.print(" voiture(s)");*/
    }
    fermer();
  }
}
// Fin du programme
