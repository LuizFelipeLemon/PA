#include<iostream>
#include<cmath>

using namespace std;



void complexo::ler(){

    cout<<"Digite um valor pra parte real:\n";
    cin>>real;
    cout<<"Digite um valor pra parte imaginaria:\n";
    cin>>imag;

}

complexo complexo::soma(complexo B) const {

    complexo z3;
    z3.real = real + B.real;
    z3.imag = imag + B.imag;

    return z3;
}

void complexo::imprime() const{

    cout<< real << (imag > 0 ? '+' : '-') << "j" << fabs(imag)<<endl;
}



complexo complexo::produto(complexo C2) const{

    complexo z3;
    z3.real = real * C2.real - imag*C2.imag;
    z3.imag = real*C2.imag - C2.real*imag;

    return z3;
}

int main(){
    complexo C1,C2,C3,S,P;
    C1.ler();
    C2.ler();
    //C3.ler();

    S = C1.soma(C2);
    P = C1.produto(C2);

    S.imprime();
    P.imprime();

    return 0;
}