#include <iostream>

using namespace std;

/*4-) Ler um vetor V de 10 elementos e obter um vetor W cujos componentes são os
 * fatoriais dos respectivos componentes de V.*/
int factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; ++i) {
    result *= i;
  }

  return result;
}
int main() {
  const int LEN = 10;
  int V[LEN] = {0};
  int W[LEN] = {0};

  for (int i = 0; i < LEN; ++i) {
    cout << "Digite o " << i + 1 << "º número: ";

    cin >> V[i];

    W[i] = factorial(V[i]);
  }

  for (auto n : W) {
    cout << n << ' ';
  }

  return 0;
}