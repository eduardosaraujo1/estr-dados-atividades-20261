#include <iostream>

using namespace std;

/*3-) Criar um programa que crie um vetor com 10 posições e carregue com uma
 * palavra, depois imprima o vetor de uma maneira que exiba a palavra ao
 * contrário (ex. casa...asac)*/
int main() {
  const int LENGTH = 10;
  char vetor[LENGTH] = {0};

  for (int i = 0; i < LENGTH; ++i) {
    cout << "Digite  " << i + 1 << "ª letra: ";
    cin >> vetor[i];
  }

  for (int i = LENGTH - 1; i >= 0; --i) {
    cout << vetor[i] << ' ';
  }

  return 0;
}
