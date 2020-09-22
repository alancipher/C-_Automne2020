#include <iostream>
using namespace std;

int main()
{
    int ageUtilisateur(18); //Une variable pour contenir l'âge de l'utilisateur
    
    int& maReference(ageUtilisateur); //Et une référence sur la variable 'ageUtilisateur'
     maReference = 20;
    //On peut utiliser à partir d'ici
    //'ageUtilisateur' ou 'maReference' indistinctement
    //Puisque ce sont deux étiquettes de la même case en mémoire

    cout << "Vous avez " << ageUtilisateur << "  ans. (via variable)" << endl;
    //On affiche, de la manière habituelle

    cout << "Vous avez " << maReference << " ans. (via reference)" << endl;
    //Et on affiche en utilisant la référence
    
    return 0;
}
