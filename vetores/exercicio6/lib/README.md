# História e origem do ShellSort

O Shell Sort, desenvolvido por Donald Shell em 1959, surgiu como uma das primeiras tentativas de superar as limitações de desempenho dos algoritmos de ordenação por comparação simples, como o Insertion Sort.

Naquela época, a computação estava em seus primórdios e a eficiência no processamento de dados era um desafio crítico, já que algoritmos comuns levavam um tempo proibitivo para organizar grandes volumes de informações devido ao excesso de trocas entre elementos adjacentes.

A sacada genial de Donald Shell foi perceber que o Insertion Sort é extremamente eficiente quando o array já está "quase ordenado", mas muito lento quando elementos menores estão posicionados no final da lista, exigindo inúmeras movimentações para chegar ao início.

A origem do Shell Sort é marcante na ciência da computação por ser o primeiro algoritmo a quebrar a barreira da complexidade quadrática O(n^2) para algoritmos de ordenação in-place, embora sua performance exata dependa inteiramente da sequência de gaps escolhida (mais sobre isso a seguir).

# Explicação do ShellSort

O Shell Sort é um algoritmo de ordenação que funciona como uma versão otimizada do Insertion Sort. Em vez de comparar apenas elementos vizinhos, ele começa comparando elementos distantes entre si usando um intervalo chamado gap. Esse intervalo vai diminuindo gradualmente, fazendo com que a lista fique parcialmente ordenada antes da etapa final, o que torna o processo mais rápido.

Sua principal função é ordenar listas de forma simples e sem uso de memória extra, sendo mais rápido que o Insertion Sort em muitos casos práticos. Ele é indicado para listas de tamanho médio e situações onde se busca um equilíbrio entre facilidade de implementação e desempenho, sem recorrer a algoritmos mais complexos como Quick Sort ou Merge Sort.

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

- Correspondem a todos os números da forma \(2^p \cdot 3^q\) em ordem crescente.
- Desvantagem: o número de passes nessa sequência é muito grande, por isso na prática tende a ser mais lento que as outras gap-choices.

**Upper e lower‑bound:**

- Complexidade pior‑caso é \(\Theta(N \log^2 N)\).
- Assim como Hillbard's Increments, possui pouca variação (por isso o uiso da notação \(\Theta\) no lugar de O).

### 6. Incrementos de Sedgewick (Sedgewick’s increments)

**Sequências:**

- Versão 1 (1982):
  $1, 8, 23, 77, 281, 1073, 4193, 16577, \dots, 4^{j+1} + 3\cdot 2^j + 1$.
- Versão 2 (1986):
  $$
  \begin{cases}
  9\big(2^k - 2^{\frac{k}{2}}\big) + 1 & k \text{ par} \\
  8 \cdot 2^k - 6 \cdot 2^{(k+1)/2} + 1 & k \text{ ímpar}
  \end{cases} \\
  $$

**Upper‑bound:**

- Pior‑caso é \(O(N^{4/3})\) para essas sequência.
- É uma das melhores sequências "teóricas" conhecidas em termos de expoente.

### 7. Marcin Ciura

**Sequência:**

- \(h = 701, 301, 132, 57, 23, 10, 4, 1\)
- Não existe uma fórmula simples/algorítmica fechada; é uma sequência tabelada.

**Upper‑bound:** Não aplicável

### 8. Skean, Ehrenborg, Jaromczyk

**Fórmula:**
$\left\lfloor 4.0816 \cdot 8.5714^{\frac{k}{2.2449}} \right\rfloor$

- Não é matematicamente comprovado como Sedgewick's Increments
- O estudo para essa fórmula baseou-se na tentativa e erro

**Upper-bound:** Desconhecido

## Detalhes: Prova do teorema de não regressão do ShellSort

**Proposição**
Após um vetor ser h-ordenado e depois k-ordenado $(k < h)$, o vetor permanece h-ordenado.

**Prova**
Podemos provar a proposição por contradição.

Suponha que a proposição seja falsa, isso significa que após a k-ordenação, pelo menos um par de elementos com passo h está invertido, isto é, o valor na posição $i$ é maior que o valor na posição $i + h$. Suponha que $(i, i + h)$ seja a primeira vez que isso acontece.

Nota e notação: A mudança ocorre devido à operação de inserção mais recente em uma das sequências, $x \cdot i$ ou $x \cdot {i+h}$, mas não em ambas. Quando isso acontece em uma sequência $\cdots, x_l, \cdots$, usamos $x_l|$ e $|x'_l$ para denotar os valores respectivamente antes e depois nas posições afetadas $l$. Para qualquer posição $k$ cujo valor permanece inalterado, usamos $x_k$ para denotar seu valor.

No suposto cenário proposto, antes da k-ordenação, o vetor estava h-ordenado, e agora os valores em $(i, i + h)$ estão invertidos. Isso significa que uma das duas coisas a seguir deve ter acontecido durante a k-ordenação:

1. A posição mais recente está na sequência de $x \cdot i$, e $x_i$ acabou de aumentar $(|x_i > x_i|)$.
2. A posição mais recente está na sequência de $x \cdot {i+h}$, e $x \cdot {i+h}$ acabou de diminuir $(|x_{i+h} < x_{i+h}|)$.

_Nota do tradutor: | não é o operador módulo, mas é a notação descrita três parágrafos acima. Repito: $|x_i$ significa "o valor no index $i$ DEPOIS da etapa de insertion sort ocorrer"; $x_i|$ significa "o valor no index $i$ ANTES da etapa de insertion sort ocorrer"._

(1) Suponha que seja o primeiro caso. Observe que, no processo de ordenação por inserção com passo k, qualquer elemento pode se mover no máximo $1 \cdot k$ posições. Na maior parte do tempo, o valor em uma posição tende a diminuir; o único caso de aumento ocorre quando $x_i$ é a posição mais recente, e ele é substituído pelo valor anterior. Por exemplo, $x_i| = A$ e $|x_i = M$:

| Inserindo A em E, M:                    |
| --------------------------------------- |
| **E** E R **M** O X _**A**_ S P **L** T |
| **A** E R **E** O X **M** S P **L** T   |

Assim, $|x_i = x_{i-k}|$, por exemplo, $|x_6 = x_3| = M$. Como $(i, i + h)$ é a primeira vez que a inversão acontece, temos $x_{i-k}| < x_{i-k+h}$; ao mesmo tempo, $x_{i+h}$ e $x_{i-k+h}$ estão na mesma sequência k, então quando a k-ordenação alcançar a posição $i + h$ mais tarde, $x_{i+h}$ será substituído pelo maior valor dessa sequência, que satisfaz $\geq x_{i-k+h} > x_{i-k}| = |x_i$, logo eventualmente a inversão não ocorrerá, isto é, o caso (1) é eliminado.

(2) Suponha que seja o segundo caso. Devido ao insertion sort, quando o valor de $x_{i+h}$ diminui, isso deve ocorrer por causa da inserção do último elemento visitado $x_{j+h}|$ em sua sequência, por exemplo, $x_6| = A$ é inserido no início, o que faz com que os valores de $x_0 = E$ e $x_3 = M$ diminuam, portanto $j > i$, e $x_{j+h}| \leq |x_{i+h} < x_i$.

| Inserindo A em E, M:                    |
| --------------------------------------- |
| **E** E R **M** O X _**A**_ S P **L** T |
| **A** E R **E** O X **M** S P **L** T   |

Enquanto isso, como o valor na posição $j + h$ (no exemplo, $x_6$) aumentou, isso não causaria uma inversão na posição $(j, j + h)$ (a menos que $x_j$ tivesse aumentado ainda mais, caso em que a violação de $x_j > |x_{j+h} > x_{j+h}|$ significaria que a inversão do caso (1) já teria ocorrido anteriormente na posição $j$, o que contradiz a suposição de que $(i, i + h)$ é a primeira vez em que a violação acontece).

Como resultado, $x_j < x_{j+h}| \leq |x_{i+h} < x_i$, mas como $j > i$ e $j$ já foi visitado, $x_i$ e $x_j$ já deveriam ter sido ordenados, o que leva a uma contradição, isto é, o caso (2) é eliminado.

Fonte: https://liususan091219.github.io/teaching/cs284_20s/slides/sort_2.pdf

# Implementação em C++

```cpp
#include <iostream>

using namespace std;

int generate_sedgewick(int *gaps, int max_n) {
  int k = 0;
  int count = 0;

  while (1) {
    int gap;
    int p;

    if (k % 2 == 0) {
      // k par
      p = k / 2;
      // bit shifting no lugar de exponenciação por 2 funciona!
      gap = 9 * ((1 << k) - (1 << p)) + 1;
    } else {
      // k ímpar
      p = (k + 1) / 2;
      // bit shifting no lugar de exponenciação por 2 funciona!
      gap = 8 * (1 << k) - 6 * (1 << p) + 1;
    }

    if (gap >= max_n) break;

    gaps[count++] = gap;
    k++;
  }

  return count;
}

void shell_sort_gap(int *vet, int len, int gap) {
  // otimizacao: no lugar de um subarray por vez, organizo os primeiros
  // elementos, de cada subarray, depois os segundos elementos de cada, depois os terceiros, ...
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
  int gaps[1000];
  int count = generate_sedgewick(gaps, len);

  for (int i = count - 1; i >= 0; i--) {
    shell_sort_gap(vet, len, gaps[i]);
  }
}

int main() {
  const int LEN = 8;
  int vetor[LEN] = {0};

  for (int i = 0; i < LEN; ++i) {
    cout << "Digite o " << i + 1 << "° número: ";
    cin >> vetor[i];
  }

  shellsort(vetor, LEN);

  for (auto v : vetor) {
    cout << v << ' ';
  }
}
```

# Conclusão

O algorítmo do ShellSort é uma generalização do Insertion Sort, fato que o faz muito mais complexo e abre espaço para tantas variações de gap-sequences.

As propriedades discutidas do ShellSort demonstram que ele pode ter uma melhora de performance em relação ao Insertion Sort, e apesar complexidade de tempo ainda é inferior à de algorítmos como Heap Sort, Merge Sort e Quick Sort, sua relativa facilidade de implementação e eficiência em listas de tamanho moderado o mantém utilizado.

# Referências

- https://liususan091219.github.io/teaching/cs284_20s/slides/sort_2.pdf
- https://www.youtube.com/watch?v=g06hNBhoS1k
- https://thimbleby.gitlab.io/algorithm-wiki-site/wiki/shell_sort
- https://www.udiprod.com/shell-sort/#analysis
- https://www.geeksforgeeks.org/dsa/shell-sort/
- https://sedgewick.io/wp-content/themes/sedgewick/papers/1996Shellsort.pdf
- https://www3.decom.ufop.br/toffolo/site_media/uploads/2013-1/bcc202/slides/16._shellsort.pdf
- https://ir.cwi.nl/pub/24243/24243B.pdf
- https://arxiv.org/pdf/2301.00316
