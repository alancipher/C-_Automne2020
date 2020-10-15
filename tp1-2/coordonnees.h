/* Squelette de départ TP1
 * TP1 - Géocodage inversé
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://ericbeaudry.uqam.ca/INF3105/tp1/
 */

#if !defined(_COORDONNEEs__H_)
#define _COORDONNEEs__H_
#include <iostream>

class Coordonnees {
  public:
  //  Tableau(int capacite_initiale=4);
  Coordonnees();
  Coordonnees (double lat_,double long_);

    double distance(const Coordonnees&) const;
   Coordonnees nouveauVecteur(const Coordonnees&)const;
   Coordonnees projectionCoor(const Coordonnees&)const;
    Coordonnees additionner(const Coordonnees&)const;
  public:
    double latitude;
    double longitude;

  friend std::ostream& operator << (std::ostream&, const Coordonnees&);
  friend std::istream& operator >> (std::istream&, Coordonnees&);
};

#endif
