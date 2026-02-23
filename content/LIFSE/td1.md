+++
draft = false
title = "td1 de lifse"
+++

## exercice 1

### definition de write

_la fonction permets de lire count octets a partir de filedescriptor fd et les en memoire dans buf_

**fd** ca represente la maniere dont on peut interagir avec le fichier
en general on mets la valeur de retour de open
on lappelle le file descriptor

**buf** cest ladresse de lendroit ou on a stocke les donnes a ecrire

**ssize_t** c le nombre doctets quon mets dans le fichier
size_t jsp pk mais c un sous type des unsigned int

### definition de read

_la fonction permets de lire count octets a partir de filedescriptor fd et les en memoire dans buf_

**fd** ca represente la maniere dont on peut interagir avec le fichier
en general on mets la valeur de retour de open
on lappelle le file descriptor

**buf** cest ladresse de lendroit ou on a stocke les donnes a ecrire

**count** c le nombre doctets que le systeme va compter avant de sarreter decrire/lire le fichier

tout ces appels permettent de la lecture/ecriture en binaire

a contrario, les bibliotheques fstream font differemment

### reecriture avec dautre buffers

```c++
char tab[64];
write(fd, tab, 64) //ou write(fd, &tab[0],64*sizeof(char)), mais c mieux dutiliser sizeof (sur char ou sur long dcp) pour etre sur
```

## exercice 2

```c++
int main(void) {
  int ret, n, fd = open("test.dat", O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
  if(fd == −1) return −1;

  char msg[] = "value"; 
  n = (strlen(msg) + 1) ∗ sizeof(char);
  ret = write(fd, msg, n); // pour savoir si le write c bien passe
  if(ret != n) return −1;

  unsigned int x = 42; // askip c une blague
  n = sizeof(unsigned int); //pour correctement le stocker
  ret = write(fd, &x, n); 

  if(ret != n) return −1;
  unsigned int tab[3] = {1, 2, 0x12345678};
  n = 3 ∗ sizeof(unsigned int); // on sassure du nombre doctets..
  ret = write(fd, tab, n); // pour correctement les stocker
  if(ret != n) return −1;// on verifie

  ret = close(fd); // on le ferme..
  if(ret == −1) return −1; // en verifiant une derniere fois...

  return 0;
}
```

### connaitre la valeur de retour

on utilise la var denvironnement $?

### nombre doctets ecrit lligne 7

on ecrit 6 caracteres de 1 octets un octet (5 lettres et un char de fin de chaine)

### nombre doctets que prends un hexa

un hexa c 4 bit
donc un octet c 2 nombre hexadecimale

bah dcp on utilise la fonction hex() en python

### la boucle de la ligne 5 a 9

```c++
int main(void) {
  int ret, fd = open("test.dat", O_RDONLY);// on ouvre un fichier en lecture seule
  if(fd == −1) return 1;

  do {
    char c;
    ret = read(fd, &c, 1);//je lis un octet du fichier en mettant le contenu a ladresse de c
    if(ret == 1) printf("%02x ", c); // affiche ce quon lit si on a bien reussi a le lire
    //printf() <-afficher en c
    // % precise le format dans lequel on ecrit
    // %c ecrit en ascii
    // %02x ecrit en hex
  } while(ret == 1);

  printf("\n"); // affiche un retour à la ligne
  if(ret == −1) return −1;

  ret= close(fd);
  if(ret == −1) return −1;
}
```

donc on lit le fichier tant quil y a des trucs a lire, et on ressort le tout en hexadecimal, sur la sortie standard

### la mysterieuse chaine en hexadecimal (c le contenu de test.dat)

bon en gros cette chaine doctets en hex c les chars qui formet "value"
donc e c le dernier avant loctet 00 (qui signifie fin de chaine de charactere) => 65

donc 4 octets pour un entier non signe

## exercice 3

on a un tres grand tableau de charactere
pour lecrire dans un fichier on va ecrire par bloc de caractere dun coup

```c++
int writech(int fd, const char* v, int n){ // const permets de bloquer les modifications de ladresse v
  const int tailleb= 64; //taille des blocs ecrits
  int nbwr, rem = n;//nbwr nombre ecrit et rem = restant memoire
  const char * p = v;// donc les deux pointeurs pointent au MEME endroit
  while (rem >= tailleb){
    nbwr = write(fd,p,tailleb)
    rem -= nbwr; //rem, restant en memoire, combien il reste en memoire
    p += nbwr;
    while (rem > 0){
      nbwr = write(fd,p,rem);
      rem -= nmwr;
      p+=nbwr;
    }
    return 0;
  } // a la fin de la boucle il nous restera soit -64, soit 0
```

## exercice 4

```
/
├── bin
│   └── visionneurPDF
└── home
    └── fontaine
        ├── prive
        │   └── correction.pdf
        └── sujet.pdf
```

cp /home/fontaine/prive/correction.pdf ~

```
- --- --- ---
```

1er tiret c le type du fichier
2eme groupe de tiret c les droits du proprietaires
2eme groupe de tiret c les droits du groupe
3eme groupe de tiret c les droits du autres

les tirets peuvent etre remplaces par
r = lecture
w = ecriture
x =
s = nexiste que dans la colonne du proprietaire (set uid bit)
=> donc ca montre le fait que ladministrateur a permis lexecution de cet executable comme etant le proprietaire
donc elise pour regarder ses scans de onepiece avec ce visionneur pdf
desole davoir pose cette question la team
