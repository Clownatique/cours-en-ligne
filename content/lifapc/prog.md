+++
title='prog'
draft=false
+++
... (prerequis)

# gestion memoire pendant l'execution

pile, tas, code charge: corresponds a des _segments de donnee_

## schema du segments de donnee en C++

- code
- pile
- tas (pour les donnees qui doivent survivre a la sortie dun bloc: askip c un farwest)
- rodata (constantes...)
- donnees globales (variables..)
  deux registres (attention c tres schematise..)
- 1 pour le pointeur dinstruction
- 1 pour le pointeur de pile
- tout le pilement/depilement se fait gerer par ce registre

## Usage de la pile

## lors de l'appel d'une fonction

on appelle ca un contexte (#frame)
on rappelle que laffectation se lit de droite a gauche

### pile

- d'autres donnees sont empilees
- le pointeur pointe sur la fonction
- le registre de pile avance du nombre d'octets de retour
- lors de return, on place la valeur au debut du contexte

## difference entre initialisaT/affectaI

.. a voir quand on verra les structs

### tas

quand on fait new/malloc, on sadresse a un groom, qui va nous trouver une place de parking, et garer notre voiture. apres il nous passe les cles, et c a nous de retrouver notre bagnole pour partir avec

le dereferencement, c le fait daller devant la voiture, vider les bagages etc...

quand on utilise delete, on dit juste au groom qu'il peut utiliser la place de parking

## ordre du pointeur de registre

-> la fonction main est pointe en premier

# allocation, outil memoire (prerequis)

## outil qui donne l'adresse

&

## outil qui trouve une place de parking

new

## outil qui libere une place de parking

delete

## outil qui va permettre de remplacer ce quon a garer

*(cle) un pointeur peut pointeur sur la pile
ou cle[0]
ou cle-> si on a garer une struct

## outil pour creer une place pour les cles de voiture dans sa poche

type* cle;

## outil pour se coller un memo sur ou sont les cles de la bagnole

type** memo;

## outil pour afficher la place de parking

& place

et la a partir de la slide 30 c la merde

## outil pour mettre un casque de realite virtuelle de voiture

type & nom_alias = emplacement_memoire;
ne peut pas etre une constante.

en realite, un alias est un pointeur, mais c masque

un alias permets de modifier la valeur d'une variable a distance
c pour ca il est important de preciser le mot cle const si on veut pas changer la valeur dune variable

# r-value/l-value

...

on peut avoir une reference en r-value

# types composites

## les types composites en c++

### class

syntaxe + infos

#### utilisation du mot static dans les classes:

sert

### struct

syntaxe + infos

## les destructeurs/constructeurs par defaut

existent autant avec les struct que les class, car ils permette simplement d'allouer la memoire et de la liberer.

### constructeur par copie

- Pour un type primitif la copie employée est une copie bit à bit
- copie des champs en suivant leurs propres lois de copie (types primitifs, class..)

  utilise dans ces dusages:
- quand une instance est définie et initialisée à partir d’une autre
- quand on passe une valeur de type Complexe à une fonction
- quand une fonction retourne une valeur de type Complexe

### destructeur

- unique

## notion de module

un module n'est pas forcement une classe: c un code specifique a quelque choseh
