+++
draft = false
title = "Ocamel"
+++

aha ce langage ca ma toujours give camel genre les cigarettes tas capte
sauf que depuis ce cm, ca a pas la meme vibe

## types en ocaml

int, operations arithmetique classique
float, sans le modulo, attention a preciser quon agit sur des float (en mettant un point)
bool (et, ou, comme en C, ya til un non ?)
char ()
string

on peut pas combiner les operateurs

## variables

on a une dummy variable (comme en python, python`for _ in range(entier):`)
les appels de fonction sont proprietaires
distinction globale/locale importante

### variables locales

let var = expr
in expr

### variables globales

let var = expr;;

### les variables fonctions

appel:syntaxe similaire quen LISP, (nom_func arg1 arg2), parantheses non obligatoire
creation:

```ocaml
let nom_func (arg1:type1): typeretour =
  expr_resultat;;
```

## type

```ocaml
type mon_type_somme =
  | Cons1
  | Cons2
  ;;
```

Un type somme est un type ou les valeurs possible sont definis a l'avance
en vrai, c un peu comme les struct en c++ (si je dois faire des liens ahza)

## types complexes:

les n uplets est une aggregation de plusieurs valeurs.

`("un",1)` est de type `string * int`

## declarer un type complexe

un type inductif, est defini avec des regles bien precises, (et souvent avec lui meme)

## filtrage de motif : une fonction qui trie

faut un peu voir ca comme des regexp ?!

```ocaml
match Lundi with
| Mardi -> 2
| Mercredi -> 3
| Lundi -> 1
| Vendredi -> 5
| Dimanche -> 7
| Samedi -> 6
| Jeudi -> 4
;;
("ici l'expression match with renvoie int:1")
```

le filtrage de motif on peut le voir comme un switch case
il fait la correspondance d'une expression avec une autre expression

une **expression** peut correspondre a des fonctions ou des valeurs.

### loperateur of

c juste un moyen de dire que le constructeur de ce type de donnee est composee de..

### l'operateur ()
