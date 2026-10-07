// LIFAP6 - R. Chaine

#ifndef _LISTE
#define _LISTE

#include "element.h" //offrant le type Elem

class ListeTriee; // declaration

class Cellule
{
    friend class ListeTriee;

    private :
        Elem info;
        Cellule *psuivant;
};

class ListeTriee
{
    public :
    //Constructeurs-------------------------------------------------------------
    ListeTriee();
    //Postcondition : la liste *this est  initialisée comme étant vide
    ListeTriee(const ListeTriee & l);
    //Postcondition :  la liste *this est initialisée en copie profonde de l
    //         (mais elles sont totalement independantes l'une de l'autre)
    
    //Destructeur---------------------------------------------------------------
    ~ListeTriee();
     //Postcondition : l'espace occupé par *this  peut-être restitué
    
    //Affectation---------------------------------------------------------------
    // ListeTriee & operator = (const ListeTriee & l);
    //Précondition : aucune
    //       (la liste *this à affecter et l doivent être initialisées)
    //Postcondition : la liste *this correspond à une copie profonde de l
    //           (mais elles sont totalement independantes l'une de l'autre)
    
    bool testVide() const;
    //Précondition : aucune
    //               (*this initialisée)
    //Résultat : true si *this est vide, false sinon
    
    Elem premierElement() const;
    //Précondition : testListeTrieeVide(l)==false
    //Résultat : valeur de l'Elem contenu dans la 1ere Cellule
    
    Cellule * premiereCellule() const;
    //Précondition : aucune
    //               (*this initialisée)
    //Résultat : adresse de la premiere cellule de *this si this->testVide()==false
    //           nullptr sinon
    //           Attention : la liste *this pourrait ensuite etre modifiée à travers
    //           la connaissance de l'adresse de sa première cellule
    
    Cellule * celluleSuivante(const Cellule *pc) const;
    //Précondition : pc adresse valide d'une Cellule de la ListeTriee *this
    //Résultat : adresse de la cellule suivante si elle existe
    //           nullptr sinon
    //           Attention : la liste *this pourrait ensuite etre modifiée à travers
    //           la connaissance de l'adresse d'une de ses cellules
    
    Elem elementCellule(const Cellule * pc) const;
    //Précondition : pc adresse valide d'une Cellule de la ListeTriee *this
    //Résultat : valeur de l'Elem contenu dans la Cellule
    
    void affichage() const;
    //Précondition : aucune
    //               (*this initialisée)
    //Postcondition : Affichage exhaustif de tous les éléments de *this
    
    void vide();
    //Précondition : aucune
    //               (*this initialisée)
    //Postcondition : this->testVide()==true (tous les éléments sont retirés)
    
    // void ajoutEnQueue(const Elem & e);
    //Précondition : aucune
    //               (*this et e initialisés)
    //Postcondition : L'Elem e est ajouté en fin de la liste *this
    
    //OPERATIONS QUI POURRAIENT ETRE AJOUTEES AU MODULE LISTE
    
    Cellule * rechercheElement(const Elem & e) const;
    //Précondition : aucune
    //               (*this initialisée)
    //Résultat : Adresse de la première Cellule de *this contenant e, nullptr sinon
    //           Attention : la liste *this pourrait ensuite etre modifiée à travers
    //           la connaissance de l'adresse d'une de ses cellules
    
    void insereElementApresCellule(const Elem & e,Cellule *pc);
    //Précondition : pc adresse valide d'une Cellule de la ListeTriee *this
    //               ou nullptr si this->testVide()==true
    //Postcondition : l'element e est inseré après la Cellule pointée par pc
    
    void modifieInfoCellule(const Elem & e,Cellule *pc);
    //Precondition : *this non vide et pc adresse valide d'une Cellule de *this
    //Postcondition : l'info contenue dans *pc a pour valeur e

    void insereCellule(const Elem & e);
 
    private :
        void ajoutEnQueueConnaissantUneCellule(const Elem & e, Cellule *pc);
        void affichageDepuisCellule(const Cellule * pc) const;
    //Donnees membres-----------------------------------------------------------
        Cellule *ad;
        int taille;
};


#endif
