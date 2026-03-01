+++
title = ""
draft = false
+++

## arguments

_cette partie du cours fait echo a un certain TP en LIFSE_

Un programme peut etre appelle avec des arguments.
Voici plusieurs exemples en bash: (ligne de commande)

```bash
ls -a # l'argument ici est -a
mkdir src # ici c'est src
```

Pour recuperer les arguments en C++, c la meme chose qu'en C:

```cpp
int main(int argc, char *argv[], char **envp)
/* argc -> nombre d'arguments (ARGuments Count)
 * argv -> tableau des agruments (ARGuments Values)
 * envp -> variable d'environnement
*/
```
