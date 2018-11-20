#ifndef FONCTION_H
#define FONCTION_H

// On defini ici les sconstantes qui vont servir a l'ensemble du programme 
// plutot que de creer des variables globales. Il est ainsi beaucoup plus 
// facile de maintenir le code (seule une source a changer)


#define OUVRIR 0xFD    // Alias pour clarifier le programme 
#define FERMER 0xFE    // pour l'ouverture et la fermeture de la barriere
#define BOUCLEAMONT 0xC0      //Boucle d'entrée
#define BOUCLEAVAL 0xA0  //Boucle de sortie    

#define MECANISME 0x20    //0 0 1 0 0 0 0 0  Assignation de l'adresse 0x20 a la variable mecanisme du bus I2C
#define AUXILIAIRE 0x21   //0 0 1 0 0 0 0 1  Assignation de l'adresse 0x21 a la variable auxiliaire du bus I2C
#define CLAVIER 0x22      //0 0 1 0 0 0 1 0  Assignation de l'adresse 0x22 a la variable clavier du bus I2C


void commandeBarriere(int,int);   // Fonction qui accepte deux parametre :
                                  // int : defini le sens de fonctionnement de la barriere
                                  //     0 => fermeture de la barriere
                                  //     autre valeur => ouverture de la barriere
                                  // int : defini le nombre de tours que doit realiser la barriere

void ouvrir();     // Fonction qui a un parametre qui correspond au nombre de tours dans le sens de l'ouverture

void fermer();     // Fonction qui a un parametre qui correspond au nombre de tours dans le sens de la fermeture

unsigned char lectureBam();

unsigned char lectureBav();


#endif
