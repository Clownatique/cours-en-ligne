#include "Arbre.h"
#include "ElementA.h"

Arbre::Arbre(){
  adRacine = nullptr;
}

Arbre::~Arbre(){
  vider();
}

bool Arbre::estVide() const{
  return (adRacine == nullptr);
}

void Arbre::insererElementDepuisNoeud(Noeud * &n, ElementA e){
  if (n == nullptr){
    n = new Noeud;
    n->info = e;
    n->fd = nullptr;
    n->fg = nullptr;
  } else{
    if (e > n->info){
      insererElementDepuisNoeud(n->fd, e);
    } else if (e < n->info) {
      insererElementDepuisNoeud(n->fg,e);
    } else{
      //ne rien faire car c bon
    }
  }
}

void Arbre::insererElement(ElementA e){
  Arbre::insererElementDepuisNoeud(adRacine, e);
}

void Arbre::afficherParcoursInfixe()
