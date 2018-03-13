#include<iostream>

using namespace std;


int main(){

    float Num;
    unsigned N = 0;
    float *arr = NULL;
    unsigned i;

    do{
        cout<<"Digite um número (0.0 para parar)";
        cin>> Num;
        if(Num != 0.0){
            float *prov = new float[N+1];
            for(i = 0;i<N;i++) prov[i] = arr[i];
            prov[N] = Num;

            if(arr!= NULL) delete[] arr;
            arr = prov;
            N++;

        }

    }while(Num != 0.0);

    for(int j =0; j < N; j++){

            cout<<arr[j]<<"\n";
    }

    if(N==0){

        cout<<"Você não digitou nenhum número!!\n";
    }
    else{

        float soma(0.0);
        for(i = 0; i<N;i++) soma += arr[i];
        float media = soma/N;
        unsigned num_abaixo(0), num_acima(0);

        for(i = 0; i < N;i++){

            if(arr[i]>media) num_acima++;
            if(arr[i]<media) num_abaixo++;

        }

        cout<<"A média é: " << media << endl;
        cout<<"Números abaixo: "<<num_abaixo<<endl;
        cout<<"Números acima: "<<num_acima<<endl;
    }

    if(arr!= NULL) delete[] arr;

}