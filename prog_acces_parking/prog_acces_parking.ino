#include "fonction.h"
#include <Wire.h>
#include "i2c.h"


#define MECANISME 0x20    //0 0 1 0 0 0 0 0  
#define AUXILIAIRE 0x21   //0 0 1 0 0 0 0 1
#define CLAVIER 0x22      //0 0 1 0 0 0 1 0


void setup() {

Serial.begin(9600);   /// Demarrage de la liaison serie
pinMode (BOUCLEAMONT,INPUT);  /// Detection voiture en entree
pinMode (BOUCLEAVAL,INPUT);  /// Detection voiture en sortie
pinMode (VALIDATION,INPUT);  /// Detection voiture en entree

/******* Bus I2C *******/

initI2C(122);
Wire.beginTransmission(0x20);
Wire.write(0xFD);
Wire.endTransmission(MECANISME);
delay(1000);
Wire.beginTransmission(0x20);
Wire.write(0xFE);
Wire.endTransmission(MECANISME);
delay(1000);
}

void loop() {

int tempo = 0, testTempo;   /// tempo permettra d'attendre les 30 secondes en entree
static int nombreVoiture = 0;     /// Variable static permettant de compter le nombre de vehicule dans le parking 

/******* Gestion de l'entree d'un vehicule *******/

if (digitalRead(BOUCLEAMONT) == 1 && digitalRead(BOUCLEAVAL) == 0){   /// arrivee d'une voiture en entre du parking
  if(digitalRead(VALIDATION) == 1) {    /// Si le code est valide
    testTempo = 1;
    tempo;
    commandeBarriere(OUVRIR,2);   /// Ouverture de la barriere 
    while (digitalRead(BOUCLEAMONT) == 1 && digitalRead(BOUCLEAVAL) == 0 && testTempo == 1)
    {
      delay(30);
      tempo++;    /// Incrementation toute les 30ms pour simuler l'attentede 30 secondes 
      if(tempo == 1000){
        testTempo = 0;    /// Le delay de 30 secondes est atteint 
      }
    }
    delay(20);    /// Evite une mauvaise lecture du if suivant si jamais il y a un rebond de l'inter bav
    if (digitalRead(BOUCLEAMONT) == 0 || digitalRead(BOUCLEAVAL) == 1){
      if(digitalRead(BOUCLEAMONT) == 1){
        while (digitalRead(BOUCLEAMONT) == 1 || digitalRead(BOUCLEAVAL) == 1);    /// On attend que le vehicule quitte les boucles
        nombreVoiture++;
        Serial.print("Il y a dans le parking : ");
        Serial.print(nombreVoiture);
        Serial.print(" voiture(s)");
      }
    }
    commandeBarriere(FERMER,2);
  }
}

/******* Gestion de la sortie d'un vehicule *******/

/// On ne decremente que si la voiture traverse les deux deux boucles
if (digitalRead(BOUCLEAVAL) == 1 && digitalRead(BOUCLEAMONT) == 0){
  commandeBarriere(OUVRIR, 2);
  while (digitalRead(BOUCLEAVAL) == 1 && digitalRead(BOUCLEAMONT) == 0);    /// On attend que le vehicule bouge
  if(digitalRead(BOUCLEAVAL) == 1 || digitalRead(BOUCLEAMONT) == 1){
    while (digitalRead(BOUCLEAVAL) == 1 || digitalRead(BOUCLEAMONT) == 1);    /// On attend que le vehicule soit parti
    nombreVoiture--;
    Serial.print("Il y a le parking : ");
    Serial.print(nombreVoiture);
    Serial.print(" voiture(s)");
  }
  commandeBarriere(FERMER, 2);
}
/// Fin du programme de sortie d'un vehicule
}
/// Fin du programme
