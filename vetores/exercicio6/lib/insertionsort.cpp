void insertionsort(int *arr, int len) {
  // Comparar do segundo valor em diante e ir verificando qual número deve ser
  // trocado
  // 20, 50, 79, 46, 100, 76, 70, 11, 19, 10
  for (int i = 1; i < len; ++i) {
    int cur = arr[i];
    int j = i - 1;

    while (arr[j] > cur && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }

    arr[j + 1] = cur;
  }
}