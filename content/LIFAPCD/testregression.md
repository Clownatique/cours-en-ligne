+++
title = "test de regression"
draft = false
+++

## regression ?

regression est a opposer avec progression.
Si lorsquon ajoute des fonctionnalites a notre programme, les fonctions deja developpe ne marche plus c quon regresse.

**Il est imperatif de sassurer que ce ne soit pas le cas.**

## tests ?

on va donc ecrire des tests pour s'assurer qu'un module marche.

ces tests se font avec des _assert_: cette fonction s'arrete

### assert

j'ai un peu creuse par curiosite ce qu'etait reelement la fonction assert
alors PROFITONS EN:

assert est un appel systeme en C.

Sachant que le C++ est pleinement retrocompatible avec le C, cela ne nous pose
pas de probleme

voici le code qui nous interesse le plus:

```c
#define assert(EX) ((EX) ? (void)0 : __assert(#EX, __FILE__, __LINE__))
```

assert est une **MACRO**: raccourci.

Plutot que de marquer un truc comme:

```c
if (EX){
  __assert(#EX, __FILE__,__LINE__);
} else {
  (void)0 // ce qui ne fait RIEN
}
```

le compilateur lors de l'etape de **precompilation** va le faire pour nous.

Sachez meme que le code remplace meme a [ca](https://github.com/gcc-mirror/gcc/blob/master/fixincludes/tests/base/assert.h)

```c
#define assert(EX) ((EX) ? (void)0 : __assert(#EX, __FILE__, __LINE__))
```

ou ((expr) ? (bloc) : (bloc)) est interprete comme un

```c
if (){
  
} else {
  
}
```

> on appelle ca _loperateur ternaire_
