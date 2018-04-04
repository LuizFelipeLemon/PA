//Luiz Felipe Santana
//PA 2018.1
#include<iostream>

using namespace std;


class MyString
{
public:
    inline MyString() N(0), x(NULL) {};
    MyString(MyString &&) = default;
    MyString(const MyString &S) = default;
    MyString &operator=(MyString &&) = default;
    MyString &operator=(const MyString &S) = default;
    ~MyString();

    inline unsigned size() const {return N;}
    char getChar(unsigned index) const;
    inline char operator[](unsigned index) const {getChar(index);}

    ostream &operator<<(ostream &print, const MyString &S) const;

    istream &operator>>(istream &put, MyString &S);

    void setChar(unsigned index, char c);

    MyString operator+(const MyString &S2) const;

    bool operator<(const MyString &S2) const;

private:
    unsigned N;
    char *x;

    void criar(unsigned numC);
    void copiar(MyString &S);
    void limpar();

};

MyString::MyString()
{
}

MyString::~MyString()
{
}           