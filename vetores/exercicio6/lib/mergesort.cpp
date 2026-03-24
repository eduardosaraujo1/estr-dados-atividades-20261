void merge(int *arr, int start, int mid, int end) {
  int len1 = mid - start + 1;
  int len2 = end - mid;

  int tmpArr1[len1];
  int tmpArr2[len2];

  // Preencher arrays
  for (int i = 0; i < len1; ++i) {
    tmpArr1[i] = arr[start + i];
  }
  for (int j = 0; j < len2; ++j) {
    tmpArr2[j] = arr[mid + j + 1];
  }

  // Popular array principal com lógica
  int i = 0;
  int j = 0;
  int k = start;
  while (i < len1 && j < len2) {
    if (tmpArr1[i] < tmpArr2[j]) {
      arr[k] = tmpArr1[i];
      ++i;
    } else {
      arr[k] = tmpArr2[j];
      ++j;
    }
    ++k;
  }

  // Popular array caso tenha sobrado no Arr1
  while (i < len1) {
    arr[k] = tmpArr1[i];
    ++i;
    ++k;
  }

  // Popular array caso tenha sobrado no Arr1
  while (j < len2) {
    arr[k] = tmpArr2[j];
    ++j;
    ++k;
  }
}

// 20 50 79 46 100 76 70 11 19 10
void mergesort(int *arr, int start, int end) {
  // Caso base recursão: array deve ter 2 elementos ou mais
  // `end-start` vai retornar 0 se for 1 elemento, 1 se for 2 elementos e assim
  // vai. Por isso a condição usa o 1 e não o 2
  if (end - start < 1) {
    return;
  }

  // Organizar recursivamente as duas metades
  int halfpoint = start + (end - start) / 2;
  mergesort(arr, start, halfpoint);
  mergesort(arr, halfpoint + 1, end);

  // Mesclar as duas metades já ordenadas
  merge(arr, start, halfpoint, end);
}