#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream monFichier;
  monFichier.open ("example.txt");
  monFichier << "Writing this to a file.\n";
  monFichier.close();
  return 0;
}
