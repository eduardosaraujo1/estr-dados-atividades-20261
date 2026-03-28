# História e origem do ShellSort

WIP

# Explicação do ShellSort

WIP

## Detalhes: Seleção da sequência de lacunas (gap-sequence)

OBJETIVO: explicar como cada uma dessas sequências funcionam.

Tipos que existem:

- Marcin Ciura (https://thimbleby.gitlab.io/algorithm-wiki-site/wiki/shell_sort)
- Shell's original sequence: N/2 , N/4 , …, 1
- Knuth's increments: 1, 4, 13, …, (3k – 1) / 2
- Sedgewick's increments: 1, 8, 23, 77, 281, 1073, 4193, 16577...4j+1+ 3·2j+ 1
- Hibbard's increments: 1, 3, 7, 15, 31, 63, 127, 255, 511…
- Papernov & Stasevich increment: 1, 3, 5, 9, 17, 33, 65,...
- Pratt: 1, 2, 3, 4, 6, 9, 8, 12, 18, 27, 16, 24, 36, 54, 81....

## Detalhes: Prova do teorema de não regressão do ShellSort

<details>
<summary>Clique aqui para expandir</summary>

Explicar a prova descrita em https://liususan091219.github.io/teaching/cs284_20s/slides/sort_2.pdf

</details>

# Complexidade de tempo e espaço

- Ressaltar que depende da sequência de lacunas

WIP

# Implementação em C++

```cpp
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
```

# Conclusão

WIP

# Referências

- https://liususan091219.github.io/teaching/cs284_20s/slides/sort_2.pdf
- https://www.youtube.com/watch?v=g06hNBhoS1k
- https://thimbleby.gitlab.io/algorithm-wiki-site/wiki/shell_sort
- https://www.udiprod.com/shell-sort/#analysis
- https://www.geeksforgeeks.org/dsa/shell-sort/
