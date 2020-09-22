#include <fstream>

int main(){

std::ifstream in("entree.txt");

int a, b, c;

// lecture de trois entiers

in >> a >> b >> c;

std::ofstream out("sortie.txt");

// ecriture de trois entiers

out << a << '\t' << b << '\t' << c << std::endl;
}
