#include <iostream>
#include <cassert> 
using namespace std;

int f(int *tab, int n){
int* nombres = new int[n]; 
int* comptes = new int[n]; 
int m = 0;
for(int i=0;i<n;i++){
int j=0; 
for(;j<m;j++)
if(tab[i] == nombres[j]){ 
cout << "ICI"<< endl;
comptes[j]++;
break; // sort du for j 
}
if(j>=m){
nombres[m] = tab[i]; 
comptes[m] = 1;
++m;
} 
}
int k = 0;
for(int i=0;i<m;i++)
for(int j=0;j<comptes[i];j++) 
tab[k++] = nombres[i];
assert(n==k); //arrête le programme si n!=k
return m; 
}




int main(){
// int n=0;
/*cin >> n; // taille du problème; hypothèse n>=1 

int* tab = new int[n];

for(int i=0;i<n;i++)
cin >> tab[i]; 
int m = f(tab, n); 
for(int i=0;i<n;i++)
cout << tab[i] << '\t'; 
cout << endl << m << endl; 
delete[] tab;

int x=0;
int z=x++;
int y=++z;
cout << ++x+y+z++;

for(int i = 0; i < 3; i++)
  cout << i;
for(int i = 0; i < 3; ++i)
  cout << i;*/

bool f(int* tab, int n) {
    if(n > 1)
        return tab[n-1] + f(tab, n/2);
    return tab[0];
}

int main(int argc, const char* argv[]){
    int n;
    std::cin >> n;
    int* tab = new int[n];
    for(int i=0;i<n;i++)
        std::cin >> tab[i];
    if(f(tab, n) > 10)
        std::cout << "f" << std::endl;
    return 0;
}
}














/*void allo();
int main(){
 allo();
//std::cout<<"Hello world  this is the INF3105 course" << std::endl;
return 0;
}
void allo(){
std::cout<<"Hello world  this is the INF3105 course" << std::endl;
}*/
