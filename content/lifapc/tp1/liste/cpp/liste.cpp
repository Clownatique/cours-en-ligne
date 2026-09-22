#include <cstdio> 
#include "liste.h"
#include "element.h"

using namespace std;

Liste::Liste(){
    this->ad = nullptr;
    this->taille = 0;
}

// bool Liste::vide(){
//     return ((*this)->ad == nullptr);
// }

void Liste::ajoutEnTete(const Elem & e){
    // lors de cet appel on rajoute ladresse de la liste sur laquelle on agit (#ThisOuQuoi)
    Cellule* p = new Cellule;
    p->info = e;
    p->psuivant = this->ad;
    this->ad = p;
    this->taille++;
}

void Liste::affichage() const{
    Cellule* p = this->ad;
    cout<<'[';
    while(p != nullptr){
        cout<<p->info<<',';
        p = p->psuivant;
    }
    cout<<']';
}

void Liste::ajoutEnQueue(const Elem & e){
    Cellule* p = this->ad;
    if (this->testVide()){
        ajoutEnTete(e);
    } else {
        while(p->psuivant == nullptr){
            // recette de cuisine:
            // 
            p = p->psuivant;
        }
        p->info = e;
    }
}

Liste::~Liste(){
    Cellule* p = this->ad;
    // if (this->testVide()){
    //     ajoutEnTete(e);
    // } else {
    while(p->psuivant == nullptr){
        // recette de cuisine:
        // 
        p = p->psuivant;
    }
    p->info = e;
    // }
}

// void Liste::affichageDepuisCellule(const Cellule * pc) const{
//     cout<<pc->info;
// }
