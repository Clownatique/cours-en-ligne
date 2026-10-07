+++
title ="td1"
done = true
draft = false
+++

## petits rappels de notations

$$ \lambda x f(x)\equiv $$

une abstraction
appel dune fonction:
toutes les fonctions sont anonymes (en lambda calcul)

tsais jai limpression le lambda calcul c une histoire de recreer le typage

((lamda f lambda x (f x)lambda y (y+y)) 5) rightarrow (lambda x (f x [f := lambda y . y^2]))
= (lambda x . (lambda y . y^2 x)_E 5_f)
rightarrow^x (lambda y y^2 x)[x:=5]
= (lambda y . y^2 5)
rightarrow y^2 [y=5]=5^2=25

2 beta reductions
d

## td 1 exo 1. 5) (super fonction a 2 parametres)

$$ (lambda x (lambda y(x+y) x ) 5)$$

sous forme dun arbre:
(@((\lambda x (@ (\lambda y x+y)x n))5))

### faire 2 beta reduction en partant de lexterieur vers linterieur (a faire)

on devrait trouver 10

### faire x beta reduction en partant de linterieur vers lexterieur(a faire)

pareil

=> ocaml utilise la premiere strategie

## td 1 exo 6)

(lambda x ((x lambda y (y+z))+(x lambda z (z * 3))) (lambda u . lambda w (w u )5))

donc faut trouver que ce truc est bien un number.

enft le but de lexo c de trouver le type des fonctions.
pour ca, en partant du bas, on remonte de larbre en faisant gaffe a ce qui est dit dans lenonce

## td 1 exo 12

(lambda x.(x+5) (lambda z z 2))
