/* Squelette de départ TP2
 * TP2 - Traçage Pandémie
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://ericbeaudry.uqam.ca/INF3105/tp2/
 */
#include "historique.h"


void Historique::trace(DateHeure dh, const string& nomlieu, const string& nompersonne){
}

ArbreAVL<string> Historique::localiser(const Intervalle& intervalle, const string& nompersonne) const{
    ArbreAVL<string> resultats;
    return resultats;
}

ArbreAVL<string> Historique::presences(const Intervalle& intervalle, const string& nomlieu) const{
    ArbreAVL<string> resultats;
    return resultats;
}

ArbreAVL<string> Historique::frequentations(const Intervalle& intervalle, const string& nompersonne) const{
    ArbreAVL<string> resultats;
    return resultats;
}

int Historique::duree_rencontres(const Intervalle& intervalle, const string& nompersonne1, const string& nompersonne2) const{
    return 0;
}

