void shell_sort_gap(int *vet, int len, int gap) {
  // otimizacao: no lugar de um subarray por vez, organizo os primeiros
  // elementos, de cada subarray, depois os outros dois, depois os outros tres,
  // evitando assim o uso de dois loops.
  for (int i = gap; i < len; i++) {
    int cur = vet[i];
    int j = i;

    while (j >= gap && vet[j - gap] > cur) {
      vet[j] = vet[j - gap];
      j -= gap;
    }

    vet[j] = cur;
  }
}

void shellsort(int *vet, int len) {
  // Sequência escolhida: Shell's original sequence
  for (int gap = len / 2; gap > 0; gap /= 2) {
    shell_sort_gap(vet, len, gap);
  }
}
