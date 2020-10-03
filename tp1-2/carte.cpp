/* Squelette de départ TP1
 * TP1 - Géocodage inversé
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://ericbeaudry.uqam.ca/INF3105/tp1/
 */

#include "carte.h"
#include <cmath>
#include <istream>
#include <limits>
#include <string>
#include <sstream>

//std::string Carte::geocodageinverse(const Coordonnees& c) const
std:: string Carte :: geocodageinverse(Tableau <Route> routes,const  Coordonnees& p)const
{
 double  distMin = 6371001 *3, longueur, long2;
Coordonnees c,d, prim, vecteurCD, vecteurCP, vecProject, nouvPoint;
 for (int i = 0; i < routes.taille(); i++){
     longueur =0;
   for (int j = 1; j <routes[i].cor.taille()-1 ;i++ ){
    c = routes[i].cor[j-1];
    d = routes[i].cor[j];
    // determiner les vecteurs V(cd) et V(cp)
    vecteurCP = c.nouveauVecteur(p);
    vecteurCD = c.nouveauVecteur(p);
    vecProject =  vecteurCP.projectionCoor(vecteurCD);
      nouvPoint = c.additionner(vecProject);

      if (p.distance(nouvPoint) < distMin){
        distMin = p.distance(nouvPoint);
      }
   long2 = longueur + c.distance(nouvPoint);

    /*  if (i ==0 et j == 1 ){
        distMin = p.distance(nouvPoint);
      }else if (p.distance(nouvPoint) < distMin){
        distMin = p.distance(nouvPoint);
      }*/



}

}
  //    int adresse = 201;
    //std::string rue = "avenue_Président-Kennedy";
   // std::stringstream sstr;
    //sstr << adresse << " " << rue;
    return "yes";
}

std::istream& operator >> (std::istream& is, Route& route)
{
    // Code à compléter...

    // exemple de ligne à lire:
    //  Rue_Jeanne-Mance : 2020 - 2098 : (45.50838,-73.56894) , (45.50915,-73.57062) ;
    int entier;
    char temp;
    std::string chaine;

    // Lecture du nom de rue
    is >> chaine;
    if(!is || chaine.empty()) // détecter une anomalie ou la fin du fichier...
        return is;
    is >> temp;
    assert(temp==':');

    // Lecture de l'intervalle des numéros de porte
    is >> entier >> temp >> entier;
    assert(temp=='-');


    is >> temp;
    assert(temp==':');

    // Lecture des coordonnées
    Coordonnees c;
    is >> c >> temp;
    while(temp==',')
        is >> c >> temp;
    assert(temp==';');
    return is;
}

std::istream& operator >> (std::istream& is, Carte& carte)
{
    // Code à compléter...
    while(is){
        Route route;
        is >> route
           >> std::ws; // force la lecture des espaces blancs.
    }
    return is;
}
