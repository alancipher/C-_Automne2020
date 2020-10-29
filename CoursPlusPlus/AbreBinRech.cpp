template <class T>
class ArbreBinRech : public ArbreBinaire{
 public :
 bool contient (const t& element)const;
 const T* rechercher(const T& element) const;
 void inserer(const T& element);
  private :
const T* rechercher (Noeud * n , const T& element) const;
void inserer(Noeud*& n, const T& element);

};

template<class T>
bool ArbreBinRech<T>::contient(const T& element) const{
return rechercher(racine,element)!= nullptr;
}
template <class T>
const T* ArbreBinRech<T>:: rechercher(Noeud* noeud, const T& element)const{
if (noeud == nullptr)return nullptr;
if(element==noeud->contenu) return &(noeud->contenu);
if(element<noeud->contenu)
  return rechercher(noeud->gauche, element);
else
  return rechercher(noeud-.droite, element);
}
template<class T> 
void ArbreBinRech<T>:: inserer( const T& element){
  inserer(racine, element);
}
template <class T>
void ArbreBinRech<T>:: inserer(Noeud*& noeud, const T& element){
if (noeud == nullptr)
   noeud = new Noeud(element);
if (element == noeud-> contenu) return;
if(element <noeud->contenu)
   inserer(noeud->gauche,element);
else
  inserer(noeud->droite, element);
}
