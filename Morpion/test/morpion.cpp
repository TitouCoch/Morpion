/* CORPS DU MODULE */
//Inclusion
#include "morpion.h"
#include <iostream>
#include "game-tools.h"
using namespace std;

//Coprs de sous programme :
//Type variable
//Déclaration des sous programmes utilisé :
//Coprs des sous programmes déclarés

bool verifCoord(const string coord, int ligne, int colonne)

{
    if ((coord.size() != 2) || (ligne > 2 || ligne < 0) || (colonne > 2 || colonne < 0))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void convertirCoord(string coord, int &ligne, int &colonne)
{
    ligne = char(coord[0]) - '0';
    ligne = ligne - 1;
    colonne = char(coord[1]) - '0';
    colonne = colonne - 1;
}

void afficherGrille(const char tab[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << " [";
        cout << tab[i][0];
        cout << "|";
        cout << tab[i][1];
        cout << "|";
        cout << tab[i][2];
        cout << "]";
        cout << endl;
    }
}

bool caseVide(char tab[3][3], int ligne, int colonne)
{
    if (tab[ligne][colonne] == char(32))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void insererSymbole(char tab[3][3], char symbole, int ligne, int colonne)
{
    tab[ligne][colonne] = symbole;
}

bool verifierVictoire(char tab[3][3], char symbole)
{
  //  if (
 //       (tab[0][0] == symbole && tab[0][1] == symbole && tab[0][2] == symbole) || (tab[1][0] == symbole && tab[1][1] == symbole && tab[1][2] == symbole) ||
 //       (tab[2][0] == symbole && tab[2][1] == symbole && tab[2][2] == symbole) || (tab[0][0] == symbole && tab[1][0] == symbole && tab[2][0] == symbole) ||
  //      (tab[0][1] == symbole && tab[1][1] == symbole && tab[2][1] == symbole) || (tab[0][2] == symbole && tab[1][2] == symbole && tab[2][2] == symbole) ||
  //      (tab[0][1] == symbole && tab[1][2] == symbole && tab[2][2] == symbole) || (tab[0][2] == symbole && tab[1][1] == symbole && tab[2][0] == symbole))
   // {
 //       return true;
 //   }
 //   else
  //  {
 //       return false;
 //   }
}

void afficherFinPartie(char tab[3][3], int numeroTour)
{
    effacer();

    cout << "Tour numero : " << numeroTour << endl;
    numeroTour = numeroTour + 1;
    cout << "" << endl;

    //afficherGrille();
    afficherGrille(tab);
    cout << "" << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "----------- FIN DE LA PARTIE -----------" << endl;
    cout << endl;
    cout << endl;
}