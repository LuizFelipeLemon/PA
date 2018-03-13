#include <iostream>
#include <string>

using namespace std;

string valorPorExtenso(unsigned int valor);

int main()
{
  unsigned int V;
  string E;

  do {
    cout << "Digite o valor total (entre 0 e 999): ";
    cin >> V;
  } while (V>999);

  E = valorPorExtenso(V);

  cout << "Valor por extenso:\n" << E << endl;
}

string valorPorExtenso(unsigned int valor)
{
  if (valor > 999)
  {
      cerr << "Desculpe, eu nao sei converter numeros tao grande assim (" << valor << ")\n";
      return "???";
  }
  if (valor == 0)
  {
      return "zero";
  }
  unsigned int N100, N10, N1;
  string extenso;

  N100 = valor/100;
  valor = valor%100;

  N10 = valor/10;
  valor = valor%10;

  N1 = valor;

  switch(N100) {
  case 1:
    if (N10>0 || N1>0) {
      extenso = "cento";
    }
    else {
      extenso = "cem";
    }
    break;
  case 2:
    extenso = "duzentos";
    break;
  case 3:
    extenso = "trezentos";
    break;
  case 4:
    extenso = "quatrocentos";
    break;
  case 5:
    extenso = "quinhentos";
    break;
  case 6:
    extenso = "seiscentos";
    break;
  case 7:
    extenso = "setecentos";
    break;
  case 8:
    extenso = "oitocentos";
    break;
  case 9:
    extenso = "novecentos";
    break;
  default:
    extenso = "";
    break;
  }

  if (N100>0 && N10>0) {
    extenso = extenso+" e ";
  }

  switch(N10) {
  case 1:
    switch(N1) {
    case 1:
      extenso += "onze";
      break;
    case 2:
      extenso += "doze";
      break;
    case 3:
      extenso += "treze";
      break;
    case 4:
      extenso += "quatorze";
      break;
    case 5:
      extenso += "quinze";
      break;
    case 6:
      extenso += "dezesseis";
      break;
    case 7:
      extenso += "dezessete";
      break;
    case 8:
      extenso += "dezoito";
      break;
    case 9:
      extenso += "dezenove";
      break;
    default:
      extenso += "dez";
      break;
    }
    N1=0;
    break;
  case 2:
    extenso += "vinte";
    break;
  case 3:
    extenso += "trinta";
    break;
  case 4:
    extenso += "quarenta";
    break;
  case 5:
    extenso += "cinquenta";
    break;
  case 6:
    extenso += "sessenta";
    break;
  case 7:
    extenso += "setenta";
    break;
  case 8:
    extenso += "oitenta";
    break;
  case 9:
    extenso += "noventa";
    break;
  default:
    break;
  }

  if ((N100>0 || N10>0) && N1>0) {
    extenso = extenso+" e ";
  }

  switch(N1) {
  case 1:
    extenso += "um";
    break;
  case 2:
    extenso += "dois";
    break;
  case 3:
    extenso += "três";
    break;
  case 4:
    extenso += "quatro";
    break;
  case 5:
    extenso += "cinco";
    break;
  case 6:
    extenso += "seis";
    break;
  case 7:
    extenso += "sete";
    break;
  case 8:
    extenso += "oito";
    break;
  case 9:
    extenso += "nove";
    break;
  default:
    break;
  }

  return extenso;
}
