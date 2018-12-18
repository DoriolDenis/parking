#ifndef FONCTION_H
#define FONCTION_H

#define MECANISME 0x20    //0 0 1 0 0 0 0 0  
#define AUXILIAIRE 0x21   //0 0 1 0 0 0 0 1
#define CLAVIER false      //0 0 1 0 0 0 1 0
#define CARTE false
#define BOUCLEAVAL false
#define BOUCLEAMONT false
#define OUVRIR 0xFD
#define FERMER 0XFE
#define TEST  0x41

/***** Lecture de boucle *****/
int lectureBav();

int lectureBam();

unsigned char detecterCarte();

unsigned char activerBus();

unsigned char desactiverBus();

unsigned char lectureCarte();

int lectureClavier();

char convertisseurClavier();

bool codeValide();

bool toucheAppuye();

/***** Commande barriere *****/
void ouvrir();

void fermer();

#endif
