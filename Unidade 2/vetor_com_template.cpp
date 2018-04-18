#include <iostream>

using namespace std;

template <class TT>
class vector
{
private:
    unsigned N;
    TT *x;
    void copy(const vector &V);
public:
    void clear();
    inline vector(): N(0), x(NULL) {}
    inline vector(const vector &V) {copy(V);}
    inline ~vector() {clear();}
    inline void operator=(const vector &V) {if (this!=&V) {clear(); copy(V);}}

    inline unsigned size() const {return N;}
    TT operator[](unsigned id) const;
    TT &operator[](unsigned id);

    void push_back(TT Valor);
    void erase(unsigned id);
};

template <class TT>
void vector<TT>::copy(const vector<TT> &V)
{
    N = V.N;
    x = (N==0 ? NULL : new TT[N]);
    for (unsigned i=0; i<N; i++) x[i] = V.x[i];
}

template <class TT>
void vector<TT>::clear()
{
    if (x!=NULL) delete[] x;
    x = NULL;
    N = 0;
}

template <class TT>
TT vector<TT>::operator[](unsigned id) const
{
    if (id >= N) {
        cerr << "Indice invalido\n";
        return 0;
    }
    return x[id];
}

template <class TT>
TT &vector<TT>::operator[](unsigned id)
{
    static TT nada=0;
    if (id >= N) {
        cerr << "Indice invalido\n";
        return nada;
    }
    return x[id];
}

template <class TT>
void vector<TT>::push_back(TT Valor)
{
    TT *prov = new TT[N+1];
    for (unsigned i=0; i<N; i++) prov[i] = x[i];
    prov[N] = Valor;
    if (x!=NULL) delete[] x;
    x = prov;
    N++;
}

template <class TT>
void vector<TT>::erase(unsigned id)
{
    if (id >= N) {
        cerr << "Indice invalido\n";
        return;
    }
    TT *prov = (N>1 ? new TT[N-1] : NULL);
    N--;
    for (unsigned i=0; i<N; i++) prov[i] = (i<id ? x[i] : x[i+1]);
    if (x!=NULL) delete[] x;
    x = prov;
}

int main()
{
    vector<float> Z;

    Z.push_back(3.14);    // Z[0]
    Z.push_back(0.6667);  // Z[1]
    Z.push_back(-15);     // Z[2]

    Z[2] = -7.2;  // Usa o operator[] nao const
    Z[3] = 1;     // Gera erro
    for (unsigned i=0; i<Z.size(); i++) cout << Z[i] << ' ';  // Usa o operator[] const
    cout << endl;
}
