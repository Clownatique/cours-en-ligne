+++
title = 'nicolas tu me regales'
+++

## introduction (types de memoires)

presentations des types de peripheriques

## comment est mis la memoire

### le stockage physique

on peut voir comme un gros tableau avec des decoupages

### le stockage vue par lend user

un fichier est un gros tableau doctets
un fichier a des attributs (date de creation, dernier acces, permission)

tout ces attributs sont fournis grace au systeme de fichier

## systeme de fichier

mais c bcp de choses un systeme de fichier non ?

oui, c fourni par l'os (c un composant)
concretement la memoire est represente par des structures de donnes diverses (btree, inoeuds, block)

l'os fournit effectivement des appels systemes pour lire a une adresse precise, etc...

## les fichiers

### types et format de fichiers

#### format de fichier (type mime)

2 grands formats possibles(trouvable avec la commande file)
se remarque par:

- lextension sur windows,
- magic number(place en debut de fichier) sur linux (et aussi avec lextension)

##### lisibles

(avec un encodage, mais decodable nativement => on peut utiliser iconv pour changer cet encodage)
ce format change selon l'os, s/o les symboles speciaux (retour a la ligne qui differe notamment)

##### binaires et executables

le format des binaires peut etre de l'elf (comme dans strangers things mdrrrr)
cela varie selon le processeur et larchitecture globalement
!! on peut aussi avoir des scripts ecrits consideres comme des executables grace a un shebang

**shebang**: `#!/chemin/vers/executeur`

on peut utiliser la commande hexdump pour voir un binaire

#### type de fichier (binaire,repertoire,lien)

sous unix, tout est fichier (meme ta carte graphique)

le type de fichier est indique sur le premier caractere quand on fait ls ou les possibilites

- (-) fichiers reguliers : donne ou progrannes (binaire*)
- (l) lien -> source
- (d) dossier (directory you understand :p)
- (c) pipe, sockets (se trouvent generalement dans /dev/)
- (b) bloc de donnees (utiles pour les fichiers de partition)

### mode de lecture des fichiers

#### acces sequentiel

#### acces indexe

/!\: A RATTRAPER

#### comment utiliser ces fichiers ?

avec des appels systemes (comme ceux avec fstream, et les fichiers reguliers)
il y a aussi des fichiers crees par des appels systeme (qui sont interessant a manipuler)

quand on ouvre un fichier, on dispose de 3 descripteur de fichiers

- 0
- 1
- 2

#### open()

fonction posix pour ouvrir un fichier.

open(pathfilename, flags) -> renvoie un entier

- dans pathfilename on a le chemin du fichier

- dans les flags on doit preciser si on veut lire, ecrire, ou lire ecrire
  on peut aussi preciser si on veut vider le fichier, afficher la suite

=> alors oui je pourrais faire des flashcarte sur tout les flags possible, mais ce serait trop long.

je devrais plutot savoir que man

#### write (via un descripteur de fichier)

write(descripteur de fichier, adresse,nombre doctets ecrits voulu) -> renvoie le nombre doctets ecrit

si rien na ete ecrit et que le res c 0:(0,0001% des cas )

#### read (via un descripteur de fichier)

read(descripteur de fichier, adresse,nombre doctets lu voulu) -> renvoie le nombre doctets lu

si rien na ete lu on a voulu lire la fin du fichier

#### close c important de le faire

## systeme de fichiers

### rappel avec le disque dur physique

un hdd c des disques magnetiques rigides, et ld hdd nest capable de lire que des petites portions:
il faut le moins possible le fragmenter

### exemple de ce que va faire un systeme de fichier

- il va adresser chaque bloc
- trouver de la place pour de nouveaux fichiers
- pour chaque fichiers, bien considerer les bons blocs

en fat (file allocation table) le systeme de fichier retient simplement ladresse du premier bloc. les prochaines adresses sont notes a la fin des blocs

avec des inoeuds (ext4 il me semble)
le systeme de fichiers utilise plein de mini fichiers

ce systeme de fichiers ne retient PAS le nom des fichiers (ils sont seulement dans les repertoires)

ext4 est plus complexe, mais plus extensible

## gestion des droits

## 
