void swap(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}

void bubblesort(int *arr, int len) {
  // Condição final da recursão
  if (len < 2) {
    return;
  }

  // Mover elemento da esquerda pra direita utilizando swap (bubble)
  for (int i = 0; i < len - 1; ++i) {
    if (arr[i] > arr[i + 1]) {
      swap(arr[i], arr[i + 1]);
    }
  }

  // Recursivamente executar bubble
  bubblesort(arr, len - 1);
}