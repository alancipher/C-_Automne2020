/* Squelette de départ TP2
 * TP2 - Traçage Pandémie
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://ericbeaudry.uqam.ca/INF3105/tp2/
 */

#if !defined(__HISTORIQUE_H__)
#define __HISTORIQUE_H__

#include <string>
#include "arbremap.h"
#include "dateheure.h"

using namespace std;

/** Un objet de type Historique :
    - contient des traces et offre un (représentation, partie privée);
    - offre une interface public pour ajouter des trace et exécuter des requêtes.
 */
class Historique{
  public:
   
    // Ajouter une trace
    void     trace(DateHeure dh, const string& lieu, const string& nompersonne);
    
    // Les 4 types de requête
    ArbreAVL<string> localiser(const Intervalle&, const string& nompersonne) const;
    ArbreAVL<string> presences(const Intervalle&, const string& nomlieu) const;
    ArbreAVL<string> frequentations(const Intervalle&, const string& nompersonne) const;
    int      duree_rencontres(const Intervalle&, const string& nompersonne1, const string& nompersonne2) const;
    
  private:
    // À Compléter.
};

#endif
