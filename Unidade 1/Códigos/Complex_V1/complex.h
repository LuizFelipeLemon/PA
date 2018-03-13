#include <iostream>

using namespace std;

// Tipo Complex

class Complex
{
private:
  double real, imag;
public:
  /// Construtor default e especifico
  /// Tambem eh um conversor implicito de double para Complex
  inline Complex(double R=0.0, double I=0.0): real(R), imag(I) {}
  /// Construtor por copia (poderia nao ser implementado)
  inline Complex(const Complex &C): real(C.real), imag(C.imag) {}

  /// Funcoes de consulta
  inline double getReal() const {return real;}
  inline double getImag() const {return imag;}

  /// Entrada e saida de dados
  friend ostream &operator<<(ostream &X, const Complex &C);
  friend istream &operator>>(istream &X, Complex &C);

  /// Operadores
  Complex operator+(const Complex &C2) const;
  Complex operator*(const Complex &C2) const;
};

