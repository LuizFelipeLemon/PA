#include<iostream>
#include<cmath>

using namespace std;

struct complexo{
  double a,b;

};

complexo operator+(complexo &z1, complexo &z2){

    complexo z3;
    z3.a = z1.a + z2.a;
    z3.b = z1.b + z2.b;

    return z3;
}

complexo produto(complexo &z1, complexo &z2){

    complexo z3;
    z3.a = z1.a * z2.a - z1.b*z2.b;
    z3.b = z1.a * z2.b - z2.a*z1.b;

    return z3;
}

void imprime(complexo z1){

    cout<< z1.a << (z1.b > 0 ? '+' : '-') << "j" << fabs(z1.b);
}

complexo ler(){

    complexo z1;
    cout<<"Digite um valor pra parte real:\n";
    cin>>z1.a;
    cout<<"Digite um valor pra parte imaginaria:\n";
    cin>>z1.b;

}



int main(){

    cout<<"Oi\n";


    complexo a = ler();
    complexo b = ler();

    imprime(a);
    imprime(b);

    imprime(a+b);
    

}