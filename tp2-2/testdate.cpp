/* Squelette de départ TP2
 * TP2 - Traçage Pandémie
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://ericbeaudry.uqam.ca/INF3105/tp2/
 */
#include <sstream>
#include <vector> // l'utilisation de std::vector est uniquement permise pour seulement les tests ici.
#include "dateheure.h"
//#include "arbreavl.h"

int main()
{
    std::cout << "Tests pour la classe DateHeure ..." << std::endl;
    std::stringstream str("0j_00h00m00s 0j_00h00m01s 0j_00h00m10s 0j_00h01m00s 0j_00h01m02s 0j_00h01m05s 0j_00h02m00s 0j_00h02m03s 0j_00h02m06s 0j_00h03m00s 0j_00h03m10s 0j_00h40m00s 0j_01h00m00s 0j_01h00m01s 0j_01h01m00s 0j_01h02m00s 0j_02h00m00s 0j_02h10m00s 0j_02h12m01s 1j_00h00m00s 1j_00h00m02s 1j_01h01m00s 2j_00h00m00s");
    std::vector<DateHeure> dates;
    // Recommandation : testez aussi ArbreAVL<DateHeure>
    // ArbreAVL<DateHeure> arbre;
    while(!str.eof()){
        DateHeure d;
        str >> d >> std::ws;
        std::cout << d << std::endl;
        if(str){
            dates.push_back(d);
            //arbre.inserer(d);
        }
    }
    
    // Test du comparateur
    for(unsigned int i=0;i<dates.size();i++)
        for(unsigned int j=0;j<dates.size();j++){
             if(i<j){
                 if(!(dates[i]<dates[j]))
                     std::cout << "Erreur : dates[" << i << "]<dates[" << j << "] : " << dates[i] << "<" << dates[j] << " retourne faux!" << std::endl;
             }else if(j<i){
                 if(!(dates[j]<dates[i]))
                     std::cout << "Erreur : dates[" << j << "]<dates[" << i << "] : " << dates[j] << "<" << dates[i] << " retourne faux!" << std::endl;
             }else{ // i==j
                 if(dates[j]<dates[i])
                     std::cout << "Erreur : dates[" << j << "]<dates[" << i << "] : " << dates[j] << "<" << dates[i] << " retourne faux!" << std::endl;
             }
        }
    std::cout << " --- FIN ---" << std::endl;
    
   
    return 0;
}

