#include <iostream>
#include <cmath>
#include "complex.h"

using namespace std;

// As funcoes
istream &operator>>(istream &X, Complex &C)
{
  cout << "R? ";
  X >> C.real;
  cout << "I? ";
  X >> C.imag;
  return X;
}

ostream &operator<<(ostream &X, const Complex &C)
{
  X << C.real << (C.imag<0.0 ? '-' : '+') << 'j' << fabs(C.imag);
  return X;
}

// Os metodos
Complex Complex::operator+(const Complex &C2) const
{
  Complex prov;
  prov.real = real+C2.real;
  prov.imag = imag+C2.imag;
  return prov;
}

Complex Complex::operator*(const Complex &C2) const
{
  Complex prov;
  prov.real = real*C2.real - imag*C2.imag;
  prov.imag = real*C2.imag + C2.real*imag;
  return prov;
}
