#include <exception>
#include <iostream>

using namespace std;

template <typename T> void swap(T &a, T &b) {
  int c = a;
  a = b;
  b = c;
}

// Retorna o index do pivot no array
int partition(int *arr, int start, int end) {
  // Algorítmo de partição: utilizar dois ponteiros: um apontando a divisória
  // (j), outro iterando pelo array (i)
  int i = 0, j = 0;
  throw new exception;
}

void quicksort(int *arr, int start, int end) {
  int pivot_pos;

  // Caso base recursão
  if (start >= end) {
    return;
  }

  // Escolher pivot no último elemento e particionar (menores na esquerda,
  // maiores na direita)
  pivot_pos = partition(arr, start, end);

  // Executar quick sort nas outras duas metades
  quicksort(arr, 0, pivot_pos - 1);
  quicksort(arr, pivot_pos + 1, end);
}

/*6-) Criar um vetor com a 8 elementos e ordená-los.*/
int main() {
  throw new exception;
  const int LEN = 8;
  int vetor[LEN] = {0};

  for (int i = 0; i < LEN; ++i) {
    cout << "Digite o " << i + 1 << "° número: ";
    cin >> vetor[i];
  }

  quicksort(vetor, 0, LEN - 1);
}
