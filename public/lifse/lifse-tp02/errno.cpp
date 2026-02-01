#include <iostream>
#include <errno.h>
#include <regex>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>

int main(void) {
  char txt[256] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
                  "sed do eiusmod tempor incididunt ut labore et dolore magna "
                  "aliqua. Ut enim ad minim veniam, quis nostrud exercitation "
                  "ullamco laboris nisi ut aliquip ex ea commodo consequat.";
  std::cout << txt << std::endl;
  
  int wrong_fd = open("nofile.txt", O_RDONLY);
  // exo 2 1): rien de marquer
  // avec la variable errno
  int ret = write(10, txt, 256 * sizeof(char));
  // exo 2 2): errno is set to -1
  // 3) donc il faut afficher errno tsais (avec )
  std::cerr<< "Erreur :"<< strerror(errno) << std::endl;
  return 0;
}
