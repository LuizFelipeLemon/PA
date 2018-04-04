#include "Imagem.h"
#include <iostream>

using namespace std;

typedef unsigned char pixel;

Imagem::Imagem() {
  **image = 0;

  NLin = 0;
  NCol = 0;
}

Imagem::Imagem(const Imagem &Im) {
  NLin = Im.NLin;
  NCol = Im.NCol;

  image = new pixel *[NLin];
  for (unsigned i = 0; i < NLin; i++) {
    image[i] = new pixel[NCol];
    for (unsigned j = 0; j < NCol; j++) {
      image[i][j] = Im.image[i][j];
    }
  }
}

Imagem::Imagem(unsigned _NLin, unsigned _NCol) {
  NLin = _NLin;
  NCol = _NCol;

  image = new pixel *[NLin];
  for (unsigned i = 0; i < NLin; i++) {
    image[i] = new pixel[NCol];
    for (unsigned j = 0; j < NCol; j++) {
      image[i][j] = 0;
    }
  }
}

void Imagem::operator=(const Imagem &Im) {
  NLin = Im.NLin;
  NCol = Im.NCol;

  if (NCol != 0)
    for (unsigned i = 0; i < NLin; i++) delete[] image[i];

  if (NLin != 0) delete[] image;

  image = new pixel *[NLin];
  for (unsigned i = 0; i < NLin; i++) {
    image[i] = new pixel[NCol];
    for (unsigned j = 0; j < NCol; j++) {
      image[i][j] = Im.image[i][j];
    }
  }
}

Imagem::~Imagem() {
  if (NCol != 0)
    for (unsigned i = 0; i < NLin; i++) delete[] image[i];

  if (NLin != 0) delete[] image;
}

pixel Imagem::getPixel(unsigned _NLin, unsigned _NCol) const {
  if (_NLin < NLin && _NCol < NCol) {
    return image[_NLin][_NCol];
  }
  return -1;
}

void Imagem::setPixel(unsigned _NLin, unsigned _NCol, pixel val) {
  if (_NLin < NLin && _NCol < NCol && val < 256 && val > -1) {
    image[_NLin][_NCol] = val;
  }
}

void Imagem::paintRectangle(unsigned x1, unsigned y1, unsigned x2, unsigned y2,
                            int val) {
  if (x1 > 0 && y1 > 0 && y2 > 0 && x1 > 0) {
    if (NLin > y1 && NCol > x1) {
      if (NLin > y1 && NCol > x1) {
        if (val > 0 && val < 256) {
          for (unsigned i = y2; i < y1 + 1;
               i++) {  // eixo 0,0 igual a plano cartesiano
            for (unsigned j = x1; j < x2 + 1; j++) {
              image[i][j] = val;
            }
          }
        }
      }
    }
  }
}
