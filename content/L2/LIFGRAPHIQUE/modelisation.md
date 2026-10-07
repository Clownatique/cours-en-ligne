Surface implicite

## Quadrique

### une equation..

#### plan

est defini par $$ Ax + By + Cz -D = 0 $$

#### sphere

$$ x^2 + y^2 + z^2 = r^2 $$

#### cylindre

$$ x^2 + y^2 - 1 = 0 $$

#### cone

$$ x^2 + y^2 - z^2 = 0 $$

#### d'autre formes plus complexes

## Création d’un objet par extrusion

L'extrusion consiste a etirer un objets dans une direction donne

L'extrusion va transformer

- un point en une courbe
- une courbe en une surface
- une surface en un volume

## Création d’un objet par révolution

La revolution consiste a faire tourner un objet selon un repere, et tracer
chacun des points par lequel il sera passe

## Création d’un terrain avec une carte de hauteur

Pour creer un terrain on va utiliser une carte de hauteur:

C'est une matrice (quon peut representer avec une image) ou chaque coefficient
va donner la hauteur d'un point.
Ensuite on trace des triangles entre chaque groupe de 3 sommets.

Pour calculer la normale:
jai pas compris pk faut faire des derivees ni comment mais ok

une image d'elevation de 64x64 va produire 64x64x2 triangles (ca fait bcp)
