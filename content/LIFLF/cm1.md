+++
title = 'cm1'
draft = false
+++

# objectifs du cours

- ocaml (bases et calculs)
- menhir (analyseurs)
- comprendre plus en detail la compilation 
- automate (comme en archi)


# caracteres puis mots ?

symboles ?
 - analyse morphologique ?? (pas dit dans le texte)
mots ?
 - analyse lexicale 2-3 cours (automate finis), grosse partie theorique dans le cours
expression : phrase ?
 - analyse syntaxique (est ce que les suites de mots forments des expressions correcteurs), automates a pile (pas a programme)
typage : sens de ses mots ?
 - analyse semantique, grosse partie theorique, typage, semantique des langages de programmation
compilation : transparaitre ce mots en langage machine (m1)


tout cela forme le langage.
betements, un langage est un ensemble de mots qui definit sur un alphabet finis (vocabulaire)

on definira un mot par une suite fini de lettre.
on definira egalement le mot epsilon, qui est de longueur 0 (important)

ex:
un chiffre cest une lettre, un nombre cest la representation de la quantite avec ces dits chiffres

## composition interne

- produit de concatenation: a ⋅ b = ab

la concatenation cest associatif et neutre.
si on a definit un produit, on peut definir un operateur de puissance (pourquoi ? jsp)

cette puissance va juste, repeter la concatenation... ok...

# langage = ensemble de mots.

(operation par ci par la... rien dinteresser a recopier)

si ce nest que un langage puissance 0 c egale au mot de longeur 0.
la concatenation sur un langage c un produit cartesien... grossierement.

literation dun langage, cest lensemble de tout les mots quil est possible decrire (c donc un ensemble infini de mots finis.)

le complementaire dun langage c lensemble des mots qui sont pas dans ce dit langage
V star c le vocabulaire en gros.

## decrire les langages

generation: permettent de generer des phrases.
automate : permettent de definir si un mot fait partie dun langage

# grammaire

ex: lensemble des phrases simples.
exemple de notation de grammaire

donc:

phrase -> sujet verbe preposition complement
sujet -> prenom | pronom
prenom -> [A-Z][a-z]+

...

(pas de majuscule chez xu, il faut le savoir c le point qui termine les phrases)

une grammaire c :

- un ensemble delements terminaux,

- un ensemble delements non terminaux,
 et lesemble des symboles non terminaux ne se trouvent pas dans lensemble delements terminaux, ou un autre truc bref regarder le cm slide 19

- un debut (source), souligne dans ce cours

- un ensemble de regle 

on peut definir une relation de reecriture, slide 20

donc pour prouver que 110 fait partie de la lamgue definie slide 19, on fait une espece de demonstration par recurrence.

N -> 1M -> 11M (par reecriture ?) -> 110M -> 110 (car M peut etre remplace par 󱃠)

ya une typo dans les slides, un truc est pas souligne.

donc slide 23

N -> N0 -> N00 -> 1100
et on peut pas faire le deuxieme mot.

et pour 111001:

N -> NN -> 11N -> 111001

le N invite a faire un calcul

## preuves etc

*dans la prochaine partie, c mieux davoir des notions darithmetique binaire...*

[[_]] : symbole de linterpretation dun mot au hasard

donc la grammaire slide 24 permets decrire nimporte quel nombre en binaire (dune maniere un bizzare ?)

slide 24:

en gros oui ils sont tous divisible par 3.
(julien a fait une meilleur slide que moi)

ok donc en gros slide 24 pour verifier ca, il faut voir ce que ca donne avec chaque regle

[[11]] divisible par 3
1001 aussi
N->N0... pareil
N->NN... pareil

voila et c mieux de faire par reccurence
a]




## notion de regularite en grammaire

les grammaires sont un sous ensemble de grammaire reguliere

et une grammaire est reguliere si deux contraintes

ca finit par au plus un char terminal
ca doit commencer par un char terminal

## grammaire reguliere reduite

### 1 seul char terminal a droite :

N->rien, N->qqch, N->term, N->qqchterm

### pas de regle pour passer dun term a un term

pour ca on enleve les redirections tsais

### pas de regle pour passer de qqch a un term

sauf pour epsilon

ma take:

S -> ab | e
T -> cdT | e | ab
U -> e | ab

sauf que:

- il faut mettre E -> rien
- on peut rajouter des regles

pour autant ca les empeches pas detre ambigu.

une ambiguite c quand on a deux moyens decrire la meme chose.

# automate

...

## automate finis

quintuplet avec

- vocabulaire (finis)
- Q ensemble detats
- q0  etat initial
- F, ensemble detats final (inclut dans les etats)
- T fonction de transition

lexecution ce sont des evenements sequentielles

la lecture (bah c le mot ?) (ou la concatenation des etats ?)

si lexecution finit sur un etat final, on dit quil est reconnu

on peut aussi decider dun ensemble de mots reconnus

il faut faire attention a faire des automates qui reconnaissent pas tout les mots

### lemme de letoile

et si on a des mots plus longs que lautomate, on va un peu brider notre automate (parce quil va devoir repeter des choses).

on appelle ca le lemme de letoile (de pompage selon notre altesse XU)

voila petite application du lemme detoile:

{a^n b^n | n in N }

sauf que notre automate peut reconnaitre a^n+m b^n comme a^n b^n 
