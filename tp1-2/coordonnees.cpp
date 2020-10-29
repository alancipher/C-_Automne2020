/* Squelette de départ TP1
 * TP1 - Géocodage inversé
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://ericbeaudry.uqam.ca/INF3105/tp1/
 */

#include <math.h>
#include <assert.h>
#include "coordonnees.h"
#define RAYONTERRE 6371001  // en mètres
#define PI 3.14159265359

Coordonnees :: Coordonnees(){
  // constructeur vide a revoir
}

Coordonnees :: Coordonnees (double lat_,double long_)
: latitude(lat_), longitude(long_)
{

}
double Coordonnees::distance(const Coordonnees& coor) const {
  double s1 = sin((coor.latitude-latitude)/2);
  double s2 = sin((coor.longitude-longitude)/2);
  return 2*RAYONTERRE * asin(sqrt(s1*s1 + cos(latitude)*cos(coor.latitude)*s2*s2));
}

Coordonnees Coordonnees:: nouveauVecteur(const Coordonnees& coor)const{
  double nouvLatitude = (coor.latitude -latitude);
  double nouvLongitude = (coor.longitude-longitude);
  Coordonnees nouvVecteur(nouvLatitude,nouvLongitude);
  return nouvVecteur;

}
 Coordonnees Coordonnees :: projectionCoor(const Coordonnees& coor)const{
   double produitCaCd = coor.latitude *latitude+ coor.longitude*longitude;
   double produitCd = coor.latitude *coor.latitude+ coor.longitude*coor.longitude;
   double rapport = produitCaCd/ produitCd;
   if(rapport >= 1) rapport= 1;

   if(rapport <=0) rapport =0;
//    Coordonnees nouvVecteur1(rapport*coor.latitude, rapport*coor.longitude);
  //  return nouvVecteur1;
  // }

   Coordonnees nouvVecteur(rapport*coor.latitude, rapport*coor.longitude);
   return nouvVecteur;
 }

Coordonnees Coordonnees ::additionner(const Coordonnees& coor)const{
  Coordonnees nouvPoint (coor.latitude + latitude, coor.longitude+longitude);
  return nouvPoint;
}
std::istream& operator >> (std::istream& is, Coordonnees& coor) {
  char po, virgule, pf;
  is >> po;
  if(is){
    is >> coor.latitude >> virgule >> coor.longitude >> pf;
    assert(po=='(');
    assert(virgule==',');
    assert(pf==')');
    coor.longitude *= PI / 180.0;
    coor.latitude *=  PI / 180.0;
  }
  return is;
}

std::ostream& operator << (std::ostream& os, const Coordonnees& coor) {
  os << "("
     << (coor.latitude * 180.0 / PI)
     << ","
     << (coor.longitude * 180.0 / PI)
     << ")";
  return os;
}
