(* TP2 *)

(* Puisqu'on a la base des automates on va pouvoir compliquer un peu les choses et se donner les
   moyens de savoir ce qu'on a reconnu. *)

(* Bien sûr on veut pouvoir signaler les erreurs, on se donne donc une
   exception Erreur_lex qui prendra une string en paramètre. *)
(* Lorsqu'une exception E est "levée" par
   raise E
   le calcul courant est interrompu et E est propagée à travers toutes les fonctions appelantes.

   Observer le comportement des exemples.
   
   Exemples : *)
exception E;;
exception F;;
let f x = x + 2;;
let g x = raise E;;
g 3;;
f (g 3);;  (* propagation *)

(*
   On peut cependant capturer cette exception grâce à la construction try / with . La valeur de
   try exp with E -> toto
   est :
   - celle de exp si aucune exception n'a été levée
   - la valeur toto si E a été levée durant l'évaluation de exp.
   Bien sûr si une autre exception que E a été levée durant l'évaluation de exp, cette dernière est propagée.
   Exemples : *)

let h x = try g x with E -> 666;;
h 3;;
f (h 3);;  (* capture de l'exception *)
let j x = try (raise F) with E -> x;;  (* propagation car pas de capture *)
j 3;;

(* On peut enfin étiqueter une exception par un objet d'un type non
   paramétré (c'est-à-dire sans 'a...).
   Exemple : *)

exception Yay of int;;
exception Horror of int;;
let f x = if x = 1 then raise (Yay 42) else if x = 7 then raise (Horror 666) else x;;
f 1;;
f 42;;
f 7;;

let g x = try f x with Yay n -> n-2 | Horror n -> n+34;;
g 1;;
g 7;;
g 42;;



(* On a donc besoin d'une exception pour récupérer/localiser les erreurs *)

exception Erreur_lex of string;;


(* Proposer un type somme token à trois constructeurs : Num étiqueté
   par une chaîne, Id étiqueté par une chaîne de caractères et Sym
   étiqueté par une chaîne de caractères. *)


(* Le type des transducteur peut être une modification du type des
   automates où maintenant la collection des états finals permet aussi
   d'associer (pour nous de façon naïve) le token idoine à une
   string. Proposer un type pour les transducteurs. *)


(* Proposer une fonction de lecture qui, sur la donnée d'un automate a,
   d'un mot m et d'un état e, retourne un couple formé de l'état
   d'arrivée à la lecture du mot à partir de l'état s'il existe et de
   la concaténation des chaînes lues. *)

(* Proposer une fonction qui sur la donnée d'un automate et d'un mot retourne le token
   correspondant à l'état atteint et étiqueté de la chaîne représentant le mot lu. *)


(* Proposer un transducteur opérant sur le vocabulaire contenant "0", "1", "2", "a", "b", "c",
   "=" et "+" et retournant le token Num correctement étiqueté si le
   mot lu correspond à un entier, Id ... si le mot lu correspond à un
   indentificateur (lettre puis alphanumérique), Sym... si c'est un
   symbole "+" ou "=". *)


(* En supposant que l'espace est un séparateur de mots, proposer une
   fonction qui prend une liste de chaînes
   - non vide,
   - qui ne commence pas par un séparateur,
   - qui ne termine par un séparateur,
   et retourne la liste des tokens adéquats reconnus.
**Cette fonction est une nouvelle version de la fonction de parcours précédente qui sait gérer l'espace (et qu'on ne réutilisera donc pas directement).**
 *)



(* et voilà on a passé d'une liste de chaînes/char à une liste de tokens... *)
