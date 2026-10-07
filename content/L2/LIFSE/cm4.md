# les signaux

les signaux sont une maniere de terminer un programme
on les utilise sans passer par des canaux de communications classiques (entree/sortie standard)

ils sont asynchrones (personne ne sait quand le signal sera recu)

fait penser aux interruptions bas niveau quon a vu la semaine derniere

quand un programme recoit un signal, il va

1. retenir l'endroit ou il a recu le signal
2. effectuer un **traitement** en fonction du dit signal
3. il PEUT reprendre son execution

## les differents traitements possibles

- terminaision
- sommeil
- peut etre definies par le programmeurs

### exemple avec un super schema trop joli

les signaux permettent a lutilisateur dinteragir avec un programme qui tourne

les signaux interrompent egalement certains appels systeme (voir dans la documentation)

## les differents signaux de `signal.h`

- SIGINT 2

fais une interruption

- SIGKILL 9

libere toutes les ressources ?
CE SIGNAL ne peut pas etre ignore

- SIGUSR1 10

signal pouvant etre personnalisee

- SIGTERM

demande gentiment

- SIGCONT

reprendre un processus stoppe avec sigstop (ctrl-Z)

- SIGSTOP

On le mets en pause en general (et en general celui par defaut l'endors)

- SIGCHLD

processus recu par le pere quand son fils s'est terminee.

- SIGILL

pour signifier que le processus est malade

## envoyer des signaux en c/cpp

### recevoir des signaux en c/cpp

avec l'appel systeme de `sigaction`:

```cpp
int signaction(int signum, const sigaction *new, sigaction *old)
```

on peut definir des sigactions

### definir un gestionnaire de signaux.

```cpp
struct sigaction{
  void (*SystemActionHandler)(int)
}
```

### petit point de syntaxe

en C, il est important de repreciser si le type est une structure que C'EST UNE STRUCTURE

### quelques fonctions lies aux signaux

pause : qui attends de recevoir un signal

alarm : s'envoie lui meme un signal (utile quand on veut pas que notre programme passe trop de temps a faire trop de truc)

## en ligne de commande

kill -l liste les signaux possibles

```bash
kill -<signal> <PID>
```

control D envoie EOF (end of file): utile quand on communique directement l'entree standard

---

# les tubes

C'est une file d'octets entre deux processus.
C'est un mecanisme de construction.

il prends en parametre un ecrivain et un lecteur

Lecrivain va produire des donnes a son rythme.
Octets par octets, en FIFO,
le lecteur va consommer ces octets a son rythme

peut donc permettre a un pere et son fils de

## tubes anonymes

n'ont pas de nom
est sous un fichier (car c une variable dans un programme)

pipe va creer un tableau a deux cases (une pour l'ecriture, une pour la lecture)

Lorsque le pere va devoir prevenir son fils quil arrete de parler

## tubes nommes

c reelement la meme chose MAIS le tube sera present dans le systeme de fichiers
