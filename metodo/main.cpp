#include "exercicio/exercicioA.cpp"

using namespace std;

// 2- Calcule a soma dos quadrados de dois números fornecidos pelo usuário.
// Trabalhe com chamada de métodos usadas como argumento de outros métodos.
// Dica: você vai criar 3 métodos onde duas delas estarão dentro de uma.

// 3- Um número primo é qualquer inteiro divisível por si próprio e por 1.
// Escreva um método que receba um inteiro positivo e, se este número for primo
// retorne 1, caso contrário retorne 0.

// 4- Escreva um método que receba o ano e retorne 1 se for bissexto e 0 se não
// for. Um ano é bissexto quando divisível por 4, mas não por 100. Um ano também
// é bissexto quando divisível por 400.

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

// 6- Gere um método que trabalhe com fatorial, lembrando o fatorial é ele vezes
// a quantidade dele mesmo. Ex. fat 5 = 5*4*3*2*1.

int main() {
  Exercicio *exercicio = new ExercicioA();
  exercicio->execute();

  return 0;
}