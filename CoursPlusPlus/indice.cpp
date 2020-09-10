#include <iostream>

using namespace std;

int main (){

/* int tab1[5], tab2[5];

for(int i=0; i<5; i++){
tab1[i]= i; tab2[i] = i + 10;
}

for (int i=0; i<16; i++) cout <<" "<<tab1[i];

cout<<endl;

for(int i=0; i<15; i++){
tab1[i]= 99-i ;

}


for(int i=0; i<5; i++){
cout<< " " <<tab1[i];              
}
 cout << endl;

for(int i=0; i<5; i++){
cout << " " << tab2[i];           
}

cout << endl; 

int n = 0;
int *p = &n;
*p = 5; // effet : n = 5



cout<< "n=" << *p ;

cout <<endl;


int tableau [10];
int somme = 0;
int* fin = tableau + 10 ; // pointe sur lelement suivant le dernier element du tab

for (int* i=tableau; i<fin; i++){ 

somme += *i;
cout<< " " <<somme;
}
*/

int n = 2;
int& ref_n = n; // decalaration de la reference 
n = 3;
cout<< "ref_n="<< ref_n;
cout<< endl;

return 0;
}
