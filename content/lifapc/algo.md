definir lentree et la sortie
on peut utiliser des relations entre la donnes dentree et de sortie

# Solution algorithmique

### eeeeee

definir des etapes precises

caracteristiques:

- abstraits
- loin de l'ordinateur
- partagent les memes operations (car agissent sur les memes structure de donnes.)

# Notion d'algorithme complet — Preuve

- tout ca on le voit en LC (prouver quun algorithme marche..)
- on appelle algorithme correct un algo qui pour nimporte quelle donnee satisfait les spécifications
- Il ne peut pas exister d’algorithme qui pour tout programme P et toute donnée D répond oui ou non à la question

## Outils de preuve

### Pour les algorithmes itératifs

- Test d'assertion
- Instruction de branchement (Jump, If, try…)
- Raisonnement par récurrence pour tester les invariants de boucle

### Pour les algorithmes récursifs

- Raisonnement par récurrence

## Détail du raisonnement par récurrence

- On distingue une partie de la structure complexe de données (géneralement petite, de l'ordre de 0 ou 1)
- Et des sous parties du tableau où il est nécessaire de prouver qu'un algorithme marche

# Analyse complexité — Classification des algorithmes

on peut pas utiliser le temps d'execution (trop de facteurs)
donc on compte le nombre d'instructions élémentaires
on fait ce calcul sur un temps asymptotique (n)
on fait des calculs d'ordre de grandeur

| Notation Mathématiques | Formulation en français                            |
| ---------------------- | -------------------------------------------------- |
| O(1)                   | constante (indépendante de la taille de la donnée) |
| O(log(n))              | logarithmique                                      |
| O(n)                   | linéaire                                           |
| O(nlog(n))             | quasi-linéaire                                     |
| O(n2)                  | quadratique                                        |
| O(n3)                  | cubique                                            |
| O(np)                  | polynomiale                                        |
| O(nlog(n))             | quasi-polynomiale                                  |
| O(2n)                  | exponentielle                                      |
| O(n!)                  | factorielle                                        |

On peut classifier grossièrement les algorithmes:

| Noms         | Description                     |
| ------------ | ------------------------------- |
| Polynomiaux  | En dessous de linéaire, bien    |
| Exponentiels | Au dessus de linéaire, pas bien |

# NP-Complets

On distingue plusieurs classes de problèmes:

- Classes P: Problèmes résolvables en un temps polynomial
- Classes NP: Problèmes dont on peut vérifier des solutions avec un algo en temps polynomial
- Classes NPC: Problèmes ou on peut vérifier les solutions, mais impossible de trouver ces solutions de manière polynomiale

## Relations entre ces classes

P est inclus dans NP
NPC est inclus dans NP

Si P = NP: tout problème dont on peut vérifier la solution rapidement pourrait être résolu rapidement (ce qui semble peu probable).

Si P ≠ NP: il existe des problèmes qu'on peut vérifier vite mais qu'on ne peut pas résoudre vite (ce qui semble être le cas, mais on ne l'a pas prouvé).

# Structure de donnees

# Tris

- Tri à bulle : échange d’éléments consécutifs
- Tri par sélection du minimum : échange du premier élément de la partie non triée avec son minimum
- Le tri par insertion peut également être vu comme une variante de cet algorithme de tri informel
