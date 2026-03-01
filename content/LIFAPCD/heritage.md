# Pourquoi l'heritage

L’**héritage** permet de créer une classe à partir d’une autre pour **réutiliser son code**.

On part d’une classe générale, puis on crée des versions plus spécialisées.

## Exemple : une Personne

```cpp
class Personne {
public:
    std::string nom;
    int age;

    void sePresenter() {
        std::cout << "Je m'appelle " << nom << std::endl;
    }
};
```

Cette classe décrit une personne en général.

---

## Création d’une classe qui hérite

Imaginons un étudiant.\
Un étudiant **est une** personne, mais avec des infos en plus.

```cpp
class Etudiant : public Personne {
public:
    int numeroEtudiant;
};
```

`public Personne` signifie que `Etudiant` hérite de `Personne`.

---

## Utilisation

```cpp
Etudiant e;

e.nom = "Alice";   // vient de Personne
e.age = 20;        // vient de Personne
e.numeroEtudiant = 1234; // propre à Etudiant

e.sePresenter();   // méthode héritée
```

La classe `Etudiant` possède :

- ses propres données
- **tout ce qui existe déjà dans `Personne`**

---

## Ajouter un comportement spécifique

```cpp
class Professeur : public Personne {
public:
    std::string matiere;

    void enseigner() {
        std::cout << "J'enseigne " << matiere << std::endl;
    }
};
```

---

## Résumé

L’héritage permet de :

- réutiliser du code existant
- créer des relations "est-un" (`Etudiant` est une `Personne`)
- organiser les classes de manière logique

Une classe enfant récupère les attributs et méthodes de la classe parent.
