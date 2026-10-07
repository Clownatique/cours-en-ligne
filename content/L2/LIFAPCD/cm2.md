+++
title = "diagramme UML"
draft = false
+++

## module

une codebase (ensemble du code du projet) **doit** etre scinde en plusieurs modules

un module doit etre represente par un couple de .h/.cpp
il est necessaire de lister les signatures des fonctions
on change jamais les attributs/donnes de lobjet: on appelle uniquement des fonctions

ce qui est a faire pour modulariser au maximum son code:
separer son code en fonctionnalites

regrouper les fonctionnalites qui ont besoin des memes choses (donnes, operations sur les donnes) => 1 module
1 classe => 1 module
1 module => n fonctions

pour faire ca proprement on utilise un diagramme UML

## diagramme UML

1 diagramme c plusieurs classes et les liens entre eux
1 module c 1 ou plusieurs classes
1 classe = 1 boite decoupe entre public (ce a quoi les autres classes peuvent toucher) et privee (le reste donc)
classe la plus pointee dans le schema = la premiere classe a ecrire et tester

### notation en UML

- `+`: public
- `-`: prive
- fleches entre classe: relations entre classe

**une fleche de a vers b indique a a besoin de B**

si la fleche est pleine, cela implique que a a besoin de creer un b pour venir a ses fins
si la fleche est pointille, cela implique que a nas pas besoin de creer un b pour venir a ses fins

### isolation du module

on utilise pour isoler le plus possible des fonctions qui font office daccesseur/mutateur

accesseur quand la fonction permets de permets dacceder a une information
mutateur quand la fonction permets de permets de modifier une information

il est important davoir un equilibre entre tout mettre en prive, et trop mettre en public.

### exemples

- Indenter le code pour plus de lisibilité
- Ajouter des commentaires (préconditions, rôle d’une boucle etc.)
- Donner des noms explicites et en suivant les conventions.
- Créer des fonctions au lieu de copier/coller du code plusieurs fois
- Vérifier les désallocations de mémoire
- Gérer les erreurs (dans lordre croissant de ce que les profs preferent)
- assertions, exceptions
- codes d’erreur en retour de fonction
- indicateurs passés en paramètre en mode donnée-résultat
- etre explicites lors des itérations et récursions (surtout allocation/désallocation)
- précalcul dans des tables et simplification des équations (expressions booleennes egalement)
- utiliser les bons types
