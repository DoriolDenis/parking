#include <EEPROM.h>
#include <LiquidCrystal.h>
#include "i2c.h"
#include <Wire.h>
void activerAffichage (int adresse);
void setup() {
  // put your setup code here, to run once:
  #define Transmission
  #define Afficheur
  #define Commande

  void activerAffichage (int adresse)
  {
    int i;
    envoyerCommande(adress,0x20);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
