#include <stdio.h>
#include "Reel.h"
#include "NombreComplexe.h"

int main()
{
  Reel r=5.0;
  Complexe c1,c2,c3;
  initialisationComplexeParDefaut(&c1);
  affiche(c1);
  initialisationComplexe2Reels(&c2,PI,r);
  affiche(c2);
  initialisationComplexeParCopie(&c3,c2);
  affiche(c3);
  affectationComplexe(&c2,c1);
  affiche(c2);
  affectationComplexe(&c2,addition(c3,c3));
  affiche(c2);
  printf("Nombre de complexes existants : %d \n",nbComplexesVivants());
  testament(&c1);
  testament(&c2);
  testament(&c3);
  printf("Nombre de complexes existants : %d \n",nbComplexesVivants());
  return 0;
}

