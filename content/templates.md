+++
title = "templates"
draft = false
+++

## Pourquoi ?

Les templates (en francais, gabarits) sont des moyens de creer des classes conteneurs

# Les templates en C++

Un **template** permet d’écrire du code qui fonctionne avec plusieurs types sans le recopier.

---

## Exemple sans template

```cpp
int addition(int a, int b) {
    return a + b;
}

double addition(double a, double b) {
    return a + b;
}
```

On répète presque le même code.

---

## Exemple avec template

```cpp
template <typename T>
T addition(T a, T b) {
    return a + b;
}
```

`T` est un type générique.\
Le compilateur remplace `T` par le vrai type (`int`, `double`, etc.).

Utilisation :

```cpp
int x = addition(3, 5);
double y = addition(2.5, 1.5);
```

---

## Exemple avec une classe

```cpp
template <typename T>
class Boite {
public:
    T contenu;
};
```

Utilisation :

```cpp
Boite<int> b1;
Boite<std::string> b2;
```

---

## Résumé

Un template, c’est un **modèle générique**.\
Tu écris le code une fois, et C++ génère automatiquement la version adaptée au type utilisé.
