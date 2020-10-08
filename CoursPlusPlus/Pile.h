//#if !defined(_Pile___H_)
//#define _Pile___H_

//#include <assert.h>
#include <iostream>
#include <cstdlib>
#include namespace std;
#define SIZE 10

template <class T>
 class Pile{
  private:
  T *arr;
  int top;
  int capacity;

  public : 
     Pile();
    Pile (int size = SIZE);
   ~Pile();
   int taille() const;
   bool vide() const;
  const T& sommet() const ;
  void empile (const T& e);
   T depiler();
   //void depiler ();
  void depiler(T& e);


};

template <class T> 
Pile <T> :: Pile (int size)
{
 arr = new T[size];
 capacity = size;
 top = -1;
}


int main (){

Pile <string> pt(2);
return 0;
}
//#endif
