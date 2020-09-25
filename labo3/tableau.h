/* Squelette pour classe générique Tableau<T>.
 * Lab3 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://ericbeaudry.uqam.ca/INF3105/lab3/
 */

#if !defined(_TABLEAU___H_)
#define _TABLEAU___H_

#include <assert.h>

template <class T>
class Tableau{

  public:
    Tableau(int capacite_initiale=4);
    Tableau(const Tableau&);
    ~Tableau();

    // Ajouter un element à la fin
    void           ajouter(const T& element);
    // redimensionner 
    void redimensionner();
    // Vider le tableau
    void           vider();
    // Retourne le nombre d'éléments dans le tableau
    int            taille() const;

    // Insère element à position index. Les éléments à partir de index sont décalés d'une position.
    void           inserer(const T& element, int index=0);

    // Enlève l'element à position index. Les éléments après index sont décalés d'une position.
    void           enlever(int index=0);

    // Cherche et retourne la position de l'élément. Si non trouvé, retourne -1.
    int            chercher(const T& element);

    const T&       operator[] (int index) const;
    T&             operator[] (int index);

    bool           operator == (const Tableau<T>& autre) const;
    Tableau<T>&    operator = (const Tableau<T>& autre);

  private:
    T*             elements;
    int            nbElements;
    int            capacite;
};


// ---------- Définitions -------------


template <class T>
Tableau<T>::Tableau(int capacite_)
{
    // À compléter
capacite = capacite_;
nbElements = 0;
    elements = new T[capacite]; // cette ligne n'est peut-être pas bonne.
}

template <class T>
Tableau<T>::Tableau(const Tableau& autre)
{
    // À compléter
capacite =autre.capacite;
nbElements= autre.nbElements;
elements = autre.elements;
}

template <class T>
Tableau<T>::~Tableau()
{
    // À compléter
  delete [] elements;
  elements = nullptr;
}

template <class T>
int Tableau<T>::taille() const
{
    // À compléter
    return this -> nbElements;
}

template <class T>
void Tableau<T>::ajouter(const T& item)
{
    // À compléter
assert(nbElements <= capacite);
if (nbElements == capacite)
redimensionner();
   elements[nbElements++] = item;
}

template <class T>
 void Tableau <T> :: redimensionner (){
  capacite*=2;
  T* temp = new T[capacite];
  for(int i=0; i < nbElements ; i++){
    temp[i] = elements[i];
}

    delete [] elements; 
   elements = temp;
}

template <class T>
void Tableau<T>::inserer(const T& element, int index)
{
    // À compléter
}

template <class T>
void Tableau<T>::enlever(int index)
{
    // À compléter
}

template <class T>
int Tableau<T>::chercher(const T& element)
{
    // À compléter
    // Voir la fonction Tableau<T>::contient() dans les notes de cours (Section 4.7).
    // Il suffit de l'adapter pour retourner la position au lieu d'un booléen.
    return -1;
}

template <class T>
void Tableau<T>::vider()
{
    // À compléter
//capacite = 0;
nbElements =0;
//capacite = nbElements;
//delete  [] elements;
 //elements = new  T[capacite];
}

template <class T>
const T& Tableau<T>::operator[] (int index) const
{
    // À compléter
 assert (index <nbElements);
    return elements[index];
}

template <class T>
T& Tableau<T>::operator[] (int index)
{
    // À compléter
     assert (index<nbElements);
    return elements[index];
}

template <class T>
Tableau<T>& Tableau<T>::operator = (const Tableau<T>& autre)
{
    // À compléter
if(this==&autre) return *this;
nbElements = autre.nbElements;
if(capacite<autre.nbElements){
  delete[] elements;
  capacite = autre.nbElements;
  elements = new T[capacite];
}
for(int i=0;i<nbElements;i++){
 elements[i] = autre.elements[i];
}
    return *this;

}

template <class T>
bool Tableau<T>::operator == (const Tableau<T>& autre) const
{
    // À compléter
if (this == &autre) return true;
if (nbElements != autre.nbElements) return false;
for (int i=0; i<nbElements; i++)
    if (elements[i] != autre.elements[i])
         return false;
     return true;

   // return true;
}

#endif //define _TABLEAU___H_