#include <cmath>
#include <iostream>

using namespace std;

class Ponto {
 private:
  double x, y;

 public:
  inline Ponto() : x(0.0), y(0.0) {}
  inline Ponto(double X, double Y) : x(X), y(Y) {}
  ostream &imprimir(ostream &O) const;
  istream &ler(istream &I);
  double distancia(const Ponto &B) const;
};

ostream &Ponto::imprimir(ostream &O) const {
  O << '[' << x << ';' << y << ']';
  return O;
}

istream &Ponto::ler(istream &I) {
  I >> x >> y;
  return I;
}

inline ostream &operator<<(ostream &O, const Ponto &P) { return P.imprimir(O); }
inline istream &operator>>(istream &I, Ponto &P) { return P.ler(I); }

inline double pow2(double x) { return x * x; }

double Ponto::distancia(const Ponto &B) const {
  return sqrt(pow2(x - B.x) + pow2(y - B.y));
}

class Circulo : public Ponto {
 private:
  double r;

 public:
  inline Circulo() : Ponto(), r(0.0) {}
  inline Circulo(double X, double Y, double R) : Ponto(X, Y), r(R) {}
  ostream &imprimir(ostream &O) const;
  istream &ler(istream &I);
};

ostream &Circulo::imprimir(ostream &O) const {
  // ALTERNATIVA 1
  Ponto::imprimir(O);  // Chama o imprimir do Ponto
  // ALTERNATIVA 2
  // O << (const Ponto&)*this;  // Chama o operator<< para Ponto

  O << r;
  return O;
}

istream &Circulo::ler(istream &I) {
  // ALTERNATIVA 1
  Ponto::ler(I);  // Chama o ler do Ponto
  // ALTERNATIVA 2
  // I >> (Ponto&)*this;  // Chama o operator>> para Ponto

  I >> r;
  return I;
}

inline ostream &operator<<(ostream &O, const Circulo &C) {
  return C.imprimir(O);
}
inline istream &operator>>(istream &I, Circulo &C) { return C.ler(I); }

int main(void) {
  Circulo C1(1.0, 0.7, 12.0), C2;

  cout << "1o circulo: " << C1 << endl;
  cout << "Digite o 2o circulo: ";
  cin >> C2;

  // Utilizacao de um metodo de Ponto passando como parametro um Circulo, e nao
  // um Ponto
  cout << "Distancia entre os centros dos circulos: " << C1.distancia(C2)
       << endl;

  return 0;
}
