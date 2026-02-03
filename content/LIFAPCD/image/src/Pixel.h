#ifndef _PIXEL_H
#define _PIXEL_H


struct Pixel {
  // on fait une structure parce que c comme une classe en public
  unsigned char r;
  unsigned char g;
  unsigned char b;
  Pixel();
  Pixel(unsigned char nr,unsigned char ng,unsigned char nb);
};


#endif
