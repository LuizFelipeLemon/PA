#include <iostream>

using namespace std;

class vector_double
{
private:
  unsigned N;
  double *x;
  void copy(const vector_double &V);
public:
  void clear();
  inline vector_double(): N(0), x(NULL) {}
  inline vector_double(const vector_double &V) {copy(V);}
  inline ~vector_double() {clear();}
  inline void operator=(const vector_double &V) {if (this!=&V) {clear(); copy(V);}}

  inline unsigned size() const {return N;}
  double operator[](unsigned id) const;
  double &operator[](unsigned id);

  void push_back(double Valor);
  void erase(unsigned id);
};

void vector_double::copy(const vector_double &V)
{
  N = V.N;
  x = (N==0 ? NULL : new double[N]);
  for (unsigned i=0; i<N; i++) x[i] = V.x[i];
}

void vector_double::clear()
{
  if (x!=NULL) delete[] x;
  x = NULL;
  N = 0;
}

double vector_double::operator[](unsigned id) const
{
  if (id >= N) {
    cerr << "Indice invalido\n";
    return 0;
  }
  return x[id];
}

double &vector_double::operator[](unsigned id)
{
  static double nada=0;
  if (id >= N) {
    cerr << "Indice invalido\n";
    return nada;
  }
  return x[id];
}

void vector_double::push_back(double Valor)
{
  double *prov = new double[N+1];
  for (unsigned i=0; i<N; i++) prov[i] = x[i];
  prov[N] = Valor;
  if (x!=NULL) delete[] x;
  x = prov;
  N++;
}

void vector_double::erase(unsigned id)
{
  if (id >= N) {
    cerr << "Indice invalido\n";
    return;
  }
  double *prov = (N>1 ? new double[N-1] : NULL);
  N--;
  for (unsigned i=0; i<N; i++) prov[i] = (i<id ? x[i] : x[i+1]);
  if (x!=NULL) delete[] x;
  x = prov;
}

int main()
{
  vector_double Z;

  Z.push_back(3.14);    // Z[0]
  Z.push_back(0.6667);  // Z[1]
  Z.push_back(-15);     // Z[2]

  Z[2] = -7.2;  // Usa o operator[] nao const
  Z[3] = 1;     // Gera erro
  for (unsigned i=0; i<Z.size(); i++) cout << Z[i] << ' ';  // Usa o operator[] const
  cout << endl;
}
