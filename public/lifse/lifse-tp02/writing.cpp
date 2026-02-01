#include <iostream>
#include <string>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>

int main(void) {

  char tab[12];
  tab[0] = 'a';
  tab[1] = 'b';
  tab[2] = 'c';
  tab[3] = 'd';
  tab[4] = 'e';
  tab[5] = 'f';
  tab[6] = 'g';
  tab[7] = 'h';
  tab[8] = 'i';
  tab[9] = 'j';
  tab[10] = '\n';
  tab[11] = '\0';

  int fd;
  std::string test = "abcdefghij";
  std::cout<<test<<test;
  // première ouverture et écriture dans le fichier
  // ouverture du fichier
  
  fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  // WRONLY = write read only
  // CREAT = create a file if the the pathname point to nowhere
  // TRUNC = permets d'ecraser le fichier 
  // S_IRUSR ET permets demander les droits ? c relatif au droit ?
  // ok non en fait ca permets dentrer dans le repertoire qui contient le fichier
  if(fd == -1) {
    std::cerr << "Erreur : " << strerror(errno) << std::endl;
    exit(1);
  }
  write(fd,tab,12);
  close(fd);
  
  // écriture dans le fichier (question 2)
  fd = open("test.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
  char toto[22] = "Toto fait du velo!!!";
  int wr = write(fd,toto, 22);
  close(fd);
  // deuxième ouverture et écriture dans le fichier (question 3)
  
  if(fd == -1) {
    std::cerr << "Erreur : " << strerror(errno) << std::endl;
    exit(1);
  }
  return 0;
}

