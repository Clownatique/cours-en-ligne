type arbre_bin =
  AbVide (* la faut imaginer rien*)
  | AbNoeud of int * arbre_bin * arbre_bin
(* On remarque bien que tout les trucs commence par une majuscule*)

(* assert 3;; *)

let ab1 = AbNoeud(3,AbNoeud(4,AbVide,AbVide),AbVide);;
let ab2 = AbNoeud(3,AbNoeud(4,AbVide,AbVide),AbVide);;

let rec taille_ab (ab: arbre_bin): int =
  match ab with
    | AbVide->0
    | AbNoeud(elt, fg,fd)-> 1 + (taille_ab fg) + (taille_ab fd);;
  Printf.printf "la taille fait %d\n" (taille_ab ab2) ;;
(* le type de print c un type reserve du systeme *) 
  print_endline ("la taille fait " ^ string_of_int (taille_ab ab1));;
(* print_endline prends une string *)

let rec produit_ab(ab: arbre_bin): int =
  match ab with
    | AbVide->1
    | AbNoeud(elt, fg,fd)-> elt * (produit_ab fg) * (produit_ab fd);;

(* assert (taille_ab ab1 = 0);; *)
(* assert il va afficher un appel a unit() *) 

(* (produit_ab ab1);; *)

let rec insere_arbre_bin(e:int) (ab: arbre_bin): int =
  match ab with
    | AbVide-> AbNoeud(e, AbVide,AbVide)    
    | AbNoeud(elt, fg, fd)->
        if e > elt then Noeud(elt, (insere e ag ))

        if (cmp e e') then Noeud(e',(insere e ag cup), ad)
                      else Noeud(e', ag, (insere e ad cup))
    ;;


  
(* pour un pattern matching, il y a autant de cas possible que de regle pour le type possiblec *) 
:
