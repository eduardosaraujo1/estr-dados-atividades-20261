#include "../includes/exercicio_base.hpp"
#include <iostream>

using namespace std;

// 1- Desenvolva um programa que tenha dois métodos fahrenheit e celsius, onde
// você entra com um valor em fahrenheit e transforma em celsius e vice e versa.
// Fórmula Celsius: (fahrenheit – 32) _ 5/9;
// Fahrenheit = (Celsius _ 9/5) + 32;
class ExercicioA : public Exercicio {
public:
  double calcular_fahrenheit(double celsius) { return 32 + celsius * 9 / 5; }

  double calcular_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
  }

  int execute() override {
    short oop;
    int deg_in;

    cout << "Digite a operação que deseja executar:\n1- Celsius -> "
            "Fahrenheit\n2- Fahrenheit -> Celsius\n> ";
    cin >> oop;

    if (oop == 1) {
      cout << "Digite o valor em Celsius: ";
      cin >> deg_in;

      cout << "Resultado: " << calcular_fahrenheit(deg_in);
    } else if (oop == 2) {
      cout << "Digite o valor em Fahrenheit: ";
      cin >> deg_in;

      cout << "Resultado: " << calcular_celsius(deg_in);
    } else {
      cout << "Operação inválida.";
    }

    return 0;
  }
};
