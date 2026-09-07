# objectif du cours

- comprendre les systemes de resolution
- programmation theorique (pas la mise en pratique d'algorithmique)
- on reviendra sur LISP ? sur CAML ?
- gallina (langage de preuve tout ca tout ca)
- regle de raisonnement
- regles inductives
- specification au premier ordre (passer du texte a lequivalent booleen)

# pourquoi ?

on veut trouver un moyen de verifier du code

postulat : phrase toute simple

les types manipulees seront des nombre, des caracteres et des chaines (et meme des trucs plus complets)
on va ecrire des programme qui sont en realit des preuves
le gros va etre dappliquer des calculs dans des programmes ?

pour definir un objet on peut :
le faire assez arbitrairement
ou avec des regles

ex: LifLF appartient il aux UE
on va ecrire des preuves de correction

on va apprendre a ecrire des fonctions correctes (dans un langage plus sympa que le caml)

jean gallier (foundations of automatic theorem proving): bible (mais c indigeste)
introduction a la logique (david, nour, raffali): reference numero 1 (1er chapitre terrible)

# ensembles

- pas de theorie des ensembles

rappel: des sacs non ordonnes sans repetition

on peut le def de maniere exhaustive
ou intentionnellement (avec une regle)

un ensemble infini sexprime forcement par intention

les operateurs sont les memes

pas dinclusion large (stricte ou non, depends de la barre en dessous du symbole dinclusion)

une partie de E (power set, lensemble des parties d'ensemble)
ex: E ={a,b} et P(E) = {vide, {a},{b},{a,b}}, et c 2^n, n le nombre delements de E

il ne faut pas confondre le produit cartesien (ensemble de n uplet) avec un ensemble d'ensemble

# relations

le symbole P est une relation

les relations cest des parties ?
c une sorte de produit cartesien entre des parties

quand yen a 2 : fleche
quand yen a 3 : triangle

donc laddition c ternaire, parce quelle associe (loperation), 2 nombres avec leur somme

TODO: exprimer un peu mieux les proprietes

cest ... une relation dequivalence
cest ... une relation d'ordre

symetrique c frere
antisymetrique c pere

a->b
a->d
b->a
c->a
c->c
d->c

cette relation est ni symetrique, ni antisymetrique.

## stabilite

notion de stabilite

laddition est stable, tout comme les entiers naturels pairs

mais laddition de nombre impairs ne lest pas car on peut avoir un resultat pair.
et attention mais pour rendre laddition de nombre impair stable, on peut utiliser tout les nombres naturels sauf 0

### les fermetures

E = {a,b,c,d}
R = {(a,d),(a,b),(b,c),(c,d)}
ici la relation nest pas transitive

pour rendre cette relation transivite on ajoute a la relation
(b,d) et (a,c)

#### la fermeture transitive
ajoute des relations a une relation pour la rendre relative

## fonction

une fonction est un certain type de relation

chaque element doit avoir une image

on peut avoir des fonctions a plusieurs arguments :
(curryfiction)

### applciation

et apres tsais c comme en maths (in,sur,bi)jective
rappeller comment le savoir au s

### cardinal, equipotence

est ce que Z est equipotent que N ?

(ou comment compter linfini en v)
pour prouver ca, il faut prouver quune relation bijective de N a Z est impossible.

et comme il est trop fort:

x|-> x/2 si pair
x|-> -x+1/2 si x impair

le cardinal dun truc se note |truc|

parce que oui on peut aussi essayer de dire quils ont le meme cardinal

## ensembles inductifs

exemple de schema dinduction

schema dinduction : schema pour definir des ensembles, avec un ensemble de regle et un ensemble de depart

lensemble des entiers naturels peut secrire {->0,n->n+1} (on part de 0 et on additionne 1): on va obtenir tout les entiers naturels ma gueule

et bah lensemble inductif de cet ensemble c la plus petite partie close dun ensemble dinduction



### egalite densemble

#### proceder par double inclusion

ex:

G est inclus dans D car N c la plus petite partie close de N
D est inclus dans G parce que N est inclus dans lintersection de N dans Z dans R

#### on peut proceder par induction

.... oupsi

#### on peut jsp trop quoi faire (slide 24)

ok on peut utiliser des fonctions pour definir des ensemble ?

S(x) c une fonction
donc on a ({S,Z}*,{->Z,x->S(X)})

on pourra meme definir double(n):
si n est Z alors Z
si est S(m) alors S(S(double(m)))

#### propriete egalement : bonne fondation

une relation binaire anti ref et transitive et en ordre strict tas capte
une relation peut etre bien fonde sur un ensemble

