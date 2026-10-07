#include <cstring>
#include <iostream>

using namespace std;

int main(void){
  char tab[11];
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
  tab[10] = 'k';
  tab[11] = '\0';

  string test = "abcdefghij";
  cout<<test<<endl;

  char big_tab[21];

  for (int i = 0 ; i < 20 ; i++){
    big_tab[i] = '-';
  }
  big_tab[21] = '\0';
  int i = 0;
  while (big_tab[i] != '\0'){
    cout << big_tab[i];
    i++;
  }
  memcpy(& big_tab, &tab[5], 5);
  cout<<big_tab;
  return 0;
}
