#include <iostream>
using  namespace std;

/*
int somme(int* tab , int n ){
int s = 1;
for (int i = 0; i <n; i++){
  s+= tab[i];
  cout << tab[i]<< endl;
}
// s+=tab[i];

return s;

}
int main (){
int n = 0;
cin>>n;
int *tab = new int[n];

for (int i =0; i<n;i++)
cin >> tab[n];
cout << somme(tab,n)<< endl;
delete[]tab;
return 0;

}
*/

int * filterpaires(int* tab, int n, int& nbpaires){
nbpaires = 0; 
for (int i = 0; i<n; i++)
if (tab[i]%2 == 0) nbpaires++;
int * paires  = new int [nbpaires];
nbpaires = 0;
for (int i =0;i<n; i++)
if (tab[i]%2 == 0)
paires[nbpaires++] = tab[i];
return paires;



}

int main (){
int n,m;
cin >>n;
int* tab = new int [n];
for(int i = 0; i<n;i++)
 cin >>tab[n];
int * paires = filterpaires (tab, n, m);
for (int i =0; i<m; i++)

cout << paires[i] << endl;
delete []  paires;
delete [] tab;

return 0;
}
