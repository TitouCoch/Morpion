/*
 Programme : Jeux du morpion
 But : Jeux du morpion
 Date de dernière modification : 22 novembre 2021
 Auteur : T. Cocheril I. Salle
 Remarques : Code conforme aux spécifications internes vues en TD2
*/

//#include <cstdlib>
#include <ctime>
#include <iostream>
#include "game-tools.h"
#include "morpion.h"
using namespace std;

int main()
{
    //Initialisation Variables et Grille du jeu :
    string prenom1;
    string prenom2;
    char symbole1;
    char symbole2;
    string coordonnee;
    int numeroTour = 1;
    bool abandon = false;
    bool victoire = false;
    char v = char(32);
    
    
    
    int ligne = 0;
    int colonne = 0;

    //Règle du Jeu :

    cout << "----------- M O R P I O N -----------" << endl;
    cout << endl;
    cout << "Jeu avec 2 joueurs humains et une grille de 9 cases : 3 lignes et 3 colonnes." << endl;
    cout << "Chaque Joueur a tour de rôle." << endl;
    cout << "Le but du jeu est d'aligner, avant son adversaire, 3 symboles identiques, horizontalement, verticalement ou diagonale." << endl;
    cout << "" << endl;
    cout << "La partie se termine :" << endl;
    cout << "-quand l'un des joueurs a aligne ses 3 symboles, et il gagne," << endl;
    cout << "-quand la grille est complète, et il y a égalité (pas de gagnant)" << endl;
    cout << "-quand l'un des joueurs abandonne, et c'est alors l'autre joueur qui gagne." << endl;
    cout << "Chaque joueur a donc son propre symbole." << endl;
    cout << "" << endl;
    cout << "Dans cette version du Morpion, une phase prealable de personnalisation permet a chaque joueur de saisir spn propre prenom, symbole choisit pour jouer." << endl;
    cout << "Lorsqu'arrive son tour de jouer, un joueur peut :" << endl;
    cout << "-saisir la position de la case ou placer son symbole, sous la forme LigneColonne (exemple : 12 pour Ligne 1, Colonne 2)" << endl;
    cout << "-saisir A (ou a) pour abandonner le jeu" << endl;
    cout << "" << endl;
    cout << "------------------------------------" << endl;
    cout << "Veuillez saisir la dimension de la grille parmis les grilles suivantes :"<<endl;
    cout << "3x3 (3), 9x9 (9) "<<endl;

    cout << "Veuillez saisir un des nombres entre parenthèse : "; cin>> y;

    
    //Phase de personnalisation :

    cout << "--- Phase de personnalisation ---" << endl;
    cout << "" << endl;
    cout << "Joueur 1, entrez votre prenom : ";
    cin >> prenom1;
    cout << prenom1 << ", entrez votre symbole (1 lettre ou 1 chiffre) : ";
    cin >> symbole1;
    cout << "" << endl;
    while (true)
    {
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
    cout << "" << endl;
    cout << "Ok c'est partie !!";
    pause(2);
    //Effacer le terminal via la bibliothèque GameTools
    effacer();

    //Fin de l'initialisation

    //Début de la phase de jeu :

    while (true)
    {

        //Tour du joueur 1 :

        //Verifie l'égalite
        if (numeroTour > 9)
        {
            break;
        }

        //Affiche le tour actuelle
        cout << "Tour numero : " << numeroTour << endl;
        numeroTour = numeroTour + 1;
        cout << "" << endl;

        //Affiche le tableau

        //afficherGrille();
        afficherGrille(grille);
        cout << "" << endl;
        //Saisi verif de l'abandon du joueur
        while (true)
        {

            //Verifier la continuation de la partie
            //saisi verif de la coordonnée du joueur
            cout << "" << endl;
            cout << "" << endl;
            cout << "------> " << prenom1 << ", entrez : " << endl;
            cout << "Une coordonnee  (LigneColonne, ex 12 pour ligne 1, colonne 2) ou abandonner en tapant A(a)" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "Votre choix : ";
            cin >> coordonnee;
            if (coordonnee.size() == 1 && (coordonnee[0] == 'a' || coordonnee[0] == 'A'))
            {
                abandon = true;
                break;
            }

            convertirCoord(coordonnee, ligne, colonne);

            //Fonction de verification de coordonnee et verification de case vide

            if (verifCoord(coordonnee, ligne, colonne) && caseVide(grille, ligne, colonne))
            {
                break;
            }
            else
            {
                //Afficher erreur de saisie
                cout << "Erreur de saisi, veuillez recommencer !";
            }
        }
        if (abandon == true)
        {
            break;
        }
        insererSymbole(grille, symbole1, ligne, colonne);
        if (verifierVictoire(grille, symbole1))
        {
            victoire = true;
            break;
        }

        pause(1);
        effacer();

        //Tour du joueur 2 :

        if (numeroTour > 9)
        {
            break;
        }

        //Affiche le tour actuelle
        cout << "Tour numero : " << numeroTour << endl;
        numeroTour = numeroTour + 1;
        cout << "" << endl;

        //Affiche le tableau

        //afficherGrille();
        afficherGrille(grille);
        cout << "" << endl;
        //Saisi verif de l'abandon du joueur
        while (true)
        {

            //Verifier la continuation de la partie
            //saisi verif de la coordonnée du joueur
            cout << "" << endl;
            cout << "" << endl;
            cout << "------> " << prenom2 << ", entrez : " << endl;
            cout << "Une coordonnee  (LigneColonne, ex 12 pour ligne 1, colonne 2) ou abandonner en tapant A(a)" << endl;
            cout << "" << endl;
            cout << "" << endl;
            cout << "Votre choix : ";
            cin >> coordonnee;
            if (coordonnee.size() == 1 && (coordonnee[0] == 'a' || coordonnee[0] == 'A'))
            {
                abandon = true;
                break;
            }

            convertirCoord(coordonnee, ligne, colonne);

            //Fonction de verification de coordonnee et verification de case vide

            if (verifCoord(coordonnee, ligne, colonne) && caseVide(grille, ligne, colonne))
            {
                break;
            }
            else
            {
                //Afficher erreur de saisie
                cout << "Erreur de saisi, veuillez recommencer !";
            }
        }
        if (abandon == true)
        {
            break;
        }

        insererSymbole(grille, symbole2, ligne, colonne);
        if (verifierVictoire(grille, symbole2))
        {
            victoire = true;
            break;
        }

        pause(1);
        effacer();
    }

    //Fin de la partie :

    //Afficher la finalité de la partie :

    if (numeroTour > 9)
    {
        afficherFinPartie(grille, numeroTour);
        cout << "Egalite (pas de gagnant) car grille complete ";
    }
    else if (victoire == true)
    {
        if (numeroTour % 2 == 0)
        {
            afficherFinPartie(grille, numeroTour);
            cout << "Partie gagne par " << prenom1 << " au tour numero " << numeroTour - 1 << " !";
        }
        else
        {
            afficherFinPartie(grille, numeroTour);
            cout << "Partie gagne par " << prenom2 << " au tour numero " << numeroTour - 1 << " !";
        }
    }
    else if (abandon == true)
    {
        if (numeroTour % 2 == 0)
        {
            afficherFinPartie(grille, numeroTour);
            cout << "Partie gagne par " << prenom2 << " suite a l'abandon de " << prenom1 << " au tour numero " << numeroTour - 1 << " !";
        }
        else
        {
            afficherFinPartie(grille, numeroTour);
            cout << "Partie gagne par " << prenom1 << " suite a l'abandon de " << prenom2 << " au tour numero " << numeroTour - 1 << " !";
        }
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    return 0;
}
