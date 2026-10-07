// LIFAP6 - Automne 2017 - R. Chaine

#include "element.h"
#include "liste-triee.h"
#include <charconv>
#include <cstdio>

int main()
{
  ListeTriee lili;
  std::printf("Lili\n");
  lili.affichage();
  for(int i=5;i>=0;i--){
    std::printf("%d",i);
    lili.insereCellule(i);
  }
  lili.affichage();
  std::printf("reussi\n");
  return 0;
}
