/*template <class T>
class Arbre {
 private :
void afficherPreOrdre(Noeud* n)const;
void afficherPostOrdre(Noeud* n)const;
  public :
void afficherPreOrdre() const;
void afficherPostOrdre() const;
 

};*/

template <class T >
class ArbreBinaire{
 public :
ArbreBinaire();
~ArbreBinaire();
void vider();
private :
class Noeud{
 T contenu;
 Noeud * gauche;
 Noeud * droite;

};
  Noeud * racine;
  vider(Noeud*);
};
// fonctions de la classe ArbreBinaire

template <class T > ArbreBinaire <T> :: ArbreBinaire () : racine(nullptr){}
template <class T > ArbreBinaire <T>:: ~ArbreBinaire(){
  vider();
}
template <class T> void ArbreBinaire<T>:: vider(){
 vider(racine);
 racine=nullptr;

}

template <class T> void ArbreBinaire<T>:: vider(Noeud* n){{
 if (n== nullptr) return;
 vider(n->gauche);
 vider(n->droite);
  delete n;
}

template <class> void ArbreBinaire<T>:: afficher_iordre(){

afficher_iordre(racine);
}
template <class T> void ArbreBinaire<T>:: afficher_iordre(Noeud* n){

if (n== nullptr) return;
afficher_iordre(n->gauche);
std::cout << n-> contenu << " ";
afficher_iordre(n->droite);
}
