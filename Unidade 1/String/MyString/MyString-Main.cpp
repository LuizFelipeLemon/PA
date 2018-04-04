#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
  MyString A("Adelardo"), B("Medeiros"), C;

  C = A + " " + B;
  //B = C + 1;
  cout << "A=" << A << endl;
  cout << "B=" << B << endl;
  cout << "C (A+B)=" << C << endl;
  cout << "A==C? " << (A==C ? "Sim" : "Nao") << endl;
  cout << "A<C? " << (A<C ? "Sim" : "Nao") << endl;
  cout << "A>C? " << (A>C ? "Sim" : "Nao") << endl;
  cout << "C upp=" << C.toupper() << endl;
  cout << "C low=" << C.tolower() << endl;
}
