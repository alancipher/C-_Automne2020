/* Squelette de départ TP1
 * TP1 - Géocodage inversé
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://ericbeaudry.uqam.ca/INF3105/tp1/
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "carte.h"

// Fonction princiale du TP1 : lecture et traitement des requêtes
int tp1(const Carte& carte, std::istream& in)
{
   int  indice =0;
    while(in){
        Coordonnees c;
        in >> c;
        if(in){
           std::string adresse = carte.geocodageinverse(c, indice);
         std::cout << adresse << std::endl;
        }
        in >> std::ws;
        //Tableau <Route> routes,const  Coordonnees& p
        indice++;
    }
    return 0; // fin normale
}

// La fonction main est le point d'entrée. En principe, vous n'avez pas à modifier.
// argc=nombre d'arguments (le premier implicite étant l'exécutable); argv=tableau de chaines de caractères
int main(int argc, const char** argv)
{
    if(argc<2)
    {  // Si aucun arguements passés.
        std::cout << "./tp1 carte.txt [requetes.txt]" << std::endl;
        return 1;
    }
    Carte carte;
    {
        // Lecture du fichier carte
        std::ifstream fcarte(argv[1]);
        if(!fcarte)
        {
            std::cout << "Erreur ouverture : " << argv[1] << std::endl;
            return 2;
        }
        fcarte >> carte;
        //  std::cout <<carte << std::endl;

      //  for (int i = 0 ; i<carte.routes.taille(); i++)
        // std::cout <<carte.routes[i]<< std::endl;
    }
    if(argc<3)
        return tp1(carte, std::cin); // Si un seul argument, lire depuis l'entrée standard (clavier ou fichier redirigé).
    else{
        // Si deux arguments, lire depuis le fichier spécifié.
        std::ifstream frequetes(argv[2]);
        if(!frequetes){
            std::cout << "Erreur ouverture : " << argv[2] << std::endl;
            return 3;
        }
        return tp1(carte, frequetes);
    }
}
