#include<iostream>
#include"List.h"


List::List(unsigned int size){
    N = size;
    if(N != 0)
        p = new valor[N];

}

void List::add(valor a){

    valor *temp = new valor[N+1];
    for(unsigned i = 0; i < N; i++) temp[i] = p[i];
    temp[N] = a;
    if(p != NULL) delete[] p;
    p = temp;

}

List::List(const List &L){

    N = L.N;
    if(N != 0)
        p = new valor[N];
    for(unsigned i = 0; i < N;i++) p[i] = L.p[i];


}
/// Luiz Felipe
void List::operator=(const List &L){
    if(this != &L){
        if(p!=NULL) delete[] p;
        N = L.N;
        if(N != 0)
            p = new valor[N];
        for(unsigned i = 0; i < N;i++) p[i] = L.p[i];
    }

}

ostream& operator<<(ostream& X, const List &L)
{
  for (unsigned i=0; i<L.N; i++)
  {
    if (i!=0) X << ' ';
    X << L.p[i];
  }
  return X;
}

valor List::get(unsigned int pos)const {

    if(pos >= N){
        cout<<"NVN";
        return 0;
    }

    return p[pos];

}