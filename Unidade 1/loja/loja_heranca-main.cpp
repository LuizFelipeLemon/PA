#include <iostream>
#include <string>
#include <limits>
#include "loja_heranca.h"

using namespace std;

int main()
{
    Loja X;
    Livro L;
    CD C;
    DVD D;
    string A;
    int opcao(0);
    unsigned id(0);

    cout << "CONTROLE DE ACERVO\n\n";
    do
    {
        do{
            cout << "1/-1 - Incluir/excluir livro\n";
            cout << "2/-2 - Incluir/excluir CD\n";
            cout << "3/-3 - Incluir/excluir DVD\n";
            cout << "4 - Imprimir acervo em tela\n";
            cout << "5 - Ler acervo de arquivo\n";
            cout << "6 - Salvar acervo em arquivo\n";
            cout << "0 - Sair\n";
            cout << "Opcao: ";
            cin >> opcao;
        } while (opcao<-3 || opcao>6);

        // Entrada de dados, de acordo com a opcao
        switch (opcao)
        {
        case -3:
        case -2:
        case -1:
            cout << "Id do objeto a excluir: ";
            cin >> id;
            break;
        case 5:
        case 6:
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Nome do arquivo: ";
            getline(cin,A);
            break;
        case 1:
            cout << "LIVRO>>\n";
            cin >> L;
            break;
        case 2:
            cout << "CD>>\n";
            cin >> C;
            break;
        case 3:
            cout << "DVD>>\n";
            cin >> D;
            break;
        case 4:
        default:
            break;
        }

        // Funcao a ser chamada, de acordo com a opcao
        switch (opcao)
        {
        case -3:
            X.excluirDVD(id);
            break;
        case -2:
            X.excluirCD(id);
            break;
        case -1:
            X.excluirLivro(id);
            break;
        case 0:
        default:
            break;
        case 1:
            X.incluirLivro(L);
            break;
        case 2:
            X.incluirCD(C);
            break;
        case 3:
            X.incluirDVD(D);
            break;
        case 4:
            X.imprimir();
            break;
        case 5:
            X.ler(A.c_str());
            break;
        case 6:
            X.salvar(A.c_str());
            break;
        }
    } while (opcao!=0);
}
