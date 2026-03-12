#include "../includes/exercicio_base.hpp"
#include <iostream>

using namespace std;

// 4- Escreva um método que receba o ano e retorne 1 se for bissexto e 0 se não
// for. Um ano é bissexto quando divisível por 4, mas não por 100. Um ano também
// é bissexto quando divisível por 400.
class ExercicioD : public Exercicio {
public:
  int is_bissexto(unsigned int ano) {
    if (ano % 400 == 0) {
      return 1;
    }

    if (ano % 4 == 0 && ano % 100 != 0) {
      return 1;
    }

    return 0;
  }

  int execute() override {
    unsigned int num_in;
    cout << "VERIFICADOR DE ANOS BISSEXTOS\n";
    cout << "Digite 0 para sair.\n";

    do {
      cout << "Digite um número: ";
      cin >> num_in;

      cout << (is_bissexto(num_in) == 1 ? "É bissexto.\n"
                                        : "Não é bissexto.\n");

    } while (num_in != 0);

    return 0;
  }
};
