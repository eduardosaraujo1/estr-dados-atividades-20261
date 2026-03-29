void insertionsort(int *arr, int len) {
  // Comparar do segundo valor em diante e ir verificando qual número deve ser
  // trocado
  // 20 50 79 46 100 76 70 11 19 10
  for (int i = 1; i < len; ++i) {
    int cur = arr[i];
    int j = i;

    while (arr[j - 1] > cur && j > 0) {
      arr[j] = arr[j-1];
      --j;
    }

    arr[j] = cur;
  }
}