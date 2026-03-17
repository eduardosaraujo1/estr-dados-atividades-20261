void swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}

// Retorna o index do pivot no array
int partition(int *arr, int start, int end) {
  // Algorítmo de partição: utilizar dois ponteiros: um apontando a divisória
  // (j), outro iterando pelo array (i)
  // [22, 65, 7, 93, 4, 76, 29, 73, 89, 49]
  int j = start - 1;
  int pivot = arr[end];

  for (int i = start; i <= end; ++i) {
    if (arr[i] <= pivot) {
      ++j;

      if (i != j) {
        swap(arr[j], arr[i]);
      }
    }
  }

  // j agora está apontando para o pivot
  return j;
}

void quicksort(int *arr, int start, int end) {
  int pivot_pos;

  // Caso base: array de tamanho 1 ou menor não precisa de sorting
  if (end - start <= 0) {
    return;
  }

  // Escolher pivot no último elemento e particionar (menores na esquerda,
  // maiores na direita)
  pivot_pos = partition(arr, start, end);

  // Executar quick sort nas outras duas metades
  quicksort(arr, 0, pivot_pos - 1);
  quicksort(arr, pivot_pos + 1, end);
}