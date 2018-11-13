#include "fonction.h"
#include <Wire.h>
#include "i2c.h"

void setup() {

Serial.begin(9600);           /// Demarrage de la liaison serie
pinMode (BOUCLEAMONT,INPUT);  /// Detection voiture en entree
pinMode (BOUCLEAVAL,INPUT);   /// Detection voiture en sortie
pinMode (VALIDATION,INPUT);   /// Detection voiture en entree

/******* Bus I2C *******/

initI2C(122);

}

void loop() {

int tempo = 0, testTempo;         /// tempo permettra d'attendre les 30 secondes en entree
static int nombreVoiture = 0;     /// Variable static permettant de compter le nombre de vehicule dans le parking 

///Serial.println("Salut beaute");
Wire.requestFrom(MECANISME,1);
  while(Wire.available()){
    int i;
    i=Wire.read();
    Serial.println(i);
  }
/******* Gestion de l'entree d'un vehicule *******/

if (digitalRead(BOUCLEAMONT) == 198 && digitalRead(BOUCLEAVAL) == 230){     /// arrivee d'une voiture en entre du parking
  ///if(digitalRead(VALIDATION) == 1) {   /// Si le code est valide
  
  /*Wire.beginTransmission(0x20);
  Wire.write(0xFD);   /// Ouvrir
  Wire.endTransmission(MECANISME); */ 
  commandeBarriere(OUVRIR,2);                                 
    testTempo = 1;
    tempo;                                                                /// Ouverture de la barriere 
    while (digitalRead(BOUCLEAMONT) == 198 && digitalRead(BOUCLEAVAL) == 230 && testTempo == 1)
    {
      delay(30);
      tempo++;                          /// Incrementation toute les 30ms pour simuler l'attentede 30 secondes 
      if(tempo == 1000){
        testTempo = 0;                  /// Le delay de 30 secondes est atteint 
      }
    }
  
    delay(20);                          /// Evite une mauvaise lecture du if suivant si jamais il y a un rebond de l'inter bav
    if (digitalRead(BOUCLEAMONT) == 230 || digitalRead(BOUCLEAVAL) == 198){
      if(digitalRead(BOUCLEAMONT) == 198){
        while (digitalRead(BOUCLEAMONT) == 198 || digitalRead(BOUCLEAVAL) == 198);          /// On attend que le vehicule quitte les boucles
        nombreVoiture++;
        Serial.println("Il y a dans le parking : ");
        Serial.println(nombreVoiture);
        Serial.println(" voiture(s)");
      }
    }
 /* Wire.beginTransmission(0x20);
  Wire.write(0xFE);   /// Fermer
  Wire.endTransmission(MECANISME);*/
  commandeBarriere(FERMER,2);
  
  }
///}

/******* Gestion de la sortie d'un vehicule *******/

/// On ne decremente que si la voiture traverse les deux deux boucles
if (digitalRead(BOUCLEAVAL) == 166 && digitalRead(BOUCLEAMONT) == 230){
 /// Serial.println("Une voiture veut sortir");
  
   /*Wire.beginTransmission(0x20);
  Wire.write(0xFD);   /// Ouvrir
  Wire.endTransmission(MECANISME);*/
  commandeBarriere(OUVRIR, 2);
  
  while (digitalRead(BOUCLEAVAL) == 166 && digitalRead(BOUCLEAMONT) == 230);            /// On attend que le vehicule bouge
  if(digitalRead(BOUCLEAVAL) == 166 || digitalRead(BOUCLEAMONT) == 198){
    ///Serial.println("Une voiture sur une des deux boucles");
    while (digitalRead(BOUCLEAVAL) == 166 || digitalRead(BOUCLEAMONT) == 198);          /// On attend que le vehicule soit parti
    nombreVoiture --;
    Serial.println("Il y a le parking : ");
    Serial.println(nombreVoiture);
    Serial.println(" voiture(s)");
  }
  
   /*Wire.beginTransmission(0x20);
  Wire.write(0xFE);   /// Fermer
  Wire.endTransmission(MECANISME);*/
  commandeBarriere(FERMER, 2);
}
/// Fin du programme de sortie d'un vehicule
}
/// Fin du programme
