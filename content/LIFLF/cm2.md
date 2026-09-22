# rappels cm1..

blabla

problematique: automate finis ne permettent pas de reconnaitre tout les langages (avec des mots infini)

genre:
- les mots avec autant de alpha que de beta
- ww c chaud

on a vu un lien entre grammaire reguliere reduite et automate non deterministe finis

les automates deterministes c mieux pour la memoire
mais c plus simple de decrire un langage avec un automate non deter (rebeu deter tsais)

on peut rendre un automate non deterministe en deterministe.

## slide 38

F_det cest lensemble des etats finaux
T_det cest une fonction de transition

et en gros si on trouve un etat final de A dans ce det de A et ca reconnait le meme langage que A

ensuite ya une preuve un peu chiante la bref

# expressions reguliere

## expressions regulieres particulieres

## concatenation possible+ propriete

et e^{+} il devrait pas etre sur les slides

le double crochet ca veut dire "le langage represente"
 
1 + 0^ + (1.0.0^)^

(take pcq jai demande le rapport avec les regexp en bash il sen est battu les couilles)

je sais pas ensuite il a fait sa preuve a la con tout seul (personne lui a demande je veux dire)

ah ok on a lidee des langages rationnels (c genre des solutions dequations)

genre ce serait (un langage rationnel)

X = eX + f, e une expression, f c aussi une expression

et comme solution on a e^star.f comme solution unique et la meme chose comme solution minimale (ca depends de si ya epsilon dans e)

apres trop cool il utilise son lemme pour faire des trucs rigolos (#TotoOuUnTiti)

apres waw genial une expression reguliere c un langage rationnel (#PassionantOuQuoi)

