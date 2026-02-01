+++
title = "td2"
done = false
+++

## td exo 1

### 1. on doit typer et traduire en ocaml

#### a

lambda x (x+2)

fun x -> x+2

pour le typage n->n

#### b

fun x -> fun y -> (2 * x) - y

typage: n -> (n->n)
! la fleche est associative a droite:

a -> b -> c => (a -> (b -> c))

#### c

la c faut consider que x := f

et le type pour c : ((n-> n) -> n)

on peut pas beta reduire dailleurs (pas de la forme requise)

fun x -> x 2 + x 3 plus clair en rajoutant des parantheses dapplication

#### d

y + 3 ca renvoie forcement n
lambda y renvoie alors n -> alpha

lapplication de x y ca va renvoyer (n -> alpha) -> alpha'

donc cette application de x dans alpha ca renovie -> alpha'

traduction: fun x -> (x fun y -> (y + 3))

### 2

#### traduction en lambda calcul

lanalyse commence en rajoutant des parantheses forcement

(((fun u -> fun y -> u (fun v -> v)) (fun x -> (x y))) 3)

traduction:((lambda u.lambda y (u \lambda v v) \lambda x (x y)) 3)
variable libre:

ok lambda v.v, v est lie (bounded)
donc y est lie dans la branche de gauche:

le probleme c que la variable est libre et lie
