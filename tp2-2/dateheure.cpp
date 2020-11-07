/* Squelette de départ TP2
 * TP2 - Traçage Pandémie
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://ericbeaudry.uqam.ca/INF3105/tp2/
 */
#include <cstdio>
#include <iomanip>
#include <assert.h>
#include "dateheure.h"

DateHeure::DateHeure(){
  // À compléter : initialiser la date.
}

bool DateHeure::operator <(const DateHeure& d) const{
    // À compléter : comparer *this (l'objet courant) avec d.
    return false;
}

std::ostream& operator << (std::ostream& os, const DateHeure& d){
    int jours, heures, minutes, secondes;
    // À compléter : transférer la date d dans les champs.
    char chaine[40];
    sprintf(chaine, "%dj_%02dh%02dm%02ds", jours, heures, minutes, secondes);
    os << chaine;
    return os;
}

std::istream& operator >> (std::istream& is, DateHeure& d){
    char chaine[40];
    int jours, heures, minutes, secondes;
    char j, m, h, s, underscore;
    is >> jours >> j >> underscore >> heures >> h >> minutes >> m >> secondes >> s;
    assert(j=='j');
    assert(underscore=='_');
    assert(h=='h' && m=='m' && s=='s');    
    
    // À compléter : utiliser les variable jours,heures,minutes,secondes pour modifier l'objet d.
    
    
    return is;
}

std::ostream& operator << (std::ostream& os, const Intervalle& i){
  os << i.debut  << i.fin;
  return os;
}

std::istream& operator >> (std::istream& is, Intervalle& i){
  char crochetgauche, crochetdroit, virgule;
  is >> crochetgauche >> i.debut >> virgule >> i.fin >> crochetdroit;
  assert(crochetgauche=='[' && virgule==',' && crochetdroit==']');
  return is;
}

