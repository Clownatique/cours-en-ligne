#include "Pixel.h"

Pixel::Pixel():r(0),g(0),b(0){}
// petit mecanisme pour initialiser rapidement

Pixel::Pixel(unsigned char nr, unsigned char ng, unsigned char nb){
        
    r = nr;
    g = ng;
    b = nb;
}
