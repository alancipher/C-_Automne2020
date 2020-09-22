#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, char** argv){

std:: ifstream in ("entreee.txt");
int a,b,c;
// lecture des trois entiers 

in >> a>> b>> c;

std::ofstream out("sortie.txt");
out << a<< '\t' << b << '\t'<< c << std::endl;
/*int a,b;
cout << "Entrez deux nombres:" << endl;
cin >>a>>b;
int somme = a+b;
cout << "La somme est :"<< somme << endl;
*/

return 0;
}
