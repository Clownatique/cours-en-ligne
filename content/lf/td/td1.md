+++
title='td1'
draft=false
+++

## exercice : calcul

### concatenation

uv = ababa
u^2 = abab
u^3 = ababab
v^2 = abaaba

### concatenation de langage

Soient deux langages sur V définis par L1 = {a, ba} et L2 = {ε, b, aa}, calculer L1 ◦L2,
L2 ◦L1, L2
1, L2
2, L⋆
1, L⋆
2.

L1 rond L2 = {a,ab,aaa,ba,bab,baaa}
L2 rond L1 = {a,ba,bba,aaa,aaba}
L1^2 = {aa,baba,baa,aba}
L2^2 = {(epsilon),b,bba,aaaa,aa,baa,aab}
L1,L2 starfoullah : jsp ce qu'ils ont marques

### expression reguliere

Soient les langages sur V définis par L1 = {a}⋆◦{b}⋆, L2 = ({a} ∪{b})⋆, L3 = {ab}⋆,
L4 = {a}⋆∪{b}⋆, L5 = ({ab} ∪{a})⋆.

L1 = suite infini de a, suite infini de b
L2 = suite infini de ab
L3 = meme chose
L4 = 

,a, b, aa, ab, ba, aab, abab
L1,oui,oui,oui,non,oui,non
L2,


## Grammaires

L -> a | b | cL | dLL

### montrer quun ensemble de mot est reconnu dans un langage

ca, dba, cdccab

cL -> ca
dLL -> dbL -> dba
cL -> cdLL -> cdcLL -> cdccLL -> cdccab

### calculer tout les mots possible

```
a
b
cL/
├── ca
├── cb
├── ccL/
│   ├── cca
│   ├── ccb
│   ├── cccL/
│   │   ├── ccca
│   │   ├── cccb
│   │   ├── ccccL:pas possible
│   │   └── cccdLL:pas possible
│   └── ccdLL:pas possible
└── cdLL/
    ├── cdaa
    ├── cdab
    ├── cdba
    ├── cdbb
    └── cdcLL :pas possible
dLL/
├── daa
├── dab
├── dba
├── dbb
├── dcLL/
│   ├── dcaa
│   ├── dcab
│   ├── dcba
│   └── dcbb
└── dLcL/
    ├── daca
    ├── dacb
    ├── dbca
    └── dbcb
```

## formule de reccurence

- cas initial: cL, dLL
- terme de reccurence:L->cL,dLL,a,b
- cas final: n>n

## automate ?

## facile..

..

# grammaires

je sais pas pourquoi jai voulu faire des grammaires regulieres mdr

## entiers

_ -> S | C
S -> +C | C (avec ou sans +..)
C -> 0C\_2 | ...C\_2 | 9C\_2
C_2 -> C | E
E -> \epsilon

## nombre flottants

_ -> S (lisibilite..)
S_1 -> 0C\_1 | +C\_1 | -C\_1
C\_1 -> 0C\_1 | ...C\_1 | 9C\_1 | P | E (E pour former retrouver des nombres sans virgule)
P -> .C\_2
C\_2 -> 0C\_2 | ...C\_2 | 9C\_2 | F
F -> eS\_2 | E (soit ya un exposant et on continue, soit c juste [0-9].[0-9])
S\_2-> +C\_3 | -C\_3
C\_3 -> 0C\_3 | ...C\_3 | 9C\_3 | C\_3 | E (pour former plusieurs chiffres apres la mantisse)
E -> \epsilon

## Nombres Pairs

S -> \epsilon | aaS | abS | baS | bbS

## Nombres Pairs sans repetition de a

C -> abC | bC | a | b | \epsilon


## Nombres Pairs sans repetition de a et b

si on imagine les mots que ca donne...

ababab....

donc jsp c elegant mais:

_ -> bC | a
C -> abC | \epsilon

..

# automate finis

...

## mots binaires divisibles par 3 (classique)

en base 10 la somme de 3 nombres consecutives par 3

on commence par noter les mots binaires divisibles par 3:

0,11,110,1001,1100,1111,10010

et on essaie de trouver des proprietes ensuite.

exemple : tout ces nombres sont congrus a 3

on essaie de trouver des paquets. (ceux qui se divisent par 3k+0,1,2)

on determine ainsi que letat final c'est les mots qui finissent par 3k+0

il faut se rappeller quon ne fait pas des maths, et que on peut faire la concanetion

un nombre qui finit par 0 est pair, et si il finit par 1 il est impair (ou autrement dit, on le reecrit par 2k+0/1)

|w   |w.0                 |w.1                 |
|3k+0|2+(3k+0)=3k'+0      |2(3k+0)+1=3k'+1     |
|3k+1|2(3k+1)+0=3k'+2     |2(3k+1)+1=6k+3=3k'  |
|3k+2|2(3k+2)+0=6k+4=3k'+1|2(3k+1)+1=6k+5=3k'+2|

digraph Automate {
    rankdir=LR;
    node [shape=circle];
    q0 [label="3k+0", shape=doublecircle];
    q1 [label="3k+1"];
    q2 [label="3k+2"];  // État accepteur
    q0->q1 [label="1"];
    q1->q0 [label="1"];
    q1->q2 [label="0"];
    q2->q1 [label="0"];
    q1->q1 [label="0"];
    q2->q2 [label="1"];
}

avec la suite dequation suivante, on definit notre grammaire

```
X_1 = 0X_1 + 1 X_2 + \epsilon
X_2 = 0X_3 + 1X_1
X_3 = 0X_2 + 1X_3
```

et en resolvant cette equation (pour notre `X_x` inconnu)
(on fait ca en injectant `X_2` partout)

(le fois cest une concatenation donc)

```
X_1 = X_1 (0+11) + 10 X_3
X_3 = X_3 (00+1) + 01X_1
```

```
X_1 = (0+11)*.(10X_3+\epsilon)
X_3 = (00+1)*.(01X_1)
```

```
X_1 = (0+11)*(10(00+1)*.(01X_1)+\epsilon
=(011)*(AX_1+\epsilon) //reecriture
={(011)*A}{e}{X_1}{X}+{(0+11)*\epsilon}{f}
= e*f
```

on resout seulemt X_1 car c letat initial (idealement faudrait resoudre `X_2` et `X_3`)

```
X+1 = ((0+11)*10(00+1)*01)*.(0+11)*
```

# barman aveugle

automate non deterministe (plusieurs directions possible pour le meme mot)
```
digraph{
    rankdir=LR;
    node [shape=circle];
    1 [label="1", shape=doublecircle]; //etat initial
    2 [label="2"];
    3 [label="3"];
    4 [label="4"];
    5 [label="5"];

    1->1 [label="a,b"];
    1->2 [label="a"];
    2->3 [label="a"];
    3->3 [label="a,b"];
    1->4 [label="b"];
    4->5 [label="b"];
    5->5 [label="a,b"];
}

```

```
digraph{
    rankdir=LR;
    node [shape=circle];
    1 [label="1", shape=doublecircle]; //etat initial
    12 [label="1,2"];
    14 [label="1,4"];
    123 [label="1,2,3"];
    145 [label="1,4,5"];
    134[label="1,3,4"];
    125[label="1,2,5"];
    1235[label="1,2,3,5"];
    1345[label="1,3,4,5"];
    12345[label="1,2,3,4,5"];

    1->12 [label="a"];
    1->14 [label="b"];
    12->14 [label="b"];
    14->12 [label="a"];
    12->123[label="a"];
    123->123 [label="a"];
    123->134 [label="b"];
    134->123 [label="a"];
    134->1345 [label="a"];
    1345->1345 [label="b"];
    1345->12345 [label="a"];
    12345->12345 [label="a,b"];

    // en bas

    14->145 [label="b"];
    145->125 [label="a"];
    125->145 [label="b"];
    145->145 [label="b"];
    125->1235 [label="a"];
    1235->1235 [label="a"];
    1235->12345 [label="a,b"];
}
```

Notions d'indistinguabilite


