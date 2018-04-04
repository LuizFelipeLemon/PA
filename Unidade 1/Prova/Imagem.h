#ifndef _LIB_DO_LUIZ_PARA_IMAGENS_
#define _LIB_DO_LUIZ_PARA_IMAGENS_

#include <iostream>

using namespace std;

typedef unsigned char pixel;

class Imagem {
 public:
  Imagem();
  Imagem(const Imagem &i);
  Imagem(unsigned _NLin, unsigned _NCol);
  ~Imagem();

  void operator=(const Imagem &i);
  pixel getPixel(unsigned _NLin, unsigned _NCol) const;
  void setPixel(unsigned _NLin, unsigned _NCol, pixel val);
  void paintRectangle(unsigned x1, unsigned y1, unsigned x2, unsigned y2,
                      int val);

 private:
  pixel **image;
  unsigned NLin;
  unsigned NCol;
};

#endif