#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (){

string ligne ;
ifstream monFichier("example.txt");
if (monFichier.is_open()){
while(getline (monFichier,ligne)){
 cout<< line<< '\n';
}
  monFichier.close();

}
else cout << "unable to open file";

return 0;

}
