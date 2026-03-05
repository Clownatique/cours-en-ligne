+++
title = "FOnctionnement d'openGL"
draft = false
+++

## avant de commencer

ce cours nous donne quelques cles pour comprendre ce qui se trame dans les entrailles
d'openGL:

Une compression approfondie n'est pas necessaire, mais essentielle.
GTK2Light le fait pour nous en gros.

Ce qui va nous interesser c'est comment on peut creer les formes etc.

## pipeline de rendu

un pipeline est la chaine d'operation effectue sur nos donnes pour representer
la scene souhaite

grossierement, pour tout les points, on cherche a projeter nos points en 3d sur
une image 2d (en l'occurence, il s'agit ici de l'ecran)

## API OpenGL

toutes les travaux ici se font avec l'api d'openGL
Il est interessant de considerer OpenGL comme une machine a etat:

Pour chaque donnee manipule, OpenGL affecte un etat par defaut.

le pipeline actuel est lui meme definir par des etats (comme le Z Buffer)

Pour passer d'un etat a l'autre, il suffit de faire
`glEnable()` ou `glDisable()`

pour revenir a nos points, on peut consider ces 2 approches:

### Objets -> Image

Les objets vont etre projetes sur l'image.
Cette approche est la moins couteuse, mais elle aura du mal a reproduire des
phenomenes physiques

### Oeil -> Objets

Des rayons vont etre projets depuis l'oeil. Tous ces rayons, vont traverser l'image:
cela va constituer les pixels de notre image.

Bien evidemment cela est plus couteux/long

## Quels sont nos reperes dans son monde

## Comment on projete les points sur notre image

## Comment on remplis nos surfaces sur notre image

### ZBuffer
