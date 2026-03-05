type 'a arbre_n = 
  Feuille of 'a 
  | Noeud of 'a * 'a arbre_n list;;

let rec hauteur_abr(abr: 'a arbre_n): int =
  match abr with
  | Feuille -> 1
  | Noeud l -> hauteur_foret(l) + 1
  and hauteur_foret(l: 'a arbre_n list) : int =
    match with
;;


let rec minimum (abr: 'a arbre_n): 'a option=
  match abr with =
  
