+++
title = 'cours'
draft = false
+++

_note en deux fois_

# Ensemble

## Definition

On peut dire d'un ensemble, qu'il s'agit d'un sac non ordonne, sans repetition
En pratique, on distingue deux maniere de declarer des ensembles:

- Par extension: cela implique que l'ensemble declare est finis.
- Par intention: cela implique que l'ensemble declare n'est pas finis (qu'il peut etre infini)
Cette derniere maniere se fait avec une proposition mathematique.
- Par induction: cela se fait avec un ensemble de depart et une regle. Cela forme un *schema d'induction*

## Operateurs dits ensemblistes

| Symbole | Traduction en français | Définition mathématique |
|---|---|---|
| $$\varnothing$$ | Ensemble vide | $$\varnothing=\{\}$$ |
| $$\in$$ | Appartient à | $$x\in A\iff x\text{ est un élément de }A$$ |
| $$\notin$$ | N'appartient pas à | $$x\notin A\iff x\text{ n'est pas un élément de }A$$ |
| $$\subseteq$$ | Est inclus dans | $$A\subseteq B\iff \forall x,\ x\in A\Rightarrow x\in B$$ |
| $$\subsetneq$$ | Est strictement inclus dans | $$A\subsetneq B\iff A\subseteq B\ \text{et}\ A\neq B$$ |
| $$\supseteq$$ | Contient | $$A\supseteq B\iff B\subseteq A$$ |
| $$\supsetneq$$ | Contient strictement | $$A\supsetneq B\iff B\subsetneq A$$ |
| $$=$$ | Est égal à | $$A=B\iff \forall x,\ x\in A\Leftrightarrow x\in B$$ |
| $$\neq$$ | Est différent de | $$A\neq B\iff \neg(A=B)$$ |
| $$\mathcal{P}(A)$$ ou $$2^A$$ | Ensemble des parties de $$A$$ | $$\mathcal{P}(A)=\{B\mid B\subseteq A\}$$ |
| $$\cup$$ | Union | $$A\cup B=\{x\mid x\in A\ \lor\ x\in B\}$$ |
| $$\cap$$ | Intersection | $$A\cap B=\{x\mid x\in A\ \land\ x\in B\}$$ |
| $$\setminus$$ | Différence ensembliste | $$A\setminus B=\{x\mid x\in A\ \land\ x\notin B\}$$ |
| $$A^c$$ ou $$\complement A$$ | Complémentaire de $$A$$ | $$A^c=E\setminus A=\{x\in E\mid x\notin A\}$$ |
| $$\triangle$$ | Différence symétrique | $$A\triangle B=(A\setminus B)\cup(B\setminus A)$$ |
| $$\times$$ | Produit cartésien | $$A\times B=\{(a,b)\mid a\in A\ \land\ b\in B\}$$ |
| $$\bigsqcup$$ | Union disjointe | $$A\bigsqcup B=A\cup B\quad\text{avec}\quad A\cap B=\varnothing$$ |
| $$\bigcup_{i\in I}A_i$$ | Union d'une famille d'ensembles | $$\bigcup_{i\in I}A_i=\{x\mid \exists i\in I,\ x\in A_i\}$$ |
| $$\bigcap_{i\in I}A_i$$ | Intersection d'une famille d'ensembles | $$\bigcap_{i\in I}A_i=\{x\mid \forall i\in I,\ x\in A_i\}$$ |
| $$\left\{x\in E\mid P(x)\right\}$$ | Ensemble défini par compréhension | $$\{x\in E\mid P(x)\}=\text{ensemble des éléments de }E\text{ vérifiant }P(x)$$ |
| $$\lvert A\rvert$$ | Cardinal de $$A$$ | $$\lvert A\rvert=\text{nombre d'éléments de }A$$ |

# Relation

## Definition

Une relation est un ensemble de n-uplets (n etant l'arite de la relation) definissant des liens entre les elements de n ensembles.

*pour le bien de tous, on se limitera a des relations avec 3 ensembles distincts, qui seront representees par un triangle.*

## Arite
Nombre d'ensemble associes.

## Propriete (des relations binaires)

| Propriété | Traduction en français | Définition mathématique |
|---|---|---|
| $$R$$ réflexive | Chaque élément est en relation avec lui-même | $$\forall x\in E,\ (x,x)\in R$$<br>ou<br>$$\forall x\in E,\ R(x,x)$$ |
| $$R$$ antiréflexive | Aucun élément n'est en relation avec lui-même | $$\forall x\in E,\ (x,x)\notin R$$<br>ou<br>$$\forall x\in E,\ \neg R(x,x)$$ |
| $$R$$ symétrique | Si un élément est en relation avec un autre, alors l'inverse est aussi vrai | $$\forall x,y\in E,\ (x,y)\in R\Rightarrow(y,x)\in R$$<br>ou<br>$$\forall x,y\in E,\ R(x,y)\Rightarrow R(y,x)$$ |
| $$R$$ antisymétrique | Deux éléments distincts ne peuvent pas être en relation dans les deux sens | $$\forall x,y\in E,\ \big((x,y)\in R\land(y,x)\in R\big)\Rightarrow x=y$$<br>ou, de manière équivalente :<br>$$\forall x,y\in E,\ \big((x,y)\in R\land x\neq y\big)\Rightarrow(y,x)\notin R$$ |
| $$R$$ transitive | Si un élément est en relation avec un deuxième, lui-même en relation avec un troisième, alors le premier est en relation avec le troisième | $$\forall x,y,z\in E,\ \big((x,y)\in R\land(y,z)\in R\big)\Rightarrow(x,z)\in R$$<br>ou<br>$$\forall x,y,z\in E,\ \big(R(x,y)\land R(y,z)\big)\Rightarrow R(x,z)$$ |

### Relations particulieres

| Relation d'équivalence | Relation réflexive, symétrique et transitive | 
| Relation d'ordre | Relation réflexive, antisymétrique et transitive |


## Notion de stabilite

### Stable

On dit d'un ensemble qu'il est stable/close par une relation donnee lorsque les associations se font exactement a l'interieur de lui meme.


### Ensemble de "cloture"

Si un ensemble $$E$$ n'est pas stable par $$R$$, il existe un plus petit sous ensemble $$F$$, inclus dans $$E$$ qui est lui stable.

On appelle $$F$$ la cloture de $$E$$ par $$R$$

## Relations particulieres

### Fonctions

#### Definition

Une fonction est une relation d'un ensemble de depart vers son element d'arrive. C-a-d chaque element de l'ensemble de depart peut avoir une image dans l'ensemble d'arrive.

#### Domaine

Le domaine d'une fonction est l'ensemble des elements de depart qui ont forcement au moins une arrivee.

#### Composition de fonction

blabla

#### Fonctions particulieres

##### Fonctions a plusieurs arguments

Si larrivee dune fonction est l'arrivee dune autre relation qui en fait est ..()

On peut avoir plusieurs relations dans la meme fonction, mais ca implique quon a plusieurs arguments

##### Applications

La particularitee d'une application est que son domaine corresponds a tout l'ensemble de depart qu'elle mets en relation.

###### Propriete des applications

####### (in,bi,sur)jective

blabla

#### Operations

Bah ca prends deux ensemble de departs et un d'arrive ??

# Cardinal

## Definition

Le nombre d'elements dans un ensemble
Se note |Ensemble|

## Equipotence

On peut demontrer que deux ensembles ont le meme cardinal si il existe une application bijective entre eux

**Exemple**:

est ce que Z est equipotent que N ?

(ou comment compter linfini en v)
pour prouver ca, il faut prouver quune relation bijective de N a Z est impossible.

et comme il est trop fort:

x|-> x/2 si pair
x|-> -x+1/2 si x impair

## Denombrable

Un ensemble infini est demontrable si il est equipotent a N

## Theoreme des ensemble infinis non denombrables

[Plus d'info ici](https://fr.wikipedia.org/wiki/Ensemble_infini_non_d%C3%A9nombrable)

# Ensemble inductif

(ya 4 trucs a bien savoir maitriser en gros, je crois que dcp les ensembles inductifs c un super outil pour trouver des fermetures)

ok donc un ensemble inductif c le plus petit ensemble qui avec les bonnes regles, peut redefinir tout un ensemble.

on peut aussi le noter sous forme de regle de deduction (boring+pas au programme)

dapres le cours dolivier bournez, on peut se dire quun ensemble decrit implicitement peut secrire comme

$$ X U_{n \in \mathbb{N}} X_n $$ ou $$(X_n)_{n \in \mathbb{N}}$$ est definie par reccurence ou

X_0 = B et X_n+1 .... truc long samere tout ca pour un cours que je comprends pas bordel

la preuve est en slide 22

# elements de raisonnement

## preuve par induction (comme la reccurence ou quoi)


...

# Logique propositionnelle

la logique propositionnelle c donc un langage assez particulier.
son alphabet est defini par un ensemble inductif, et on va beaucoup utiliser la notation deductive

## terminologie associe

! un mot = une formule (c son petit nom comme dirait mr brandel)

## origine

(inserer les cms d'archi sur l'algebre de boole)

## grammaire de la logique propositionnelle

se fait a laide de fonction booleene.. (fonctions a 3 c)
(inserer les cms d'archi sur l'algebre de boole)

## interpretation (semantique)

On definit egalement une fonction, I, qui va nous servir a interpreter tout ca

### satisfaction d'une proposition

si on satisfait une proposition A (que I(A)=1) on le note ⊨
(ici inserer un tableau avec les symboles et leurs modelisation en francais/anglais pk pas)

## remplacement

operation quon fait sur les formules en elle meme pour "simplifier" au fur et a mesure.


## sequents

les sequents cest le fait decrire des deductions plus formellement. (dans le contexte de la logique classique)

### calcul des sequents

le calcul des sequents c le fait de deduire plein de nouvelles formules a partir de sequents pas prouve mais quon estime comme vrai. (#axiome)

il dit surtout que hypotheses ⊢ conclusions

hypotheses et conclusion sont des ensembles de formules

dans ce calcul, il ya

#### le systeme G

##### axiome

() → Γ,A ⊢ Δ,A
