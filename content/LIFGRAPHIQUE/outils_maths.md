+++
title = "outils mathematique"
draft = false
+++

## outils mathematiques

pour decrire la scene on va utiliser un systeme de coordonnes.

pour se rappeller quel axe est lequel on utilise sa main droite (pouce x, index y majeur z)

sans surprise on peut utiliser des complexes (r, theta, phi)donc les points

on rappelle que le cote oppose c celui qui na aucun lien direct avec langle voulu
et le cote adjacent et bah il construit langle

la diapp 8 fait un rappel pour reconstruire des points polaires dans un systeme cartesien

on rappelle que les vecteurs c grosso une direction. le vecteur normale c celui qui est perpendiculaire a la surface voulu

je pense que le mieux pour comprendre ces assertions c de tester avec des points/vecteurs particuliers

point - point ca fait un vecteur (cf la formule du vecteur)
vecteur + vecteur ca fait un super vecteur
point + vecteur ca fait un nv point
point + point ca fait rien

important de comprendre que le vecteur op a les memes coordonnes que le point p

### vecteurs:

#### evidemment la norme

$$/sqrt{x^2+y^2+z^2}$$

#### le produit scalaire

jai limpression que ca aide a comprendre la relation entre deux vecteurs (et cest tres lie au cosinus)

#### la projection => donne un scalaire

n
quand on veut savoir la longueur dun vecteur quon projette sur un axe

#### le produit vectoriel (enfin!!)

relatif au sinus visiblement

a x b = a x b x sin(angle entre a et b)
faut passer par une matrice pour calculer le produit vectoriel (avec des coordonees)

#### equation dun plan

il faut au minimum 3 points pour un plan. (a partir de 4, on peut avoir des points qui sont deja sur le meme plan)

ou alors un point et vecteur, apres sur les diapo (22 notamment on comprends comment avec une mise en pratique bref)
mais dans ce cas il faut trouver le vecteur normal de ces 3 points et boum apres on revient a un plan avec une belle equation

#### equation parametrique dune droite

bon pareil diapo + cours de terminale okok

#### equation de cercle (2d et 3d)

bon un cercle c lensemble qui verifie x^2+y^2 = r^2

### les triangles

on aime bien les triangles en 3d parce que aha bah ca a 3 cotes

## interpolations

### interpolation lineaire

aoua lifami on se rappelle ici on utilise bcp dinterpolation lineaire.

en gros c une methode pour calculer un point a partir de deux autres
(cf photos des courbes de transitions sur blinderkitten)

## matrices

les matrices servent a definir des transformations: chaque point est multiplie par une matrice

transposee sert a :
additions de deux matrices:
multiplication sert a: au produit vectoriel tsais
propriete sur la non commutativite du produit: bah enft lordre des operations comptent tp quoi
inverse des matrices: bref faut recopier betement les slides

! bref la faut tout reecrire pcq dans tout les cas la prof elle veut passer par des matrices 4d

changement dechelle: matrice diagonale
rotation: on repasse dans les complexes pour calculer la pos de lobjet, puis matrice qui ressemble a ca:
cos theta -sin theta
sin theta cos theta
translation: on pourrait faire une bete addition, mais nn go rester dans les multiplications

en fait, pour sassurer quon garde le meme point en le bougeant, lessence de ca c pour garder les memes ratios

w ca vaut 1 sur le point a lorigine
concretement, la matrice de translation c une matrice identite, mais avec les coordonnes de point de base
