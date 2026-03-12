#include "../includes/exercicio_base.hpp"
#include <iostream>

using namespace std;

// 2- Calcule a soma dos quadrados de dois números fornecidos pelo usuário.
// Trabalhe com chamada de métodos usadas como argumento de outros métodos.
// Dica: você vai criar 3 métodos onde duas delas estarão dentro de uma.
class ExercicioB : public Exercicio {
public:
  int somar(int a, int b) { return a + b; }

  int quadrado(int n) { return n * n; }

  int soma_quadrados(int a, int b) { return somar(quadrado(a), quadrado(b)); }

  int execute() override {
    int a, b;

    cout << "CALCULAR SOMA DO QUADRADO DE 2 NÚMEROS\n";
    cout << "Digite o primeiro número: ";
    cin >> a;
    cout << "Digite o segundo número: ";
    cin >> b;

    cout << "Resultado: " << soma_quadrados(a, b);

    return 0;
  }
};
