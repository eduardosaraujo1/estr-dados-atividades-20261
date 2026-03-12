#include "../includes/exercicio_base.hpp"
#include <iostream>

using namespace std;

// 5- Desenvolver um programa onde você entre via teclado com dois valores e
// após a digitação o usuário escolha um seletor de opção (menu) com as
// seguintes opções:
// - Multiplicação;
// - Adição;
// - Divisão;
// - Subtração;
// - Fim do processo;
// Obs. Criar um método para cada opção e dentro do case chamar as funções
// respectivamente.
class ExercicioE : public Exercicio {
public:
  // 5- Desenvolver um programa onde você entre via teclado com dois valores e
  // após a digitação o usuário escolha um seletor de opção (menu) com as
  // seguintes opções:
  // - Multiplicação;
  // - Adição;
  // - Divisão;
  // - Subtração;
  // - Fim do processo;
  // Obs. Criar um método para cada opção e dentro do case chamar as funções
  // respectivamente.

  int somar(int a, int b) { return a + b; }
  int multiplicar(int a, int b) { return a * b; }
  int subtrair(int a, int b) { return a - b; }
  int dividir(int a, int b) { return a / b; }

  int execute() override {
    int a_in, b_in;
    int result;
    short op;

    do {
      cout << "Digite o primeiro número: ";
      cin >> a_in;
      cout << "Digite o segundo número: ";
      cin >> b_in;

      cout << "[SELETOR DE OPÇÕES]\n";
      cout << "1- Multiplicação\n";
      cout << "2- Adição\n";
      cout << "3- Divisão\n";
      cout << "4- Subtração\n";
      cout << "5- Encerrar programa\n";
      cout << "Escolha: ";
      cin >> op;

      switch (op) {
      case 1:
        result = multiplicar(a_in, b_in);
        break;
      case 2:
        result = somar(a_in, b_in);
        break;
      case 3:
        result = dividir(a_in, b_in);
        break;
      case 4:
        result = subtrair(a_in, b_in);
        break;
      }

      cout << "Resultado: " << result;
    } while (op != 5);

    return 0;
  }
};
