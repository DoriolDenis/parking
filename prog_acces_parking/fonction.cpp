#include <Arduino.h>
#include <wire.h>
#include "fonction.h"

int lectureBav() //fonction permettatn de detecter si il y a une voiture sur la boucle aval
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




int lectureBam()//fonction permettatn de detecter si il y a une voiture sur la boucle amont
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


void ouvrir() //Fonction permettant d'ouvrir la barriere
{
  Wire.beginTransmission(MECANISME);  //Debut de transmission avec MECANISME
  Wire.write(OUVRIR); //Octet pour ouvrir barriere
  Serial.print("Ouvrir\n");
  Wire.endTransmission(MECANISME);  //Fin de transmission avec MECANISME
}



void fermer() //Fonction permettant de fermer la barriere
{
  Wire.beginTransmission(MECANISME);
  Wire.write(FERMER);
  Serial.print("Fermer\n");
  Wire.endTransmission(MECANISME);
}





unsigned char detecterCarte()   //fonction qui detecte si une carte est inseree dans le boitier
{
  unsigned char valBit;
  Wire.beginTransmission(AUXILIAIRE);
  Wire.write(0xF1);
  Wire.endTransmission(AUXILIAIRE);
  Wire.requestFrom(AUXILIAIRE, 1);
  if (Wire.available())
  {
    valBit = Wire.read();
    valBit = bitRead(valBit, 0);
  }
  return valBit;
}





unsigned char activerBus()  //fonction qui permet la laison avec le bus I2C pour lire les valeurs de la carte a puce
{
  Wire.beginTransmission(AUXILIAIRE);
  Wire.write(0xF2);
  Wire.endTransmission(AUXILIAIRE);
}

unsigned char desactiverBus()//fonction qui desactive la liason avec la barriere
{
  Wire.beginTransmission(AUXILIAIRE);
  Wire.write(0xF1);
  Wire.endTransmission(AUXILIAIRE);
}





unsigned char lectureCarte()    //Fonction qui lit les valeurs qui sont enregistrer sur la carte
{
  unsigned char valeurCarte;
  Wire.requestFrom(0x50, 5);
  while (Wire.available())
  {
    valeurCarte = Wire.read();
    Serial.print("CODE :");
    Serial.println(valeurCarte);
  }
  return valeurCarte;
}





int lectureClavier()    //fonction qui lit quelle touche est appuyer sur le clavier de la barriere
{

  int colonne, ligne;
  Wire.beginTransmission(0x22);
  Wire.write(0x0F);
  Wire.endTransmission();
  Wire.requestFrom(0x22, 1);

  while (Wire.available())
  {
    colonne = Wire.read();
    //Serial.print("Affiche la colonne : ");
    //Serial.println(colonne);
  }
  if (colonne != 240)
  {
    Wire.beginTransmission(0x22);
    Wire.write(0xF0);
    Wire.endTransmission();
    Wire.requestFrom(0x22, 1);

    while (Wire.available())
    {
      ligne = Wire.read();
      // Serial.print("Affiche la ligne");
      // Serial.println(ligne);
    }

    return colonne + ligne;


  }
}





char convertisseurClavier() //fonction qui converti la valeur lu sur le clavier en décimal
{
  int c = lectureClavier();
  char touchesClavier;


  switch (c)
  {
    case 215 :
      touchesClavier = '0';
      Serial.println(touchesClavier);
      break;
    case 238 :
      touchesClavier = '1';
      Serial.println(touchesClavier);
      break;
    case 222 :
      touchesClavier = '2';
      Serial.println(touchesClavier);
      break;
    case 190 :
      touchesClavier = '3';
      Serial.println(touchesClavier);
      break;
    case 237 :
      touchesClavier = '4';
      Serial.println(touchesClavier);
      break;
    case 221 :
      touchesClavier = '5';
      Serial.println(touchesClavier);
      break;
    case 189 :
      touchesClavier = '6';
      Serial.println(touchesClavier);
      break;
    case 235 :
      touchesClavier = '7';
      Serial.println(touchesClavier);
      break;
    case 219 :
      touchesClavier = '8';
      Serial.println(touchesClavier);
      break;
    case 187 :
      touchesClavier = '9';
      Serial.println(touchesClavier);
      break;
    case 183 :
      touchesClavier = '#';
      Serial.println(touchesClavier);
      break;
    case 231 :
      touchesClavier = '*';
      Serial.println(touchesClavier);
      break;

  }
  delay(160);
  return touchesClavier;
}





bool toucheAppuye()   //fonction qui test si une touche a etait appuyer
{
  if (lectureClavier() == 255)
  {
    return false;
  }
  else
  {
    return true;
  }
}




bool codeValide()//fonction qui test si le code rentrer est valide
{
  lectureClavier();
  toucheAppuye();
  convertisseurClavier();
  char codeBon[4] = {'6', '9', '6', '9'};
  char tabCode[4];
  char i = 0, j = 0, essaie = 1;
  while (j < 3)
  {
    while (toucheAppuye() == false);
    if (toucheAppuye() == true)
    {
      tabCode[j] = convertisseurClavier();
      j++;
    }
  }
  j = 0;
  while ((i < 3) && (j < 3))
  {
    if (codeBon[i] == tabCode[j])
    {
      i++;
      j++;
    }
    else
    {
      Serial.println("Code faux ");

      return false;
      delay (500);
    }
  }
  Serial.println ("Code Bon");

  return true;
}
