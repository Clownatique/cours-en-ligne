+++
title = "cm3, ou une lecture de documentation en amphi"
+++

pour programmer on utilise 3 outils

le compilateur de fichier
le compilateur de plusieurs fichiers (projets)
un programme de debogage

## GCC

la commande g++ compile un fichier cpp en binaire

cependant nous ne voulons pas systematiquement un fichier binaire final:

- car nos programmes sont separes en plusieurs fichiers separes
- mais aussi la flemme de recompiler notre projet des quon change quun seul fichier

=> on utilise alors plusieurs fichiers objets

### quelques flags utile

-Wall: affiche tout les messages de prevention
-c sarrete a la compilation dun ficher objet
-o precise le nom de la sortie
-I precise le nom dun repertoire avec des librairies (sous forme de de nom de dir) a inclure (chemin)
-l precise un fichier libraire
-L precise un repertoire avec des fichiers libraires
=> les librairies installes avec apt etc sont dans /usr/include
-ggdb inclus des informations de debug

### scenarios possibles

g++ exemple.cpp -o exec # un fichier cpp en son binaire associe
g++ exemple.o -o exec # des fichier o en leur binaire associe

## Compilation par fichier

un **Makefile** est un fichier qui facilite la compilation de plusieurs fichiers

### regles

dans un makefile on definit la plupart du temps des regles de compilation

### variables

Utile pour eviter la redondance!

**Syntaxe**: nom_var = valeur

### commandes lies au makefile

make: produit la premiere regle (implique de concevoir notre makefile de sorte a taper juste ca)
make nom_regle: produit la regle nom_regle

### la compilation automatique (via IDE)

On utilise un CMake! (autre regle, autre syntaxe, car objectifs differents)

## debuggage

on est souvent confrontes a des bugs

### bugs

liste non exhaustive

#### erreur de segmentation

signifie que notre programme a essaye dacceder a de la memoire auquel il navait pas acces

### debugger

nous aide a visualiser lexecution de notre programme

#### commandes

dabord on lance notre debugger: gdb nom executable

ensuite une invite de commande nous est propose:

run (commence lexecution de notre programme)
backtrace (localise la fonction et la ligne de la fonction si ya un bug: realise la trace des appels de fonction)
where (pareil sans forcement pour un bug)
list (affiche les lignes qui posent un probleme)
break (permets de placer un point ou la visualisation sarrete)
tbreak (pareil ?)
next (prochaine ligne)
step (prochain appel de fonction)
continue (reprends lexecution)
affiche la variable
