#include "../includes/exercicio_base.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

// 3- Um número primo é qualquer inteiro divisível por si próprio e por 1.
// Escreva um método que receba um inteiro positivo e, se este número for primo
// retorne 1, caso contrário retorne 0.
class ExercicioC : public Exercicio {
public:
  /*
  ALGORÍTIMO: Determinar primo através do teorema da raíz quadrada

  Explicação do algoritmo (melhorada)

  Um número primo é um inteiro maior que 1 que possui exatamente dois divisores:
  1 e ele mesmo.

  Para verificar se um número n é primo, poderíamos testar todos os divisores de
  2 até n-1. Porém isso é desnecessário.

  Se n possui um divisor d, então existe outro divisor n/d. Um dos dois deve ser
  menor ou igual à raiz quadrada de n, pois são inversamente proporcionais.
  Observe:

  1. 20/1 = 20 <-> 20/20 = 1
  2. 20/2 = 10 <-> 20/10 = 2
  3. 20/4 = 5 <-> 20/5 = 4
  *4. 20/5 = 4 <-> 20/4 = 5
  5. 20/10 = 2 <-> 20/2 = 10
  6. 20/20 = 1 <-> 20/1 = 20

  Observe que do item 4 em diante, os divisores foram espelhados um do outro,
  pois n/d = r <-> n/r = d. Não era necessário verificar mais que 3 vezes.

  Portanto, basta verificar divisores até √n. Isso reduz o número de testes de
  O(n) para O(√n).
  */
  int is_primo(unsigned int n) {
    if (n < 2) {
      return 0;
    }

    // Otimização: se eu sei que o número é par, não é primo
    // Além disso, posso pular divisões por números pares no iterador, já que
    // idealmente devo utilizar apenas divisores primos (mas isso é dificil de
    // alcançar)
    //
    // Observe: Se um número não é divisivel por 3 por exemplo, pra que
    // verificar se é divisivel por 6 ou 9: eu já sei que não, pois 6 = 3*2 logo
    // todo número divivel por 6 (denotado 6n) pode ser reescrito como 3*2n e
    // será divisivel por 3. O mesmo vale para o 2
    if (n % 2 == 0) {
      return 0;
    }

    for (unsigned int i = 3; n / i >= i; i += 2) {
      if (n % i == 0)
        return 0;
    }

    return 1;
  }

  int execute() override {
    unsigned int num_in;
    cout << "VERIFICADOR DE NÚMEROS PRIMOS\n";
    cout << "Digite 0 para sair.\n";

    do {
      cout << "Digite um número: ";
      cin >> num_in;

      cout << (is_primo(num_in) == 1 ? "É primo.\n" : "Não é primo.\n");

    } while (num_in != 0);

    return 0;
  }
};
