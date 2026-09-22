# base de donnees

## definition

## niveaux


### niveau logique
#### modele E/A
... on sait ce que cest

##### limites

- pas de mecanique de raisonnement
- pas deterministe
- trop simpliste

##### Entites
###### classe d'entite

- modelisation commune d'entite

###### entite faibles

Si A n'existe que si B existe, alors A est une entite faible
c note avec un

###### specialisation

C le meme principe que l'heredite

##### Associations

Relation entre plusieurs entites


###### Connectivite
1,N
###### Participation
0,1

###### Association reflexive

###### Arite en N (agregation)

Quand une association doit faire interagir avec 3 entites ou plus

###### associations de specialisation

- T
- X
- XT

##### Attributs

Propriete (type) d'une entite

### niveau physique

#### Modèle relationnel
- Structure : des relations entre des tuples et des attributs.
- Contraintes : clés (identifiants de tuples, clés étrangères
(références à des tuples), contraintes de domaines.
- Langages : algèbre relationnelle, calcul relationnel, SQL, clauses
de Horn sans récursion.

#### notation

#### autres modeles de base de donnes
(synthetiser la suite)
#### Modèle déductif
- Structure : celle du modèle relationnel à laquelle on ajoute des
règles de déduction.
- Contraintes : les mêmes que le modèle relationnel
- Manipulation : langages logiques comme Datalog. Contrairement
aux langages du modèle relationnel, il admet la récursivité.

#### Modèle de graphe (e.g., RDF)
- Structure : graphe orienté et étiqueté
- Contraintes : un identifiant pour chaque nœud, un mécanisme de
référence entre des nœuds
- Manipulation : parcours de graphes, SPARQL.

#### Modèle hiérarchique (e.g., XML)
- Structure : arborescente (forêt d’arbre)
- Contraintes : un identifiant pour chaque nœud, un mécanisme de
référence entre des nœuds
- Manipulation : navigation hiérarchique, XPATH, XQUERY.

#### Modèle objet
- Structure : logique objet, soit des classes, des objets, des attributs
et des méthodes. Peut être vu comme un graphe orienté.
- Contraintes : identifiant pour les objets, référence entre objets.
- Manipulation : extensions de SQL comme OSQL ou OQL.

#### Modèle Entité/Association
- Structure : Entités (avec des attributs) et associations entre des
entités.
- Contraintes : identifiants d’entités, cardinalités sur les associations,
contraintes avancées
- Manipulation : aucun (c’est un langage de modélisation).

### niveau externe

## indepedance
### indepedance logique
### independance physique


