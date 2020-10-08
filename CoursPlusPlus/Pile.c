
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
   bool estPleine();
   bool vide() const;
  const T& sommet() const ;
  void empiler (const T& e);
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

template <class T>
void Pile<T>::  empiler(const T& e)
{
  if (estPleine()){
 cout << "overflow program Terminated";
       exit (EXIT_FAILURE);
}
 cout << "Inserting "<< e << endl;
 arr[++top] = e;

}


template <class T>
bool Pile <T> :: estPleine(){
return top == capacity -1; // or return size() == capacity 
}

int main (){

Pile <string> pt(2);
return 0;
}
//#endif
