## exo 1

$$A =
\begin{pmatrix}
1 \\ 1 \\ ... \\ 1
1 \\ 0 \\ ... \\ 0
.. \\ .. \\ ... \\ ..
1 \\ .. \\ .. \\ 0
\end{pmatrix}
P_n(X) = (-1)^n X^{n-2} \underset{=0}{(X^2-X-(n-1))}
$$

### Astuce pour factoriser $X^{n-2}$ sans calculs:

Les colonnes engendrent l'image de l'application lineaire $ u : \mathbb{R}^n \rightarrow \mathbb{R}^n$
representee par A

DOnc on en deduit que le $rg(A) = \dim \Im A = 2 $

Alors par le theoreme de Rang, on en deduit que \dim \Ker A = n - 2

- \Ker A = \{ \vec v \in \mathbb{R}^n | A \vec v = 0 \}
  => donc 0 est une valeur propre et KerA = E_0
  => c;est lespace propre de vol pr 0

=> m_geom(0)=n-2 =< m_def (0) = m tel que P_A(X) = (X-0)^m \times Q_n-m(X)

- Donc certainement P_A(X) = X^n-2 \times Q(X)

Ou alors
\texthtb(A) = \{ \lambda_1, \lambda_1, \lambda_n \} (multi ensemble)

## exo 2

simplement: les valeurs propre sont 0 donc A n'est pas diagonalisable

une matrice diagonalisable:
c une matrice
:

### critere de diagonalisable

A est diag ssi

- le polynome caractersitque est scinde (si ils se factorisent en polynome irreductible de degre 1)
  (ceci implique lexistence des valeurs propre)

- pour chaque valeur propre on doit avoir:
  1. la multiplicite geometrique = multiplicite algebrique
     ou mul_geo veut dire que la dimension E =< mul_dia
  2. vsy elle va vite

### critere de trigonalisabilite

ssi le polynome caracteristique est scinde

## exo 3 (TRES CERTAINEMENT DEMANDE A L'EXAM!!)

dans cet exercice on va verifier avec les 2 precedents critere:

on prends le polynome caracteristique pour obtenir les espaces propres
avec les espaces propres on va pouvoir prendre la matrice de passage P eh vsy frere

si le polynome P ne se factorise : pas diagonalisable
