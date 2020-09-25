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


double Coordonnees::distance(const Coordonnees& coor) const {
  double s1 = sin((coor.latitude-latitude)/2);
  double s2 = sin((coor.longitude-longitude)/2);
  return 2*RAYONTERRE * asin(sqrt(s1*s1 + cos(latitude)*cos(coor.latitude)*s2*s2));
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

