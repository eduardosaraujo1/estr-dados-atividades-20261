#include "lib/mergesort.cpp"
#include <iostream>

using namespace std;

/*6-) Criar um vetor com a 8 elementos e ordená-los.*/
int main() {
  const int LEN = 8;
  int vetor[LEN] = {0};

  for (int i = 0; i < LEN; ++i) {
    cout << "Digite o " << i + 1 << "° número: ";
    cin >> vetor[i];
  }

  // quicksort(vetor, 0, LEN - 1);
  mergesort(vetor, 0, LEN - 1);
  // bubblesort(vetor, LEN);

  for (auto v : vetor) {
    cout << v << ' ';
  }
}
