/* Squelette de départ TP2
 * TP2 - Traçage Pandémie
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://ericbeaudry.uqam.ca/INF3105/tp2/
 */
#include <iostream>
#include <fstream>
#include <cassert>
#include "historique.h"

int tp2(std::istream& entree){   
    Historique historique;
    std::string nompersonne, nomlieu, nompersonne2;
    DateHeure dh;
    Intervalle intervalle;
    while(entree){
         std::string cmd;
         char pv=0;
         entree >> cmd;
         if(!entree) break;
         
         if(cmd=="trace"){
             entree >> dh >> nomlieu >> nompersonne >> pv;
             historique.trace(dh, nomlieu, nompersonne);
             std::cout << "OK" << std::endl; 
         }
         else if(cmd=="localiser"){
             entree >> intervalle >> nompersonne >> pv;
             ArbreAVL<std::string> lieux = historique.localiser(intervalle, nompersonne);
             for(ArbreAVL<std::string>::Iterateur iter=lieux.debut();iter;++iter)
                 std::cout << *iter << " ";
             std::cout << std::endl;
         }
         else if(cmd=="presences"){
             entree >> intervalle >> nomlieu >> pv;
             ArbreAVL<std::string> personnes = historique.presences(intervalle, nomlieu);
             for(ArbreAVL<std::string>::Iterateur iter=personnes.debut();iter;++iter)
                 std::cout << *iter << " ";
             std::cout << std::endl;
         }
         else if(cmd=="frequentations"){
             entree >> intervalle >> nompersonne >> pv;
             ArbreAVL<std::string> personnes = historique.frequentations(intervalle, nompersonne);
             for(ArbreAVL<std::string>::Iterateur iter=personnes.debut();iter;++iter)
                 std::cout << *iter << " ";
             std::cout << std::endl;
         }
         else if(cmd=="duree_rencontres"){
             entree >> intervalle >> nompersonne >> nompersonne2 >> pv;
             int dr = historique.duree_rencontres(intervalle, nompersonne, nompersonne2);
             std::cout << dr << std::endl;
         }
         assert(pv==';');
    }
    return 0;
}

int main(int argc, const char** args)
{
    if(argc>1){
         std::ifstream entree(args[1]);
         if(entree.fail()){
             std::cerr << "Erreur d'ouverture du fichier '" << args[1] << "'" << std::endl;
             return 1;
         }else
             return tp2(entree);
    }else
         return tp2(std::cin);
    return 0;
}

