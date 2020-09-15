#include <fstream>
int main (int argc, char** argv){
int a,b;
 std::ifstream in ("nombres.txt");
// lire deux nombre depuis le fichier d'entree nombre.txt
in >>a>>b;
if (in.fail()){
 std::cerr << "il  y a eu un probleme lors de la lecture!"<< std:: endl;
}

int sommes = a+b;
std :: ofstream out ("somme.txt");
out << sommes<< endl;
return 0;
}
