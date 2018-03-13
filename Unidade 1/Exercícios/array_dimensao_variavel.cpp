/*
O objetivo eh fazer um programa que solicite ao usuario que
digite uma sequencia de numeros reais nao nulos. Quando o
usuario digitar zero, entende-se que ele concluiu a entrada
dos dados.
Apos a entrada dos dados, o programa deve calcular e imprimir
as seguintes informacoes:
1) A media aritmetica dos numeros digitados (sem incluir o
zero final).
2) Quantos dos numeros estao acima e abaixo da media (sem
contar com o zero final.
*/

#include <iostream>

using namespace std;

int main()
{
    float Num;
    unsigned N=0;
    ...

    do
    {
        cout << "Digite um numero [0.0 para parar]: ";
        cin >> Num;
        if (Num != 0.0)
        {
            N++;
            ...
        }
    } while (Num != 0.0);

    if (N==0)
    {
        cout << "Voce nao digitou nenhum numero!!!\n";
    }
    else
    {
        ...
        cout << "A media eh: " << ... << endl;
        cout << "Acima da media: " << ... << endl;
        cout << "Abaixo da media: " << ... << endl;
    }

    return 0;
}
