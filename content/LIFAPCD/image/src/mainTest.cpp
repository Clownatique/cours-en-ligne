#include "Pixel.h"
#include <iostream>

using namespace std;

int main(){
  Pixel p1;
  Pixel p2(10,20,30);
  cout << int(p1.r)<<endl;
  return 0;
}
