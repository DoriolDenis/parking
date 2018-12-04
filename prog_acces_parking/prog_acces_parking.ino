#include <Wire.h>
#include "fonction.h"
#include "i2c.h"

void setup() {

  Serial.begin(9600);
  Wire.begin();
  initI2C(255);
  Wire.beginTransmission(MECANISME);
  fermer();
  Wire.endTransmission(MECANISME);

}

void loop() {
  //Entrer d'un vehicule
  if ((lectureBam() == BOUCLEAMONT) && (lectureBav() != BOUCLEAVAL))
  {
    Serial.print("Entrer carte valide ou saisi code");
    if (carteValide() == CARTEAPUCE)
    {
      ouvrir();
      delay(500);} }
      /*while ((lectureBav() == BOUCLEAVAL) && (lectureBam() == BOUCLEAMONT));
      if ((lectureBav() == BOUCLEAVAL) || (lectureBam() == BOUCLEAMONT))
      {
        while ((lectureBav() == BOUCLEAVAL) || (lectureBam() == BOUCLEAMONT));
      }
      fermer();
   
  */
  /*else
    {
    while (lectureBam() == BOUCLEAMONT)
    {
      Serial.print("Code ou carte invalide, veuillez quitter l'entree");

    }
    }

    else
    {
    if(lectureClavier == 1)
    {
    ouvrir();
    }
    else
    {
    while(lectureBam == BOUCLEAMONT)
    {
      Serial.print("Code ou carte invalide, veuillez quitter l'entree")
    }

    }
    }*/


  /*Sortie d'un vehicule */
  Wire.beginTransmission(MECANISME);
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

  /* Test Clavier */
  /*int code;
    Wire.beginTransmission(0x38);
    Wire.write(0x0F);
    Wire.endTransmission(0x38);
    Wire.requestFrom(0x38, 1);
    if (Wire.available())
    {
    code = Wire.read();
    Serial.print("CODE :");
    Serial.println(code, BIN);
    }*/
}
