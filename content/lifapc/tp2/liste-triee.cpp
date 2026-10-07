// LIFAPC - R. Chaine

#include <cstdio>
#include "element.h" //offrant le type Elem
#include "liste-triee.h"
//#include <cassert> //Si on veut faire des tests de preconditions en mode debug


ListeTriee::ListeTriee()
{
    ad=new Cellule; //this->ad=nullptr;
    // non mais ca a un interet
    // dans le contexte circulaire
    ad->psuivant = nullptr;
    taille=0;
}

bool ListeTriee::testVide() const
{
    // return taille==0; //this->ad==nullptr;
    return (ad->psuivant == nullptr);
}

Elem ListeTriee::premierElement() const
{
    return ad->psuivant->info; //this->ad->info;
}

Cellule * ListeTriee::premiereCellule() const
{
    return ad->psuivant; //this->ad;
}

Cellule * ListeTriee::celluleSuivante(const Cellule *c) const
{
  return c->psuivant;
}

Elem ListeTriee::elementCellule(const Cellule * c) const
{
  return c->info;
}

void ListeTriee::insereCellule(const Elem& e){
  Cellule* w_pc= new Cellule;
  Cellule* pc = new Cellule;
  pc->info = e;
  w_pc = this->ad->psuivant;
  while( (w_pc->psuivant != nullptr) && (w_pc->info <= pc->info) ){
    w_pc = w_pc->psuivant;
  }
  // doit marcher donc si on est si la derniere cellule
  
  w_pc->info = pc->info;
  w_pc->psuivant = pc->psuivant;
  

}

#ifndef _RECURSIF 
void ListeTriee::affichage() const
{
  std::printf("ListeTriee");
  Cellule *temp=ad->psuivant; // Cellule *temp=this->ad;
  while(temp!=nullptr)
    {
      affichageElement(temp->info);
      temp=temp->psuivant;
    }
  std::putchar('\n');
}
#endif


// #ifndef _RECURSIF 
// void ListeTriee::vide()
// {
//   while(!testVide()) //while(!this->testVide())
//     {
//       suppressionEnTete(); //this->suppressionEnTete();
//     }
// }
// #endif

#ifndef _RECURSIF 
void ListeTriee::ajoutEnQueueConnaissantUneCellule(const Elem & e, Cellule *c)
// procedure interne au module : 
// *this NON VIDE et c est l'adresse d'une Cellule de *this
{
  //assert(!testVide()); //Si on veut faire des tests en mode debug
  Cellule *temp=c;
  while(temp->psuivant!=nullptr)
    temp=temp->psuivant;
  //temp pointe sur la derniere cellule
  temp->psuivant=new Cellule;
  temp->psuivant->info=e;
  temp->psuivant->psuivant=nullptr;
  taille++; // this->taille++;
}
#endif


// ListeTriee::ListeTriee(const ListeTriee & l)
// { 
//   this->ad->psuivant=nullptr;
//   this->taille=0;
//   if(!l.testVide())
//     {
//       Cellule *temp1=l.ad->psuivant; 
//       this->ajoutEnQueue(temp1->info);
//       Cellule *temp2=this->ad->psuivant;
//       temp1=temp1->psuivant;
//       while(temp1!=nullptr)
//       { //Il reste des elements a ajouter
//           this->ajoutEnQueueConnaissantUneCellule(temp1->info,temp2);
//           // la correction nous aide
//           // donc connaissantunecellule est la pour nous eviter de parcourir toute la liste
//           //
//           // le meilleur execice serait de garder le truc avec le si-sinon
//           temp2=temp2->psuivant; //Ainsi temp2 pointe sur la derniere cellule de *this
//           temp1=temp1->psuivant; //tmp1 pointe sur la premiere Cellule de l
//                                 // dont l'info n'a pas ete ajoutee a *this
//       }
//     }
// }

ListeTriee::~ListeTriee()
{
  this->vide();
}

// ListeTriee & ListeTriee::operator=(const ListeTriee & l)
// {
//   if (this!=&l)
//     {
//       this->vide();
//       if(!l.testVide())
// 	   {
// 	     Cellule *temp1=l.ad;
// 	     this->ajoutEnQueue(temp1->info);
// 	     Cellule *temp2=this->ad;
// 	     temp1=temp1->psuivant;
//          while(temp1!=nullptr)
// 	      { //Il reste des elements a ajouter
// 	        this->ajoutEnQueueConnaissantUneCellule(temp1->info,temp2);
// 	        temp2=temp2->psuivant; //Ainsi temp2 pointe sur la derniere cellule de *this
// 	        temp1=temp1->psuivant;
// 	      }
// 	   }
//      }
//   return *this;
// }

#ifdef _RECURSIF
// Version recursive de certaines fonctions/procedures
// pour lesquelles on a donne une version iterative plus haut

//Procedure interne au module
void ListeTriee::affichageDepuisCellule(const Cellule * c) const
{
    if(c!=nullptr) //il reste des cellules a afficher
    {
        affichageElement(c->info);
        affichageDepuisCellule(c->psuivant);//this->afficheDepuisCellule(c->psuivant);
    }
}

void ListeTriee::affichage() const
{
    std::printf("ListeTriee (rec) :");
    affichageDepuisCellule(ad); // this->afficheDepuisCellule(this->ad);
    std::putchar('\n');
}

void ListeTriee::vide()
{
    if(!testVide()) //  if(!this->testVide())
    {
        suppressionEnTete(); //this->suppressionEnTete()
        vide(); //this->vide()
    }
}

void ListeTriee::ajoutEnQueueConnaissantUneCellule(const Elem & e, Cellule *c)
//procedure interne au module :
// *this NON VIDE et c est l'adresse d'une Cellule de *this
{
    //assert(!testVide()); //Si on veut faire des tests en mode debug
    if(c->psuivant==nullptr)
    {
        c->psuivant=new Cellule;
        c->psuivant->info=e;
        c->psuivant->psuivant=nullptr;
        taille++; // this->taille++;
    }
    else
        this->ajoutEnQueueConnaissantUneCellule(e,c->psuivant);
}

#endif
