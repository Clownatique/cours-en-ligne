+++
title='td1'
draft=false
+++


# qqes suites importantes tsais

somme des n premiers termes : n*(n+1)/2

ptit dessin rigolo

sommes des termes dune suite geometrique :

sommes des q^i:1-q^{n+1}/1-q

la dailleurs c le nombre de noeuds dans un arbre q-aire (#on peut faire un dessin)

sommes des 2^i:2^{n+1}-1

sommes des q^i, pour i de j a n (j diff de 0):q^j x (1-q^{n-j+1}/1-q)

# une relation de reccurence **SURPRENANTE!!**

revenons au raisonnement par reccurence (induction)

- tsais faut prouver le cas initial
- ensuite on suppose que pour n c vrai.
- ensuite on se debrouille pour trouver que d_i+1 est vrai
- apres on est content

## d_i

d_0 = 1 //impair
d_i+1 = d_i + 2
      = 2 \times i + 1 + 2
      = 2 (i+1)+1
vrai pour i+1 finalement

## a_i

...

trop pratique parce quon fait que des additions, et pourtant on a deux formules cools (impairs et carres)

# fibonacci

ensuite petit dessin trop pipou de cquil se passe

**bref le nombre d'appell croit exponentiellement**

10^20 annees pour fibo(100) si chaque appel prenait une MICROseconde


**appel iterative**

## fonction iterative

3 "recepients suffisent"

... pareil que lexemple

```
  on init F\_k-1 = 1
  on init F\_k-2 = 1

  Pour k de 2 n faire
   F\_k = F\_k-1 + F\_k-1
   F\_k-2 = F\_k-1
   F\_k-1 = F\_k
  FinPour
FinFonction
```

**Lineaire en temps et constant en memoire**

Il existe aussi un algo en temps logarithmique

# les tours de hanoi

on decompose le probleme:

```lgge naturel
Si n = 1 alors
  deplacerSommet(pos_depart,pos_arrive)
Sinon
  deplacerTour(n-1,pos_d,pos_i,pos_a)
  deplacerSommet(pos_d,pos_a)
  deplacerTour(n-1,pos_i,pos_a,pos_d)
finSi
```

ahhh c exponentielle lol (si c taille 64, 1 seconde pour 1 disque, on en a 213 000 fois 1 milliard de jours pour le faire)
