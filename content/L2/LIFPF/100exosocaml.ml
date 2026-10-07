let rec last (l:list of 'a):'a=
	match l with
	| [a;[]]-> a
	| [a;['a * 'a ]] -> last(['a *'a])
