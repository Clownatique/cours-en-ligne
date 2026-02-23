+++
title = "td 3"
+++

## arbres binaires

```ocaml
type abi (*arbre binaire d'int*)
 | Vide
 | Noeud of int * abi * abi (*pour definir un triplet*)
```

En maths ca s'ecrirait: N x abi x abi (avec le produit de cartesien)

Appel au constructeur: `Type(parametres)`

les arbres suivants ne sont pas de recherches

0 int:
Vide
1 int:
Noeud(
les arbres suivants ne sont pas de recherches
4,Vide,Vide)
2 int:
Noeud(4,Noeud(Vide,Vide),Vide)
3 int:
plusieurs possibilites, comme pour celui avec 2 int
2 int:
Noeud(4,Noeud(Vide,Vide),Vide)
3 int:plusieurs possibilites, comme pour celui avec 2 int.

rappel sur les arbres binaires: Noeud(=,<,>)

Les constructeurs allouent juste de la memoire, ils ne peuvent appeller de
fonction (a ce niveau la de l'ue)

pour la 2:

```ocaml
let cons (n:int) (a:abi) : abi =
 match a with
  | Vide->
  |   Noeud(n,Vide,Vide)
  | Noeud(n',ag,ad)->
  |   if n < n' then (cons n ag) else (cons n ad)
```

Utilisation de cette fonction pour recreer les arbres precedents:

(cons 5 (cons 4 V))

On peut limiter la syntaxe pour quelque chose de plus simple:

```ocaml
let rec cons n a =
  (*corps fonction*)
```

## generalisation des arbres binaires

type generique: sans preciser d'entier

1.oups

```ocaml
type 'a abr (* arbre binaire de recherche/generique *) =
| Vide
| Noeud of 'a * 'a abr * 'a abr
```

2.renverse

```ocaml
let rec renverse ( abre: 'a abr):'a abr =
 match arbre with
  | Vide->Vide
  | Noeud(elt, ag, ad)->Noeud(elt,renverse(ad),renverse(ag))
```

3. question

parce que c pas le meme type donc ce sera bizzare

4. association de liste a arbre

exemple darbre du type (list)
Noeud(4,'xy',Noeud((5,"ww"),Noeud(6,"zx"),Vide),V)

```ocaml
let rec assoc (e :'b) (arbre:('b x 'c) abr): 'c list =
 match arbre with
  | Vide->[]
  | Noeud((k,v),ag,ad)
     (*->if k =e then v::(assoc e ag)::(assoc e ad)*)
     (* ! on peut pas rajouter une liste a une liste*)
     -> if k = e then (v::(assoc e ag)) @ (assoc e ad)
     (* loperateur arobase rends la concatenation qudratique*)
        else (assoc e ag) @ (assoc e ad)
```

5. on accede a la ligne de condition
   d'ailleurs la fonction = prends deux operandes DE MEME TYPE PUTAIN

6.

```ocaml
let rec inserer (e: 'a) (arbre: 'a abr) (cmp:'a -> 'a->bool): 'a abr =
 match arbre with
  | Vide->Noeud
  | Noeud(e',ag,ad)->
  if (cmp e e') then Noeud(e',(insere e ag cup), ad)
                else Noeud(e', ag, (insere e ad cup))
```
