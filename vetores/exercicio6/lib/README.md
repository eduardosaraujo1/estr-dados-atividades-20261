# História e origem do ShellSort

WIP

# Explicação do ShellSort

WIP

## Detalhes: Seleção da sequência de lacunas (gap-sequence)

### 1. Sequência original de Shell

**Fórmula:** \(1, \frac{N}{2}, \frac{N}{4}, \dots y = \frac{N}{2^x}\) para \(y \geq 1\).

**Upper‑bound conhecido:**

- No pior caso, \(O(N^2)\).

### 2. Knuth (Knuth’s increments)

**Fórmula:** \(1, 4, 13, 40, \dots (3^k - 1)/2\) para \(k \ge 0\).

**Upper‑bound:**

- Complexidade pior‑caso é \(O(N^{3/2})\).
- É melhor que a sequência original de Shell experimentalmente.

### 3. Hibbard’s increments

**Fórmula:** \(1, 3, 7, 15, 31, 63, \dots, 2^k - 1\) para \(k \geq 1\).

**Upper‑bound:**

- Pior caso: \(O(N^{3/2})\).
- Também tem limite inferior \(\Omega(N^{3/2})\), então possui menos variação.

### 4. Papernov & Stasevich

**Fórmula:** \(1, 3, 5, 9, 17, 33, 65, \dots, 2^k + 1\) para .

**Upper e lower‑bound:**

- Complexidade pior‑caso é \(O(N^{3/2})\).
- Compleixdade melhor-caso é \(\Omega(N \log N)\) se aplica para esta família de incrementos.

### 5. Sequência de Pratt

**Sequência:** \(1, 2, 3, 4, 6, 9, 8, 12, 18, 27, 16, 24, 36, 54, 81, \dots\)

- Correspondem a todos os números da forma \(2^p\times3^q\) em ordem crescente.
- Desvantagem: a geração dessa sequência para grandes arrays é demorada computacionalmente

**Upper e lower‑bound:**

- Complexidade pior‑caso é \(\Theta(N (\log N)^2)\).
- Assim como Hillbard's Increments, possui pouca variação (por isso o uiso da notação \(\Theta\) no lugar de O).

### 6. Sedgewick (Sedgewick’s increments)

**Sequência:**

- \(1, 8, 23, 77, 281, 1073, 4193, 16577, \dots, 4^{j+1} + 3\cdot 2^j + 1\).
- Termo geral: \(h_j = 4^{j+1} + 3\cdot 2^j + 1\) para \(j \ge 0\).

**Upper‑bound:**

- Pior‑caso é \(O(N^{4/3})\) para essa sequência.
- É uma das melhores sequências "teóricas" conhecidas em termos de expoente.

### 7. Marcin Ciura

**Sequência:**

- \(h = 701, 301, 132, 57, 23, 10, 4, 1\) (para arrays moderados).
- Não existe uma fórmula simples/algorítmica fechada; é uma sequência tabelada.

**Upper‑bound:** Não aplicável

## Detalhes: Prova do teorema de não regressão do ShellSort

<details>
<summary>Clique aqui para expandir</summary>

Explicar a prova descrita em https://liususan091219.github.io/teaching/cs284_20s/slides/sort_2.pdf

</details>

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
- https://sedgewick.io/wp-content/themes/sedgewick/papers/1996Shellsort.pdf
- https://www3.decom.ufop.br/toffolo/site_media/uploads/2013-1/bcc202/slides/16._shellsort.pdf
- https://ir.cwi.nl/pub/24243/24243B.pdf
