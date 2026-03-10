#include "exercicioBase.cpp"
#include <iostream>

// 1- Desenvolva um programa que tenha dois métodos fahrenheit e celsius, onde
// você entra com um valor em fahrenheit e transforma em celsius e vice e versa.
// Fórmula Celsius: (fahrenheit – 32) _ 5/9;
// Fahrenheit = (Celsius _ 9/5) + 32;
class ExercicioA : public Exercicio {
public:
  int execute() {
    std::cout << "Hello, world!";
    return 0;
  }
};
