/**  MODULE MORPION 
     regroupe des sous-programmes applicables au jeu du morpion
     -------------------------------------------------------
But :
    Mettre à dispositon d'un programmeur des sous-programmes applicables au jeu du morpion.
---------

 Date de dernière modification : 05/01/2022
 Auteur : T.cocheril I.salle
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

bool caseVide(char tab[3][3], int ligne, int colonne);
// verifie que la case de coordonnee ligne, colonne contient bien un caractere vide


//Accesseur

//Entrée-Sortie


//sous-programmes

void afficherGrille(const char tab[3][3]);
//But : Afficher la grille de jeu du morpion
//pré-conditions: la grille est un tableau de 3 lignes 3 colonnes


bool verifCoord(const string coord, int ligne, int colonne);
//but verifier que les variables ligne et colonne sont comprises entre 11 et 13, 21 et 23, 31 et 33 et que coord soit de longueur 2

bool caseVide(char tab[3][3], int ligne, int colonne);
//But : Verifier que la case de position ligne et colonne du tableau tab est bien vide
//pré-conditions: la grille est un tableau de 3 lignes 3 colonnes

void insererSymbole(char tab[3][3], char symbole, int ligne, int colonne);
//But : insérer le symbole dans le tableau à la case défini à la colonne et la ligne
//pré-conditions: la grille est un tableau de 3 lignes 3 colonnes

void afficherFinPartie(char tab[3][3], int numeroTour);
//affiche le numero du dernier tour, la grille et un message de fin de partie
//pré-conditions: la grille est un tableau de 3 lignes 3 colonnes

void convertirCoord (string coord, int & ligne, int & colonne);
//convertis les coordonnee saisie en une ligne et une colonne de la grille

bool verifVictoireColonne(char tab[3][3], char symbole);
//verifie si les colonnes de la grille contiennent un cas de victoire
//pré-conditions: la grille est un tableau de 3 lignes 3 colonnes

bool verifVictoireLigne(char tab[3][3], char symbole);
//verifie si les lignes de la grille contiennent un cas de victoire
//pré-conditions: la grille est un tableau de 3 lignes 3 colonnes

bool verifVictoireDiagonale(char tab[3][3], char symbole);
//verifie si les diagonales de la grille contiennent un cas de victoire
//pré-conditions: la grille est un tableau de 3 lignes 3 colonnes

#endif 