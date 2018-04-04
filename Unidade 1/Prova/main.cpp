// Luiz Felipe Santana
// PA 2018.1
// g++ -g -Wall -I/ Voo.cpp main.cpp -o test
#include <iostream>
#include "Imagem.h"

using namespace std;

int main() {
  Imagem img(240, 320);
  img.paintRectangle(0, 240, 320, 0, 127);
  img.paintRectangle(10, 230, 200, 100, 0);
  img.paintRectangle(140, 120, 310, 10, 255);
}