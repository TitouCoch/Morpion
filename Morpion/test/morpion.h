/**  MODULE MORPION 
     regroupe des sous-programmes applicables au jeu du morpion
     -------------------------------------------------------
But :
    Mettre à dispositon d'un programmeur des sous-programmes applicables au jeu du morpion.
---------

 Date de dernière modification : xxxx
 Auteur : xxx
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°2
*/

#ifndef MORPION_H
#define MORPION_H

#include <iostream>
using namespace std;

//Type

//Constante

//Operateur de comparaison

//Operateur binaire

//Autre operateur

//Accesseur

//Entrée-Sortie
void afficherGrille(const char tab[3][3]);
//But : Afficher la grille de jeu du morpion
bool verifCoord(const string coord, int ligne, int colonne);
//But : Vérifier la coordonnee rentré par le joueur
void convertirCoord (string coord, int & ligne, int & colonne);
//But : convertir les coordonnées en ligne et colonne
bool caseVide(char tab[3][3], int ligne, int colonne);
//But : Verifier que la case de position ligne et colonne du tableau tab est bien vide
void insererSymbole(char tab[3][3], char symbole, int ligne, int colonne);
//But : inérer le symbole dans le tableau à la case défini à la colonne et la ligne
bool verifierVictoire(char tab[3][3], char symbole);
//But : vérifier les cas de victoire dans la grille 
void afficherFinPartie(char tab[3][3], int numeroTour);

#endif 