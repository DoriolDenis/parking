#include <Wire.h>
#include "fonction.h"
#include "i2c.h"

void setup() {

  Serial.begin(9600);
  Wire.begin();
  initI2C(255);


}

void loop() {

  Wire.beginTransmission(MECANISME);
  Wire.beginTransmission(AUXILIAIRE);
  if ((lectureBam() == BOUCLEAMONT) && (lectureBav() != BOUCLEAVAL))
  {

    while (detecterCarte() == CARTE)
    {
      for (int i; i <= 5; i++)
      {
        activerBus();
        lectureCarte();
        desactiverBus();
      }
      {
        Serial.println("Carte OK");
        ouvrir();
        delay(3000);
        while ((lectureBav() == BOUCLEAVAL) && (lectureBam() == BOUCLEAMONT));
        if ((lectureBav() == BOUCLEAVAL) || (lectureBam() == BOUCLEAMONT))
        {
          while ((lectureBav() == BOUCLEAVAL) || (lectureBam() == BOUCLEAMONT));
        }
      }
    }
    Serial.println("Pas de carte");
    fermer();
    delay(30000);

    desactiverBus();
  }

  if ((lectureBav() == BOUCLEAVAL) && (lectureBam() != BOUCLEAMONT))
  {
    ouvrir();
    delay(500);
    while ((lectureBav() == BOUCLEAVAL) && (lectureBam() == BOUCLEAMONT));
    if ((lectureBav() == BOUCLEAVAL) || (lectureBam() == BOUCLEAMONT))
    {
      while ((lectureBav() == BOUCLEAVAL) || (lectureBam() == BOUCLEAMONT));
    }
    fermer();
    delay(500);
  }
  Wire.endTransmission(MECANISME);
  Wire.endTransmission(AUXILIAIRE);
}
