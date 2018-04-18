#include <iostream>
#include <string>

using namespace std;

template <class T>
T soma(T P1, T P2)
{
  return P1+P2;
}

int main()
{
  cout << soma(1, 3) << endl;
  cout << soma(1.3, 3.72) << endl;
  cout << soma<int>(1.3, 3.72) << endl;
  cout << soma(string("Adelardo"),string(" Medeiros")) << endl;

  return 0;
}
