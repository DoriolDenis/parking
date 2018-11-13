#include "fonction.h"       /// Permet de recuperer le prototype des fonctions ainsi que les differentes constantes
#include "arduino.h"        /// a ne mettre que si l'on utilise un fichier separee
#include <Wire.h>

void commandeBarriere(int sens, int tours)
{
  pinMode (PAS1,OUTPUT);    /// Initialisation des broches en sortie
  pinMode (PAS2,OUTPUT);
  pinMode (PAS3,OUTPUT);
  pinMode (PAS4,OUTPUT);
    
    if (sens)       /// Suivant la valeur du sens, on ouvre ou on ferme la barriere
    {
      ouvrir(tours);
    }
    else
    {
      fermer(tours);
    }
}

void ouvrir(int tours)
{
  int i,j;
    for(i=0; i<tours; i++)
    {
      for(j=0;j<12;j++)       /// On repete la sequence de 4 douze fois pour realiser 1 tours (moteur 48 pas)
      {
        seq(1);
        delay(TEMPO);         /// Temporisation pour tenir compte du cahier des charges
        seq(2);
        delay(TEMPO);
        seq(3);
        delay(TEMPO);
        seq(4);
        delay(TEMPO);
      }
    }
}

void fermer(int tours)
{
  int i,j;
    for(i=0; i<tours; i++)
    {
      for(j=0;j<12;j++)       /// On repete la sequence de 4 douze fois pour realiser 1 tours (moteur 48 pas)
      {
        seq(4);
        delay(TEMPO);         /// Temporisation pour tenir compte du cahier des charges
        seq(3);
        delay(TEMPO);
        seq(2);
        delay(TEMPO);
        seq(1);
        delay(TEMPO);
      }
    }
}

void seq(int numeroSeq)       /// Fonction qui permet de generer les 4 pas
{
  switch (numeroSeq)
  {
    case 1 : digitalWrite(PAS1,HIGH);
             digitalWrite(PAS2,LOW);
             digitalWrite(PAS3,LOW);
             digitalWrite(PAS4,HIGH);
             break;
             
   case 2 :  digitalWrite(PAS1,LOW);
             digitalWrite(PAS2,HIGH);
             digitalWrite(PAS3,LOW);
             digitalWrite(PAS4,HIGH);
             break;
             
   case 3 :  digitalWrite(PAS1,LOW);
             digitalWrite(PAS2,HIGH);
             digitalWrite(PAS3,LOW);
             digitalWrite(PAS4,HIGH);
             break;
             
  case 4 :   digitalWrite(PAS1,HIGH);
             digitalWrite(PAS2,LOW);
             digitalWrite(PAS3,HIGH);
             digitalWrite(PAS4,LOW);
             break;    
  }
}
