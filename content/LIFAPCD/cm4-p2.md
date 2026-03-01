+++
title = "ecrire du code"
draft = false
+++

## pourquoi des conventions pour ecrire du code?

- Pour favoriser des bonnes pratiques
- Pour normaliser une base de commune
- Pour fluidifer la lecture (car un code est plus souvent lu qu'ecrit, cf excoffier)

## quelque principes (applicables a d'autres langages)

> **une ligne ne doit pas depasser 80 caracteres**

- pour pouvoir zoomer
- si c trop long il est preferable de decouper notre propos (exemple condition
  booleene)

> **choisir une unique langue pour les noms de variables/classes/fonction**:

- parce que les minions de moi moche et mechants ne savent pas coder
- pour des principes d'inclusions
- surtout parce que c plus simple pour decider des noms

> **les blocs (de fonction, structure de controle) doivent respecter l'indentation**

- ameliore grandement la lisibilite
- certains langages vont forcer ses utilisateurs a indenter (python)

### quelques commendement plus specifiques au c++

parce que ces regles peuvent legerement varier d'un langage a lautre

### regle de nommage

les regles suivantes vont aider

#### nom des types

concerne les `struct` et `Class`

> [CamelCase](https://fr.wikipedia.org/w/index.php?title=Camel_case)(les majuscules des mots vont former des bosses, comme le chameau)

#### noms des fonctions/procedures

> ce qui est manipule doit etre dans le nom

(une classe si c une methode)

> 1 verbe a linfinitif

(jfais mon relou mais l'infinitif en anglais y'a `to` devant donc a mediter)

#### noms des constantes

souvent c'est des variables importantes

> doit etre en majuscule et en [snake case](https://fr.wikipedia.org/wiki/Snake_case#Variantes)

#### conventions lies aux variables

> Le pluriel implique une collection d'objet

> Il est apprecie (par nos profs) de preciser le type d'une variable par la premiere lettre de cette derniere

> les variables d'iteration sont representes par un caractere simple

### les declarations

> on doit toujours preciser le cast (convertisseur de type)

> on doit affecter une valeur par defaut a une variable lorsqu'on la declre

> on ne doit jamais utiliser de variables globales (sauf les constantes du coup)

### structures de controle

> on n'utilise jamais break et continue

chatgpt aime en utiliser :)

> les variables d'iteration sont declares en amont

```cpp
int i,j; // elles sont declares ici
for (int i = 0 ; i < 42 ; i++){// plutot que dans le for
  
}
```

### pour les plus curieux

- [recommandation d'une boite qui fait des logiciels dans la sante](http ://geosoft.no/development/cppstyle.html)
- [recommendation d'une boite suedoise de telecom](http ://www.doc.ic.ac.uk/lab/cplus/c++.rules/)
- [recommandation de la nase](http ://v2ma09.gsfc.nasa.gov/coding standards.html)
- [recommandation de qt](https://github.com/nCine/nCine/wiki/Coding-Standards)
- [recommandation de linux (en C)](https://www.kernel.org/doc/html/v4.17/process/coding-style.html)
- []()
