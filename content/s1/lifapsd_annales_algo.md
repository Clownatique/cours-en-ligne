## 2024

### Q2

inserer element fonction
on appelle insererelementdepuisnoeud avec elt (récursif)

insererelementdepuisnoeud(ptr vers noeud, elt)
if !ptr est null
if elt<info: inserereltdepuisnoeud(filsgauche, elt)
if elt>info: inserereltdepuisnoeud(filsdroit, elt)

**pas réussi**
else
inserer quand le noeud est vide dcp

### Q5

sauverdanstabdyn(tab)

sauverdanstabdyndepuisnoeud(tab, noeud)
si estfeuille:
sauver info dans tab

sinon:
enfonction du parcours
sauverdanstabdyndepuisnoeud(tab,info)
sauverdanstabdyndepuisnoeud(tab,fg)
sauverdanstabdyndepuisnoeud(tab,fd)

correction: mauvaise condition 

### Q6

tableaudyn::triabr
abr vide;
for (int i = 0 ; i...)
  insererelement(el,abr);
}
tab.vider()
tab = abr::sauver dans tabdyn(abr);// il n y a pas de constructeur par copie d'arbre
donc on le fait à la main

1
### Q9

déjà fait c simple

### Q10

traiter

## 2023

### Q3

insererelement

void arbre::insererelementdepuisnoeud(element,noeud)
si le noeud est null:
  créer le noeud
  info = 
  Noeud = 
  fg, fd = nullptr
sinon
  inserer

#### Q4
en v2v: stocker en mémoire toutes les paires de fg/fd, afficher l'info,
et recommencer pour tout le stock des paires fils gauche fils droit

### Q5


int nombre occurence depuis noeud
if noeud = nullptr
  return 0
if info = element {
  int trouve = 1
}
return trouve + nombreoccdepuisnoeud(fg, el) + nombreocc..;(fd,el)
bah non !! puisqu'à partir du moment ou on trouve l'elt, on a juste
à remonter le nb docc

### Q8

on boucle sur chacun des élements: on va simplement
récup l'espérluette (l'adresse) de chaque elt et le mettre dans le nv tab

### Q10


on boucle sur chacun des élements:
on va ensuite récup l'adresse,
faire un sizeof(adresse_elt_i)
allocation de l'espace pour la valeur
affectation avec un déréf de l'adresse_elt_i

## 2022

### Q3

simple boucle ou on cherche si la valeur est présente renvoie -1 à la fin,
et condition pour renvoyer i

### Q5

avant d'ajouter, vérifier si l'elt existe pas déjà

### Q7
intersection: pour tout les elts vérifie si elt présent dans i
si tel est le cas, ajoute le dit elt dans un nouveau ensemble

sousensemble:
vérifie si intersection de sous ensemble et ensemble = au sous ensemble

### Q9:

avant d'ajouter un elt,on vérifie si taille_utilisee == capacite
  on crée un nv tableau vide (new [capacité*1.5]) /!\ bien penser à mettre un (int)
  enfin on mets à jour l'instance
  on boucle pour recopier chaque case de l'ancien dans nv 
  enfin on mets à jour l'instance
  bien penser à supprimer
  /!\ mettre l'ancien dans temp,
  pour enfin supprimer temp
  (et pas ad (peut avoir des pbs si le tab est déjà utilisé jsp quoi))

et on l'ajoute enfin (tab[taille_utilisee+1])

### Q10:

