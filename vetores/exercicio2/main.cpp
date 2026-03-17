#include <iostream>

using namespace std;

/*2-) Fazer um programa que digite vários números no vetor de tamanho máximo de
 * 100 elementos, até digitar o número “0”. Imprimir quantos números iguais ao
 * último número foram lidos. O limite de números é 100.  Sem considerar o “0”
 * como último número.*/
int main() {
  const int LENGTH = 100;
  int vetor[LENGTH] = {0};

  int last_num;
  int last_num_count = 0;

  int num_in;
  int filled_len = LENGTH;
  for (int i = 0; i < LENGTH; ++i) {
    cout << "Digite o " << i + 1 << "° número: ";
    cin >> num_in;

    if (num_in == 0) {
      filled_len = i;
      break;
    }

    vetor[i] = num_in;
  }

  last_num = vetor[filled_len - 1];

  for (int i = 0; i < filled_len; ++i) {
    if (vetor[i] == last_num) {
      ++last_num_count;
    }
  }

  cout << last_num_count;

  return 0;
}