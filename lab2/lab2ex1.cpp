#include <iostream>
using namespace std;

int main(){
    int a=1, b=2, c=3, d=4;//  declaration des entier a,b,c,d
    int* pa=&a;        // declaction et initialisation du pointeur pa  pa est un poiteur vers une variable de type int  & devant a represente une adresse memoire 
// pa pointe vers l'adresse memoire de a ie pa a en memoire ladresse ou se trouve la variable a en memoire 
    int* pb=&b;   // declaration et initialisation du pointeur pb  vers b
    int* pc=&c, *pd=&d;
    cout << "a=" << a << "\tb=" << b << "\tc=" << c << "\td=" << d << endl;
    // affichage de a, b,c, d
    cout << "pa=" << pa << "\tpb=" << pb << "\tpc=" << pc << "\tpd=" << pd << endl;
   // affichage des pointeurs pa pb et pc et pd
 *pa = 4; // dereferencement de pa
  
    cout << "a=" << a << "\tb=" << b << "\tc=" << c << "\td=" << d << endl;
    cout << "pa=" << pa << "\tpb=" << pb << "\tpc=" << pc << "\tpd=" << pd << endl;
     
      pa = pb;// pa pointe desormais vers pb 
    *pa = 8; // dereferencement de pa qui prend 8
    cout << "a=" << a << "\tb=" << b << "\tc=" << c << "\td=" << d << endl;
    cout << "pa=" << pa << "\tpb=" << pb << "\tpc=" << pc << "\tpd=" << pd << endl;
    c = 10;
    d += *pd;
    cout << "a=" << a << "\tb=" << b << "\tc=" << c << "\td=" << d << endl;
    cout << "pa=" << pa << "\tpb=" << pb << "\tpc=" << pc << "\tpd=" << pd << endl;
    return 0;
}
