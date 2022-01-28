/*
 Programme : Jeux du morpion
 But : Jeux du morpion
 Date de dernière modification : 04/01/2022
 Auteur : T.Cocheril, I. Salle

*/

//Inclusion de bibliothèque
#include <ctime>
#include <iostream>
#include "game-tools.h"
#include "morpion.h"
using namespace std;

int main()
{
    //Initialisation Variables et Grille du jeu
    string prenom1;                                  //prenom joueur 1
    string prenom2;                                  //prenom du joueur 2
    char symbole1;                                   //symbole du joueur 1
    char symbole2;                                   // symbole du joueur 2
    string coordonnee;                               //coordonne saisi par les joueurs
    int numeroTour = 1;                              //numero tour du jeu
    bool abandon = false;                            //booléen qui renvoi vrai si un joueur abandonne
    bool victoire = false;                           //booléen qui renvoi vrai si un joueur gagne la partie
    char v = char(32);                               //caractère vide que l'on place dans la grille du jeu
    char grille[3][3] = {v, v, v, v, v, v, v, v, v}; // grille de jeu
    int ligne = 0;                                   //ligne de la grille
    int colonne = 0;                                 //colonne de la grille

    //Règle du Jeu
    cout << "----------- M O R P I O N -----------" << endl;
    cout << endl;
    cout << "Jeu avec 2 joueurs humains et une grille de 9 cases : 3 lignes et 3 colonnes." << endl;
    cout << "Chaque Joueur a tour de role." << endl;
    cout << "Le but du jeu est d'aligner, avant son adversaire, 3 symboles identiques, horizontalement, verticalement ou diagonale." << endl;
    cout << "" << endl;
    cout << "La partie se termine :" << endl;
    cout << "-quand l'un des joueurs a aligne ses 3 symboles, et il gagne," << endl;
    cout << "-quand la grille est complete, et il y a egalite (pas de gagnant)" << endl;
    cout << "-quand l'un des joueurs abandonne, et c'est alors l'autre joueur qui gagne." << endl;
    cout << "Chaque joueur a donc son propre symbole." << endl;
    cout << "" << endl;
    cout << "Dans cette version du Morpion, une phase prealable de personnalisation permet a chaque joueur de saisir spn propre prenom, symbole choisit pour jouer." << endl;
    cout << "Lorsqu'arrive son tour de jouer, un joueur peut :" << endl;
    cout << "-saisir la position de la case ou placer son symbole, sous la forme LigneColonne (exemple : 12 pour Ligne 1, Colonne 2)" << endl;
    cout << "-saisir A (ou a) pour abandonner le jeu" << endl;
    cout << "" << endl;
    cout << "------------------------------------" << endl;

    //Phase de personnalisation des joueurs avec vérification de saisi
    cout << "--- Phase de personnalisation ---" << endl;
    cout << "" << endl;
    //clavier >> prenom du joeur 1 >> prenom1
    cout << "Joueur 1, entrez votre prenom : ";
    cin >> prenom1;
    //clavier >> symbole du joeur 1 >> symbole1
    cout << prenom1 << ", entrez votre symbole (1 lettre ou 1 chiffre) : ";
    cin >> symbole1;
    cin.ignore(100, '\n'); //vider le buffer du clavier

    cout << "" << endl;
    while (true)
    {
        //clavier >> prenom du joeur 2 >> prenom2

        cout << "Joueur 2, entrez votre prenom : ";
        cin >> prenom2;
        if (prenom1 != prenom2)
        {
            break;
        }
        else
        {
            cout << "Erreur, vous avez le meme prenom que le joueur 1" << endl;
        }
    }
    while (true)
    {
        //clavier >> symbole du joeur 2 >> symbole2
        cout << prenom2 << ", entrez votre symbole (1 lettre ou 1 chiffre), autre que " << symbole1 << " : ";
        cin >> symbole2;
        
        if (symbole1 != symbole2)
        {
            break;
        }
        else
        {
            cout << "Erreur, vous avez le meme symbole que le joueur 1" << endl;
        }
    }
    cin.ignore(100, '\n'); //vider le buffer du clavier
    cout << "" << endl;
    cout << "Ok c'est partie !!";
    pause(2);  //Pause de 2 secondes
    effacer(); //Effacer le terminal via la bibliothèque GameTools

    //Phase de jeu
    while (true)
    {
        cout << "Tour numero : " << numeroTour << endl; //affichage à l'écran du numéro du tour
        numeroTour = numeroTour + 1;                    //incrémentation du numéro du tour
        cout << "" << endl;

        afficherGrille(grille); //affichage à l'écran de la grille
        cout << "" << endl;

        while (true)
        {
            cout << "" << endl;
            cout << "" << endl;
            //clavier >> coordonnée du joueur 1 >> coordonnee
            cout << "------> " << prenom1 << ", entrez : " << endl;
            cout << "Une coordonnee  (LigneColonne, ex 12 pour ligne 1, colonne 2) ou abandonner en tapant A(a)" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "Votre choix : ";
            cin >> coordonnee;
            if (coordonnee.size() == 1 && (coordonnee[0] == 'a' || coordonnee[0] == 'A')) //vérification d'abandon du joueur 1
            {
                abandon = true;
                break;
            }

            convertirCoord(coordonnee, ligne, colonne); //convertion de la coordonnée en ligne et colonne

            if (verifCoord(coordonnee, ligne, colonne) && caseVide(grille, ligne, colonne)) //vérification de la coordonnée saisi
            {
                break;
            }
            else
            {
                cout << "Erreur de saisi, veuillez recommencer !";
            }
        }
        if (abandon == true) //vérification d'abancodon du joueur 1
        {
            break;
        }
        insererSymbole(grille, symbole1, ligne, colonne); //insertion du symbole dans la grille à la position indiqué par la ligne et la colonne
        //vérification des cas de victoires
        if (verifVictoireColonne(grille, symbole1) || verifVictoireLigne(grille, symbole1) || verifVictoireDiagonale(grille, symbole1))
        {
            victoire = true;
            break;
        }

        pause(1);  //pause de 1 seconde
        effacer(); //effacer le terminal

        //Tour du joueur 2
        if (numeroTour == 10) //vérification de l'égalité
        {
            break;
        }

        cout << "Tour numero : " << numeroTour << endl; //affichage à l'écran du numéro du tour
        numeroTour = numeroTour + 1;                    //incrémentation du numéro du tour de 1
        cout << "" << endl;

        afficherGrille(grille); //affichage de la grille à l'écran
        cout << "" << endl;

        //clavier >> coordonnée du joueur 2 >> coordonnee
        while (true)
        {
            cout << "" << endl;
            cout << "" << endl;
            cout << "------> " << prenom2 << ", entrez : " << endl;
            cout << "Une coordonnee  (LigneColonne, ex 12 pour ligne 1, colonne 2) ou abandonner en tapant A(a)" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "Votre choix : ";
            cin >> coordonnee;
            if (coordonnee.size() == 1 && (coordonnee[0] == 'a' || coordonnee[0] == 'A')) //vérification d'abandon du joueur 2
            {
                abandon = true;
                break;
            }

            convertirCoord(coordonnee, ligne, colonne); //convertion de la coordonnée en ligne colonne

            if (verifCoord(coordonnee, ligne, colonne) && caseVide(grille, ligne, colonne)) //vérification de la coordonnée saisi
            {
                break;
            }
            else
            {
                //Afficher erreur de saisie
                cout << "Erreur de saisi, veuillez recommencer !";
            }
        }

        if (abandon == true) //Vérification d'abandon du joueur 2
        {
            break;
        }

        insererSymbole(grille, symbole2, ligne, colonne); //insertion du symbole 2 dans la grille à la position indiqué par la ligne et la colonne
        if (verifVictoireColonne(grille, symbole2) || verifVictoireLigne(grille, symbole2) || verifVictoireDiagonale(grille, symbole2))         //vérification des cas de victoires du joueurs 2
        {
            victoire = true;
            break;
        }

        pause(1);  //pause de 1 seconde
        effacer(); //effacer le terminal
    }

    //Fin du jeu

    //Affichage de fin de partie en cas d'abandon
    if (abandon == true)
    {
        if (numeroTour % 2 == 0)
        {
            afficherFinPartie(grille, numeroTour); //affichage de fin de partie
            cout << "Partie gagnee par " << prenom2 << " suite a l'abandon de " << prenom1 << " au tour numero " << numeroTour - 1 << " !";
        }
        else
        {
            afficherFinPartie(grille, numeroTour); //affichage de fin de partie
            cout << "Partie gagnee par " << prenom1 << " suite a l'abandon de " << prenom2 << " au tour numero " << numeroTour - 1 << " !";
        }
    }
    //Affichage de fin de partie en cas de victoire
    else if (victoire == true)
    {
        if (numeroTour % 2 == 0)
        {
            afficherFinPartie(grille, numeroTour); //affichage de fin de partie
            cout << "Partie gagnee par " << prenom1 << " au tour numero " << numeroTour - 1 << " !";
        }
        else
        {
            afficherFinPartie(grille, numeroTour); //affichage de fin de partie
            cout << "Partie gagnee par " << prenom2 << " au tour numero " << numeroTour - 1 << " !";
        }
    }
    //Affichage de fin de partie en cas d'égalité
    else if (numeroTour > 9)
    {
        afficherFinPartie(grille, numeroTour); //affichage de fin de partie
        cout << "Egalite (pas de gagnant) car grille complete ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    return 0;
}
