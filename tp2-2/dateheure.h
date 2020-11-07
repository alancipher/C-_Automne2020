/* Squelette de départ TP2
 * TP2 - Traçage Pandémie
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://ericbeaudry.uqam.ca/INF3105/tp2/
 */
#if !defined(__DATEHEURE_H__)
#define __DATEHEURE_H__
#include <iostream>

class DateHeure{
  public:
    DateHeure();
    
    bool operator <(const DateHeure& date) const;
  
  private:
    // À compléter.
    
  friend std::ostream& operator << (std::ostream&, const DateHeure& date);
  friend std::istream& operator >> (std::istream&, DateHeure& date);
};

struct Intervalle{
    DateHeure debut, fin;
    friend std::istream& operator >> (std::istream& is, Intervalle& itervale);
    friend std::ostream& operator << (std::ostream& os, const Intervalle& itervale);
};

#endif
