+++
title = 'Intro Au Lambda Calcul'
date = 2026-01-26T18:45:20+01:00
draft = true
+++

TOUT est fonction dans cette maniere de voir lalgo

## variables

On ecrit le lambda calcul a laide de variable. Peut on voir les variables comme des fonctions? (quon ne pourrait pas appeller?)
Les variables se sont des symboles.

♡ 	 est un lambda terme. est il une fonction, ou une variable ?
Pour ca, on va se pencher sur deux autres elements necessaires pour ecrire du lambda calcul.

## applications

On appelle jamais une fonction. On fait seulement des applications! (c a d on y applique quelque chose)

Pour signifier quon fait une application, on mets une fonction et une variable a cote.
Et si possible, on les mets entre parantheses.

Mais comment definir une fonction dcp ?

## abstraction

avant de definir une fonction il faut ecrire un lambda. quand on voit ca on est cense se dire attention, declaration de fonction

pour definir une fonction: lambda(symbole de la fonction).(ce que renvoie la fonction)

la ici en vrai on peut faire unr parallele avec lesprit dun bebe (qui a deux fonctions de base:lambda(bien).content et lambda(pas bien).qui renvoie pas content)

on se demande alors ou sont les maths dans cet histoire

pour faire des maths avec seulement des fonctions..

## Réductions

les reductions cest ce que fait le lambda calcul tout seul

on peut voir un enonce en lambda-calcul comme un arbre ayant des nœuds binaires (les applications), des nœuds unaires (les λ-abstractions) et des feuilles (les variables).
Les réductions[15] ont pour but de simplifier cet arbre

### bêta-contraction (ou β-contraction)

il ne faut pas confondre contraction avec equivalence !!!

(λx.u)v comme u[x := v].
On dit qu'un terme C[u] se réduit[16] en C[u'] si u est un rédex qui se β-contracte en u', on écrit alors C[u] → C[u'], la relation → est appelée contraction.

Exemple de contraction : (λx.xy)a donne (xy)[x := a] = ay.

On note →* la fermeture réflexive transitive[17] de la relation de contraction → et on l'appelle réduction. Autrement dit, une réduction est une suite finie, éventuellement vide, de contractions.

On définit =β comme la fermeture réflexive symétrique et transitive de la contraction et elle est appelée bêta-conversion, β-conversion, ou plus couramment bêta-équivalence ou β-équivalence.

La β-équivalence permet par exemple de comparer des termes qui ne sont pas réductibles l'un envers l'autre, mais qui après une suite de β-contractions arrivent au même résultat. Par exemple (λy.y)x =β (λy.x)z car les deux expressions se contractent pour donner x.

Formellement, on a M =β M' si et seulement si ∃ N1, ..., Np tels que M = N1, M' = Np et, pour tout i inférieur à p et supérieur à 0, Ni→ Ni+1 ou Ni+1 → Ni.

Cela signifie que dans une conversion on peut appliquer des réductions ou des relations inverses des réductions (appelées expansions).

On définit également une autre opération, appelée êta-réduction[18], définie ainsi : λx.ux →η u, lorsque x n'apparait pas libre dans u. En effet, ux s'interprète comme l'image de x par la fonction u. Ainsi, λx.ux s'interprète alors comme la fonction qui, à x, associe l'image de x par u, donc comme la fonction u elle-même.

ce quil faut bien comprendre c que les variables en vrai ya aucun parallele possible avec la vie. on peut rien y faire. jusquici ya pas grand chose a comprendre (c juste des vieux trucs quon mixe)
alors c super c histoires de fonction qui fonctionnent mais ou est le calcul ? puis meme je vois pas ce quelle calcule moi

et puis on calcule en quoi ? en banane, en tomate, en orange ?

## et donc la on parle des types

## dont le type number
