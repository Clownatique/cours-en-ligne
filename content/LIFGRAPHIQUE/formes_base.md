+++
title = "fiche_forme_base"
draft = false
+++

## outils (primitive)

### GL_TRIANGLES_STRIP

## recette commune

Pour chaque forme de base:
on va d'abord initialiser un maillage et renseigner la primitive utilise

on va ensuite, instancier pour chaque maillage les normales (`.normal(Vector)`), puis les
point (`.vertex(Point)`)

## disque

Un disque est un cercle plein

### sommets

Pour $\alpha$ dans $[0,2\pi]$:

- x = $$ \cos(\alpha) $$
- y = 0
- z = $$ \sin(\alpha) $$

### normale

Le vecteur (0,1,0)

## cube

Un cube c'est _juste_ 6 carres, ou 12 triangles, ou 8 sommets.

on procede ainsi, avec des variables locales (tableau de tableau d'entier)

- on definit des 8 sommets
- on definit les 6 faces a partir des index des sommets
- on definit des normale pour chaque face

ensuite, pour chaque face, on ajoute la normale et les 4 sommets associes.

il est important de demander un nouveau strip a chaque face `.restart_strip`

## Tube

Un tube c des triangles qui sont positionnes de maniere a ce quon est un cercle
en haut et en bas

et oui le TD vous a menti: [**on ne realise pas ici un cylindre mais un tube**](https://fr.wikipedia.org/wiki/M%C3%A9taphysique_des_tubes)

Il est important de choisir un nombre de subdivision (on va pas tracer plein de mini
triangles sinon l'ordi d'ariane il va exploser)

Puis on **ajoute** notre normale mais on **definis** notre point (et ca on le fait 4 fois, pour faire 2
triangle)

Sauf qu'ici on va utiliser la methode triangle avec nos points definis

`TODO: bete d'animation ici`

En utilisant des `GL_TRIANGLES`

## cone

un cone cest un disque avec des triangles qui se rejoignent en un point au dessus
du disque

donc pour le disque faut aller voir [[ici]]
pour ce qui est de la methode:

on va utilsier des `GL_TRIANGLES_STRIP`
C'est les normales qui vont etre importantes (les triangles se definissent tout seul)

1. normale du premier triangle
2. un point sur le disque
3. normale du deuxieme triangle
4. le **sommet du cone**

## sphere

Pour la sphere je ferais plus tard la jai besoin d'une pause
