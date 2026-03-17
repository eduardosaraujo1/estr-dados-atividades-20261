#include <iostream>

using namespace std;

/*7-) Fazer um programa que, dados dois vetores de 7 posições cada, efetue as
 * operações aritméticas básicas, indicadas por um terceiro vetor cujos dados
 * também são fornecidos pelo usuário, gerando e imprimindo um quarto vetor.*/
int main() {
  const int LENGTH = 7;
  int vetor_a[LENGTH] = {0};
  int vetor_b[LENGTH] = {0};
  char vetor_op[LENGTH] = {0};
  double vetor_out[LENGTH] = {0};

  for (int i = 0; i < LENGTH; ++i) {
    cout << '(' << i + 1 << ") digite o número da esquerda: ";
    cin >> vetor_a[i];
    cout << '(' << i + 1 << ") digite o operador: ";
    cin >> vetor_op[i];
    cout << '(' << i + 1 << ") digite o número da direita: ";
    cin >> vetor_b[i];
  }

  for (int i = 0; i < LENGTH; ++i) {
    switch (vetor_op[i]) {
    case '+':
      vetor_out[i] = vetor_a[i] + vetor_b[i];
      break;
    case '-':
      vetor_out[i] = vetor_a[i] - vetor_b[i];
      break;
    case '/':
      vetor_out[i] = (double)vetor_a[i] / (double)vetor_b[i];
      break;
    case '*':
      vetor_out[i] = (double)vetor_a[i] * (double)vetor_b[i];
      break;
    }
  }

  for (auto v : vetor_out) {
    cout << v << ' ';
  }

  return 0;
}
