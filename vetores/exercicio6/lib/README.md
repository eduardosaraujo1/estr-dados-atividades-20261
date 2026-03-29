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
- Desvantagem: o número de passes nessa sequência é muito grande, por isso na prática tende a ser mais lento que as outras gap-choices.

**Upper e lower‑bound:**

- Complexidade pior‑caso é \(\Theta(N \log^2 N)\).
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

**Proposição**
Após um vetor ser h-ordenado e depois k-ordenado $(k < h)$, o vetor permanece h-ordenado.

**Prova**
Podemos provar a proposição por contradição.

Suponha que a proposição seja falsa, isso significa que após a k-ordenação, pelo menos um par de elementos com passo h está invertido, isto é, o valor na posição $i$ é maior que o valor na posição $i + h$. Suponha que $(i, i + h)$ seja a primeira vez que isso acontece.

Nota e notação: A mudança ocorre devido à operação de inserção mais recente em uma das sequências, $x*i$ ou $x*{i+h}$, mas não em ambas. Quando isso acontece em uma sequência $\cdots, x_l, \cdots$, usamos $x_l|$ e $|x'_l$ para denotar os valores respectivamente antes e depois nas posições afetadas $l$. Para qualquer posição $k$ cujo valor permanece inalterado, usamos $x_k$ para denotar seu valor.

No suposto cenário proposto, antes da k-ordenação, o vetor estava h-ordenado, e agora os valores em $(i, i + h)$ estão invertidos. Isso significa que uma das duas coisas a seguir deve ter acontecido durante a k-ordenação:

1. A posição mais recente está na sequência de $x*i$, e $x_i$ acabou de aumentar $(|x_i > x_i|)$.
2. A posição mais recente está na sequência de $x*{i+h}$, e $x*{i+h}$ acabou de diminuir $(|x_{i+h} < x_{i+h}|)$.

_Nota do tradutor: | não é o operador módulo, mas é a notação descrita três parágrafos acima. Repito: $|x_i$ significa "o valor no index $i$ DEPOIS da etapa de insertion sort ocorrer"; $x_i|$ significa "o valor no index $i$ ANTES da etapa de insertion sort ocorrer"._

(1) Suponha que seja o primeiro caso. Observe que, no processo de ordenação por inserção com passo k, qualquer elemento pode se mover no máximo $1*k$ posições. Na maior parte do tempo, o valor em uma posição tende a diminuir; o único caso de aumento ocorre quando $x_i$ é a posição mais recente, e ele é substituído pelo valor anterior. Por exemplo, $x_i| = A$ e $|x_i = M$:

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

int generate_pratt(int *gaps, int max_n) {
  // Seqüência de números que podem ser representados na forma 2^p * 3^q.
  gaps[0] = 1;

  int i2 = 0, i3 = 0;
  int size = 1;

  while (true) {
    int next2 = gaps[i2] * 2;
    int next3 = gaps[i3] * 3;

    int next = (next2 < next3) ? next2 : next3;

    if (next >= max_n) break;

    gaps[size++] = next;

    if (next == next2) i2++;
    if (next == next3) i3++;
  }

  return size;
}

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
  int gaps[1000];
  int count = generate_pratt(gaps, len);

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

  // mergesort(vetor, 0, LEN - 1);
  // quicksort(vetor, 0, LEN - 1);
  // insertionsort(vetor, LEN);
  // bubblesort(vetor, LEN);
  shellsort(vetor, LEN);

  for (auto v : vetor) {
    cout << v << ' ';
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
