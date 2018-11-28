#ifndef FONCTION_H
#define FONCTION_H

#define MECANISME 0x20    //0 0 1 0 0 0 0 0  
#define AUXILIAIRE 0x21   //0 0 1 0 0 0 0 1
#define CLAVIER 0x22      //0 0 1 0 0 0 1 0
#define BOUCLEAVAL false
#define BOUCLEAMONT false
#define OUVRIR 0xFD
#define FERMER 0XFE
#define TEST  0x41

/***** Lecture de boucle *****/
int lectureBav();

int lectureBam();

/***** Commande barriere *****/
void ouvrir();

void fermer();

#endif
