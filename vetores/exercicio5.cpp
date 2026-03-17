#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

/*5-) Criar um programa que leia dados de um vetor de 12 elementos inteiros.
 * Imprima o maior e menor sem ordenar, o percentual de números pares e a média
 * dos elementos do vetor.*/
int main() {
  const int LENGTH = 12;
  int vetor[LENGTH] = {0};

  int max = INT_MIN;
  int min = INT_MAX;
  int odd = 0;
  int even = 0;
  int sum = 0;

  for (int i = 0; i < LENGTH; ++i) {
    cout << "Digite o " << i + 1 << "° número: ";
    cin >> vetor[i];
  }

  for (auto num_in : vetor) {
    sum += num_in;

    if (num_in > max) {
      max = num_in;
    }

    if (num_in < min) {
      min = num_in;
    }

    if (num_in % 2 == 0) {
      ++even;
    } else {
      ++odd;
    }
  }

  cout << "Maior: " << max << '\n';
  cout << "Menor: " << min << '\n';
  cout << "Porcentagem par: " << (double)even / LENGTH * 100 << '%' << '\n';
  cout << "Média: " << (double)sum / LENGTH << '\n';

  return 0;
}