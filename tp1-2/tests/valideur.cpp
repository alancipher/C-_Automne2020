/*   Valideur pour le TP1                                       *
 *   Pour compiler: g++ -o valideur valideur.cpp                *
 *   INF3105 - Structures de données et algorithmes             *
 *   UQAM / Département d'informatique                          *
 *   http://ericbeaudry.uqam.ca/INF3105/tp1/                    */
 
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, const char** argv){
    if(argc<3){
        cout << "Syntaxe : ./valideur votre-reqN+.txt solution-reqN+.txt " << endl;
        return 1;
    }

    ifstream fsVotre(argv[1]);
    if(fsVotre.fail()){
        cout << "Échec d'ouverture: " << argv[1] << endl;
        return 2;
    }
    ifstream fsSolution(argv[2]);
    if(fsSolution.fail()){
        cout << "Échec d'ouverture: " << argv[2] << endl;
        return 3;
    }

    int nbReq=0;
    int nbNomRouteCorrects = 0;
    int nbNumerosCorrects = 0;
    int nbResultsCorrects = 0;
    
    while(fsSolution && fsVotre){
        int numPorteSolution = -1;
        int numPorteVotre = -2;
        string nomRouteVotre = "y";
        string nomRouteSolution = "zzz";

        fsVotre >> numPorteVotre >> nomRouteVotre;
        fsSolution >> numPorteSolution >> nomRouteSolution;
        if (numPorteVotre == -2 || numPorteSolution == -1)
            break;
        nbReq++;
        if(numPorteVotre == numPorteSolution)
            nbNumerosCorrects++;
        if(nomRouteVotre == nomRouteSolution)
            nbNomRouteCorrects++;
        if(abs(numPorteVotre - numPorteSolution) <= 2)
            nbResultsCorrects++;
    }

    fsSolution.close();
    fsVotre.close();

    cout << "Nombre de lignes traitées:" << nbReq << "\n";
    cout << "Nombre de résultats correctes pour:\n";
    cout << "Num\tRoute\rNum+/-2\n";
    cout << nbNumerosCorrects << '\t' << nbNomRouteCorrects << '\t' << nbResultsCorrects << '\n';

    return 0;
}
