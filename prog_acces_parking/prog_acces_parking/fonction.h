#ifndef FONCTION_H
#define FONCTION_H

/// On defini ici les sconstantes qui vont servir a l'ensemble du programme 
/// plutot que de creer des variables globales. Il est ainsi beaucoup plus 
/// facile de maintenir le code (seule une source a changer)

#define PAS1 10     /// Assignation des pattes de la carte 
#define PAS2 11     /// pour commander le moteur 
#define PAS3 12     /// pas a pas 
#define PAS4 13     /// ici in moteur 4 pas 
#define OUVRIR 0xFD    /// Alias pour clarifier le programme 
#define FERMER 0xFE    /// pour l'ouverture et la fermeture de la barriere
#define BOUCLEAMONT 0xA6     /// 198 
#define BOUCLEAVAL 0xC6      /// 166
#define VALIDATION 16
#define TEMPO 10
#define MECANISME 0x20    //0 0 1 0 0 0 0 0  Assignation de l'adresse 0x20 a la variable mecanisme du bus I2C
#define AUXILIAIRE 0x21   //0 0 1 0 0 0 0 1  Assignation de l'adresse 0x21 a la variable auxiliaire du bus I2C
#define CLAVIER 0x22      //0 0 1 0 0 0 1 0  Assignation de l'adresse 0x22 a la variable clavier du bus I2C


void commandeBarriere(int,int);   /// Fonction qui accepte deux parametre :
                                  /// int : defini le sens de fonctionnement de la barriere
                                  ///     0 => fermeture de la barriere
                                  ///     autre valeur => ouverture de la barriere
                                  /// int : defini le nombre de tours que doit realiser la barriere

void ouvrir(int);     /// Fonction qui a un parametre qui correspond au nombre de tours dans le sens de l'ouverture

void fermer(int);     /// Fonction qui a un parametre qui correspond au nombre de tours dans le sens de la fermeture

void seq(int);        /// Fonction qui permet de placer un certaine sequence en entree du moteur pas a pas suivant la valeur du parametre : 
                      /// int = 1 : PAS1 = 1
                      ///           PAS2 = 0
                      ///           PAS3 = 0
                      ///           PAS4 = 1
                      /// int = 2 : PAS1 = 0
                      ///           PAS2 = 1
                      ///           PAS3 = 0
                      ///           PAS4 = 1
                      /// int = 3 : PAS1 = 0
                      ///           PAS2 = 1
                      ///           PAS3 = 1
                      ///           PAS4 = 0
                      /// int = 4 : PAS1 = 1
                      ///           PAS2 = 0
                      ///           PAS3 = 1
                      ///           PAS4 = 0

#endif
