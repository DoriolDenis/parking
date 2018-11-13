#ifndef FONCTION_H
#define FONCTION_H

/// On defini ici les constantes qui vont servir a l'ensemble du programme 
/// plutot que de creer des variables globales. Il est ainsi beaucoup plus 
/// facile de maintenir le code (seule une source a changer)

#define PAS1 10     /// Assignation des pattes de la carte 
#define PAS2 11     /// pour commander le moteur 
#define PAS3 12     /// pas a pas 
#define PAS4 13     /// ici in moteur 4 pas 
#define OUVRIR 1    /// Alias pour clarifier le programme 
#define FERMER 0    /// pour l'ouverture et la fermeture 
#define BOUCLEAMONT 14     /// Assignation des pattes de la carte 
#define BOUCLEAVAL 15      /// pour les differents capteurs 
#define VALIDATION 16
#define TEMPO 10

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
