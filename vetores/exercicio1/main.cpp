#include <iostream>

using namespace std;

/*1-) Fazer um programa que leia vários números inteiros e positivos. A leitura
 * se encerra quando encontrar um número negativo ou quando o vetor ficar
 * completo. Sabe-se que o vetor possui, no máximo, 10 elementos. Gerar e
 * imprimir um vetor onde cada elemento é o inverso do correspondente do vetor
 * original.*/
int main() {
  const int LENGTH = 10;
  int vetor[LENGTH] = {0};
  int vetor_inverso[LENGTH] = {0};

  int num_in;
  int filled_len = LENGTH;
  for (int i = 0; i < LENGTH; ++i) {
    cout << "Digite o " << i + 1 << "° número: ";
    cin >> num_in;

    if (num_in < 0) {
      filled_len = i;
      break;
    }

    vetor[i] = num_in;
  }

  for (int i = 0; i < filled_len; ++i) {
    vetor_inverso[i] = vetor[i] * -1;
    cout << vetor_inverso[i] << ' ';
  }

  return 0;
}