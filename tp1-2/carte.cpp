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
//#include <bits/stdc++.h>

//std::string Carte::geocodageinverse(const Coordonnees& c) const
//std:: string Carte :: geocodageinverse(Tableau <Route> routes,const  Coordonnees& p)const



std:: string Carte :: geocodageinverse(const  Coordonnees& p, int compteur)const
{
  std ::string adresse = "";
 double  distMin = 6371001 *3, longueur, long2, longdist;
 int numeroPorte;
Coordonnees c,d, prim, vecteurCD, vecteurCP, vecProject, nouvPoint;

for(int i = 0; i<routes.taille(); i++){
    longueur =0;
  for (int j = 1; j <routes[i].cor.taille() ;j++ ){
   c = routes[i].cor[j-1];

   d = routes[i].cor[j];
   vecteurCP = c.nouveauVecteur(p);
   vecteurCD = c.nouveauVecteur(d);
   vecProject =  vecteurCP.projectionCoor(vecteurCD);
     nouvPoint = c.additionner(vecProject);
     if (p.distance(nouvPoint) < distMin){
       distMin = p.distance(nouvPoint);

       long2 = longueur + c.distance(nouvPoint);

       longdist = long2 + nouvPoint.distance(d);
    //   if( c.distance(nouvPoint) < nouvPoint.distance(d))
    /*
        numeroPorte = round(((longdist -long2)/(longdist-longueur))*routes[i].porteDebut+
                              ((long2-longueur)/(longdist-longueur))* routes[i].portFin);
     */

     numeroPorte = round(((longdist -long2)/(longdist-longueur))*routes[i].porteDebut+
                           ((long2-longueur)/(longdist-longueur))* routes[i].portFin);

     


  /*    if( c.distance(nouvPoint) >= nouvPoint.distance(d))
         numeroPorte = round(((longdist -long2)/(longdist-longueur))*routes[i].porteDebut+
                             ((long2-longueur)/(longdist-longueur))* routes[i].portFin);
       */

            if(routes[i].porteDebut%2 ==0&&numeroPorte%2!=0 ) numeroPorte--;
             if(routes[i].porteDebut%2 !=0&&numeroPorte%2==0 ) numeroPorte--;
           adresse = std::to_string(numeroPorte) + " " + routes[i].nom ;

     }
  longueur += c.distance(d);
}
}
    return adresse;
}




  /*si a la longueur 0 correspond porteDebut
  alors a quoi va correspondre porte a
       si porteDebut-> 0,005
        numeroPorte -> long2
  */




  //if (c.distance(nouvPoint)< nouvPoint.distance(d)){
 //  numPort2 =round(long2*routes[compteur].porteDebut/longtest);

  //std::cout << longdist<< "-"<< long2<< "-"<<longueur<< std::endl;
/*  std::cout << longdist<< std::endl;
  std::cout << long2<< std::endl;
  std::cout << longueur<< std::endl;
  std::cout << numeroPorte<< std::endl;
  std::cout << "--------"<< std::endl;
} else if (c.distance(nouvPoint)> nouvPoint.distance(d)){
std::cout << long2<< std::endl;
numeroPorte = round((longdist -long2)/(longdist-longueur)*routes[compteur].portFin +
                        (long2-longueur)/(longdist-longueur)* routes[compteur].porteDebut);
}*/





/*
std:: string Carte :: geocodageinverse(const  Coordonnees& p)const
{
  std ::string adresse = "";
 double  distMin = 6371001 *3, longueur, long2, longdist;
 int numeroPorte;
Coordonnees c,d, prim, vecteurCD, vecteurCP, vecProject, nouvPoint;
 for (int i = 0; i < routes.taille(); i++){
     longueur =0;
       //std::cout << "HERE"<< std::endl;
        std::cout << routes[i].nom<< std::endl;
   for (int j = 10; j <routes[i].cor.taille() ;j++ ){
    c = routes[i].cor[j-1];
  //  std::cout << c.latitude<< "-"<< c.longitude<< std::endl;
  std::cout << "ICI"<< std::endl;
    d = routes[i].cor[j];
    // determiner les vecteurs V(cd) et V(cp)
    vecteurCP = c.nouveauVecteur(p);
    vecteurCD = c.nouveauVecteur(p);
    vecProject =  vecteurCP.projectionCoor(vecteurCD);
      nouvPoint = c.additionner(vecProject); // on va redefinir l'operateur = pour ce class
                                            // addition de deux vecteur

      if (p.distance(nouvPoint) < distMin){
        distMin = p.distance(nouvPoint);
      }
   long2 = longueur + c.distance(nouvPoint);


   // to be test starting from here

  longdist = long2 + nouvPoint.distance(d);
  if (c.distance(nouvPoint)< nouvPoint.distance(d)){
    numeroPorte = round((longdist -long2)/(longdist-longueur)*routes[i].porteDebut +
                         (long2-longueur)/(longdist-longueur)* routes[i].portFin);

  } else if (c.distance(nouvPoint)> nouvPoint.distance(d)){

      numeroPorte = round((longdist -long2)/(longdist-longueur)*routes[i].porteDebut +
                           (long2-longueur)/(longdist-longueur)* routes[i].portFin);
  }

        adresse = std::to_string(numeroPorte) + " " + routes[i].nom ;
   longueur += c.distance(d);
}

}

    return adresse;
}*/




std::istream& operator >> (std::istream& is, Route& route)
{
    // Code à compléter...
  char  deuxpoint, tiret, virgule;

  if (is){
    // Lecture du nom de rue
    is >> route.nom;

    if(!is || ((std::string)route.nom).empty()) // détecter une anomalie ou la fin du fichier...
        return is;
    is >> deuxpoint;
    assert(deuxpoint==':');

    // Lecture de l'intervalle des numéros de porte
    is >> route.porteDebut >> tiret >> route.portFin;
    assert(tiret=='-');

    is >> deuxpoint;
    assert(deuxpoint==':');

    // Lecture des coordonnées
    Coordonnees c;
    /*is >> c >> virgule;
    route.cor.ajouter(c);
    while(virgule==','){
        is >> c >> virgule;
        route.cor.ajouter(c);
      }*/
      do{
        is >> c >> virgule;
        route.cor.ajouter(c);
      }while(virgule==',');
    assert(virgule==';');
  }
    return is;
}


/*std::ostream&  operator <<  (std::ostream& os, Route& route){
  os << "("
     << route.porteDebut
     << ","
     << route.portFin
     << ")";
  return os;

}*/

std::istream& operator >> (std::istream& is, Carte& carte)
{
    // Code à compléter...

    while(is){
        Route route;
        is >> route
           >> std::ws; // force la lecture des espaces blancs.
           carte.routes.ajouter(route);

    }
    return is;
}
