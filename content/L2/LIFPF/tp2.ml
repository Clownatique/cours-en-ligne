let rec concatene (a: int list ) (b: int list): int list=
  (* en gros on fais une recursion*) 
  (* donc on est oblige de faire un match sur le premier *)
  (* argument et la recursion se fait sur la 2eme liste *)
  match a with
  | [] -> b
  | x :: y -> x :: (concatene y b)
;;

(concatene [2 ; 2] [78]);;

let rec applatit (a: int list list): int list =
  match a with
    | [] -> []
    | a :: b -> (concatene a (applatit b))
;;

(applatit [[3;2;5;0] ; [1;2;5;9]]);;

let rec renverse_ajoute (a: int list) (b: int list) : int list=
  match a with
    | [] -> b
    | x :: y -> (renverse_ajoute y (x::b));;


let rec renverse (a: int list) = (renverse_ajoute a []);;

(* (renverse_ajoute [ 1; 2; 3 ] [ 4; 5; 6 ]) *)  

let rec insertion (x: int) (l: int list) : int list =
  match l with
  | [] -> [x]
  | y :: l' ->
    if x >= y then y::x::l'
    else y :: (insertion x l');;

(* insertion 3 [ 1; 2; 4; 5 ];; *)
(* = [ 1; 2; 3; 4; 5 ];; *)
(* insertion 3 [ 1; 2; 3; 4; 5 ] ;; *)
(* = [ 1; 2; 3; 3; 4; 5 ];; *)

let rec tri_insertion (l: int list) : int list =
  match l with
    | [] -> []
    | x::y -> (insertion x (tri_insertion y))
  ;;

tri_insertion [ 1; 4; 2; 3 ];;
tri_insertion [ 1; 2; 3; 4 ];;

type resultat =
  | Trouve of string
  | Rien
;;

let rec cherche (k:int) (d:(int * string) list): resultat=
  match d with
  | [] -> Rien
  | (key, value) :: l' ->
      if key = k then Trouve value
      else (cherche key l' )
;;


type binop = Plus | Moins | Mult | Div
type elt_expr = Op of binop | Cst of int   

type resultat = Ok of int | ErrDivZero | ErrExpr

let eval_op (op:binop) (a: resultat) (b:resultat) : resultat=
  match (a, b) with
  | Ok c, Ok d -> (
    match op with 
    | Plus  -> Ok (c + d )
    | Moins -> Ok (c - d )
    | Mult  -> Ok (c * d )
    | Div   -> Ok (c / d )
  )
  | Ok _, err -> err
  (* Un nombre ok est un autre truc qui n'est pas un nombre ok: ce nombre pas ok car c une erreur*)
  | err, _ -> err
  (* Un truc qui n'est pas OK (donc une erreur ou quoique ce soit) renvoie necessairement une erreur*)
  ;; 

let rec eval_expr (l:elt_expr list): resultat = 
  match l with
    | [] -> []
    | Cst n::le -> Ok n::eval_expr l
    | Op op -> (
      match op with 

