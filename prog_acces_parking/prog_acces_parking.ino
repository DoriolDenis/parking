#include <Wire.h>
#include "fonction.h"
#include "i2c.h"

void setup() {

  Serial.begin(1200);
  Wire.begin();
  initI2C(255);



}

void loop() {

  Wire.beginTransmission(MECANISME);
  Wire.beginTransmission(AUXILIAIRE);
  unsigned int nombreVoiture = 0; //initialisation du nombre de voiture dans le parking a 0
  int essaiCode = 0;  //initialisation du nombre d'essai au clavier a 0
  if ((lectureBam() == BOUCLEAMONT) && (lectureBav() != BOUCLEAVAL))//Si il y a une voiture sur la boucle amont
  {                                                                 //Alors on demande de rentrer une carte ou un code valide
    Serial.println(" Entrez carte valide ou code ");
    delay(1000);
    if (detecterCarte() == CARTE)                                   //Si une carte est inseree alors on lit le code de la carte
    {
      activerBus();                                                 //pour ouvrir ensuite la barriere
      lectureCarte();
      //if (lectureCarte() == '51', '52', '53', '54')
      //{
      Serial.println("Carte OK");
      ouvrir();
      delay(600);
      while ((lectureBav() == BOUCLEAVAL) && (lectureBam() == BOUCLEAMONT));  //Tant que la voiture est sur une boucle il ne se passe rien
      if ((lectureBav() == BOUCLEAVAL) || (lectureBam() == BOUCLEAMONT))    
      {
        while ((lectureBav() == BOUCLEAVAL) || (lectureBam() == BOUCLEAMONT));
      }
      //}
      desactiverBus();
      fermer();                                                           //on ferme la barriere une fois que la voiture est passer ou a reculer
      delay(600);
      nombreVoiture++;
      Serial.println(" Le nombre de voiture est : "); //on incremente le nombre de voiture si et seulement si la voiture est entrer
      Serial.println(nombreVoiture);
    }
    else {                                            //Sinon on demande a l'utilisateur de partir
      Serial.println(" code ou carte invalide ");
    }
    

    Serial.println(" Entrez carte valide ou code ");  //on test si le code taper par l'utilisateur est valide
    delay(1000);
    if (toucheAppuye() == true)             //Si une touche est appuyer alors on test si le code est correct
    {
      while (essaiCode < 3)               //tant que essaiCode est inferieur a 3 on test le code et on incremente les essais
        codeValide();
      essaiCode++;
      if (codeValide() == true && essaiCode < 3)      // si le code est valide et le nombre d'essai est inferieur a 3 alors on ouvre la barriere
      {
        ouvrir();

        delay(3000);
        while ((lectureBav() == BOUCLEAVAL) && (lectureBam() == BOUCLEAMONT));
        if ((lectureBav() == BOUCLEAVAL) || (lectureBam() == BOUCLEAMONT))
        {
          while ((lectureBav() == BOUCLEAVAL) || (lectureBam() == BOUCLEAMONT));
        }
        fermer();
        nombreVoiture++;
        Serial.println(" Le nombre de voiture est : ");
        Serial.println(nombreVoiture);
      }
      else {
        Serial.println(" code ou carte invalide ");
      }
    }
  }
    if ((lectureBav() == BOUCLEAVAL) && (lectureBam() != BOUCLEAMONT)) //Si une voiture veux sortir alors on ouvre la barriere
    {
      ouvrir();
      delay(500);
      while ((lectureBav() == BOUCLEAVAL) && (lectureBam() == BOUCLEAMONT)); //tant que la voiture n'est pas sorti ou n'a pas reculer
      if ((lectureBav() == BOUCLEAVAL) || (lectureBam() == BOUCLEAMONT))    //on laisse la barriere ouverte
      {
        while ((lectureBav() == BOUCLEAVAL) || (lectureBam() == BOUCLEAMONT));
      }
      fermer();
      delay(500);
      nombreVoiture--;  //Si la voiture est sorti on décremente le nombre de voiture dans le parking sinon non 
      Serial.println(" Le nombre de voiture est : ");
      Serial.println(nombreVoiture);
    }
    Wire.endTransmission(MECANISME);
    Wire.endTransmission(AUXILIAIRE);
  }
