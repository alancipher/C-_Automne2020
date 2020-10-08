/* Squelette de départ TP1
 * TP1 - Géocodage inversé
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://ericbeaudry.uqam.ca/INF3105/tp1/
 */

#if !defined(__CARTE_)
#define __CARTE_

#include <string>
#include "coordonnees.h"
#include "tableau.h"

class Route{
  // À compléter.
  // Une route devrait avoir un nom, tableau de points, deux numéros de porte (début et fin du segment).

private :
     char * nom ;
     Tableau <Coordonnees> cor;
      int  porteDebut;
     int portFin;
     friend std::istream& operator >> (std::istream&, Route&);
     friend class Carte;
};

class Carte{
  // À compléter.
  public:
    //Carte ();
    std::string geocodageinverse( const Coordonnees& c) const;

  private:
    Tableau<Route> routes;

  friend std::istream& operator >> (std::istream&, Carte&);

};

#endif
