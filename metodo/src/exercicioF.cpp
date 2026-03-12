#include "../includes/exercicio_base.hpp"
#include <iostream>

using namespace std;

// 6- Gere um método que trabalhe com fatorial, lembrando o fatorial é ele vezes
// a quantidade dele mesmo. Ex. fat 5 = 5*4*3*2*1.
class ExercicioF : public Exercicio {
public:
  // 6- Gere um método que trabalhe com fatorial, lembrando o fatorial é ele
  // vezes a quantidade dele mesmo. Ex. fat 5 = 5*4*3*2*1.
  unsigned int factorial(unsigned int n) {
    unsigned int m = 1;

    for (unsigned int i = 2; i <= n; ++i) {
      m *= i;
    }

    return m;
  }

  int execute() override {
    unsigned int num_in;
    cout << "CALCULADORA DE FATORIAL\n";
    cout << "Digite 0 para sair.\n";

    do {
      cout << "Digite um número: ";
      cin >> num_in;

      cout << "Resultado: " << factorial(num_in) << '\n';
    } while (num_in != 0);

    return 0;
  }
};
