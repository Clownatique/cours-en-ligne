+++
title = ""
draft = false
+++

## stl

Dans le dernier CM de LIFAPSD, il est precise que nous allons utiliser des
modules de structures de donnees deja developpes.

Il s'agit la de la bibliotheque standard du C++: **la STL**.

### Structure de donnees

La STL utilise des templates pour creer des classes supportant n'importe quelle type.

> On pourra creer un tableau d'entier de la meme maniere qu'on pourra creer un tableau de flottant

Ce mecanisme est detaille [ici](templates.md)

Liste exhaustive des structures de donnes de la STL:
_les structures cochees ont ete abordees en LIFAPSD_

- [x] array (tableau)
- [x] vector (tableau dynamique)
- [ ] deque (file a double extremite)
- [x] forward_list (liste simplement chaine non circulaire)
- [x] list (listement doublement chainee circulaire)g
- [ ] set (collection)
- [ ] map (dictionnaire)
- [x] stack (pile)
- [x] queue (file)

#### `vector` : le tableau dynamique

On peut ajouter un element a la fin du tableau:

```cpp
std::vector<int> tab_dyn; // tab_dyn = []
tab_dyn.push_back(4); // tab_dyn = [4]
tab_dyn.push_back(2); // tab_dyn = [4,2]
std::cout << tab_dyn[0]; //acces a l'indice 0

tab_dyn(5,69);// creer ce tableau: [69,69,69,69,69]
```

#### `list` : Liste chainee

```cpp
std::list<int> liste ; //initialisation d'une liste vide
liste.push(4); // liste = [4]
std::cout<<liste.begin(); //affiche la queue de la liste
std::cout<<liste.end(); //affiche la fin de la liste
```

boucle sur une liste:

```cpp
for(lit=ma_liste.begin();lit!=ma_liste.end();++lit)
  std::cout << *lit << "";
```

#### `set`: ensemble de valeur unique

De la meme qu'un ensemble de la theorie des ensemble en algebre,
le `set` ne peut pas contenir de doublons.

l'insertion d'elements:

```cpp
std::set<int> s;
s.insert(2);
// s contient 2s.insert(5);// s contient 2 5
s.insert(2);// le doublon n'est pas inséré
s.insert(1);// s contient 1 2 5
```

on boucle sur l'ensemble:

```cpp
for(sit=s.begin();sit!=s.end();++sit)
  std::cout << *sit << ' ';
```

#### `stack`: une pile

quelques methodes:

**empilage**:

```cpp
stack.push(i);
```

**depilage**:

```cpp
stack.pop();
```

**acces au 1er element**:

```cpp
stack.top();
```

**test si vide**

```cpp
stack.empty();
```

#### c tout ?

Non bien evidemment: les structures de donnes proposees par la STL sont plus
complets que ca.

Leurs references completes peuvent se trouver a l'adresse [https://cplusplus.com](https://cplusplus.com/reference/)

Il est possible d'installer les manpages de la STL:

```bash
sudo apt install libstdc++-14-doc # le 14 ici indique la version de la stl a installer
```

_parce que je comprends pas pourquoi il faudrait constamment garder un navigateur ouvert_

### time

Plutot que d'utiliser time.h (la bibliotheque C)

```cpp
clock_t t;

t = clock();
printf (“Operation à chronométrer...\n");
t = clock() - t;

cout <<“Temps en clicks=”<<t<<endl;

cout<<“Temps en secondes=”
<<((float)t)/CLOCKS_PER_SEC)
<<endl;
```

### string

Plutot que de faire comme en C, avec des tableaux de caracteres 🤮

```cpp
string s1 = "Bonjour Monde";
cout << s1 << endl;

// initialisation avec une C string
string s2 (c_string_name, n); // n correspondant au nombre de caracteres traduit

// initialisation par copie de string
string s3 (cpp_string, pos_depart,nmbre_chara)
string s3 (cpp_string)

//initialisation avec 1 caractere
string s4 (n,'+') // -> "++++...n...+++"

// apparement y'a aussi des supers fonctions
// mais on est assez grand pour demander a chatgpt pour que ce soit mis dans le CM :)
```
