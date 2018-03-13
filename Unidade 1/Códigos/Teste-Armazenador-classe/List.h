#ifndef _LISTA_do_LUIZ_H_
#define _LISTA_do_LUIZ_H_

#include<iostream>

using namespace std;



typedef int valor;

class List{
    private:

        unsigned N;
        valor *p;

    public:

        inline List(void) : N(0), p(0) {}

        explicit List(unsigned int size);

        List(const List &L);

        ~List();

        void add(valor a);

        friend ostream& operator<<(ostream &X, const List &L);]

        inline void printAll(void) const { cout<<*this<<endl;};



        void remove(void);

        inline unsigned items(void) const { return N; }

        valor get(unsigned int pos) const;

        inline valor getFirst() const {return get(0)};

        void operator=(const List &L);







};

#endif