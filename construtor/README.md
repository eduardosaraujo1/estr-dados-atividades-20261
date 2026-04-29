Lista de Exercícios – Estrutura de Dados Prof. Fernanda
1-) Baseado no diagrama de classe abaixo faça a classe no C++.

```Conta + número: int + saldo: double + limite: double + nome: string ~conta (int, double, double, string) + saca (valor: double) bool + deposita (valor: double) + transfere ( destino: Conta, valor: double) bool

```

```cpp
#include <iostream> #include <string> using namespace std;   class Conta { public:     int numero;     double saldo;     double limite;     string nome;       Conta(int numero, double saldo, double limite, string nome) {         this->numero = numero;         this->saldo = saldo;         this->limite = limite;         this->nome = nome;     }       void deposita(double valor) {         this->saldo += valor;     }       bool saca(double valor) {         if (valor <= this->saldo + this->limite) {             this->saldo -= valor;             return true;         } else {             return false;         }     }       bool transfere(Conta& destino, double valor) {         if (this->saca(valor)) {             destino.deposita(valor);             return true;         } else {             return false;         }     }       void mostra() {         cout << "Conta: " << this->numero              << " | Nome: " << this->nome              << " | Saldo: " << this->saldo              << " | Limite: " << this->limite << endl;     } };   int main() {     Conta c1(1, 500, 200, "Marcos");     Conta c2(2, 300, 150, "Joao");       c1.mostra();     c2.mostra();       cout << "\nMarcos saca 600:\n";     if (c1.saca(600))         cout << "Saque realizado!\n";     else         cout << "Saldo insuficiente\n";       c1.mostra();       cout << "\nTransferindo 100 de Joao para Marcos:\n";     if (c2.transfere(c1, 100))         cout << "Transferencia realizada!\n";     else         cout << "Falha na transferencia!\n";       c1.mostra();     c2.mostra();       return 0; }
```

02- Escreva uma classe chamada classe “Comparavel” que tem como atributo um valor inteiro, um construtor para inicializar o atributo e os métodos éMaiorOuIgual, éMenorOuIgual e éDiferenteDe que recebem um valor do tipo int como parâmetro e retornam true se o valor encapsulado for, respectivamente, maior ou igual, menor ou igual ou diferente do passado como parâmetro.

03- Escreva uma classe “EntradaDeCinema” com a seguinte estrutura (dados): Int dia do filme float horário int sala float valor E com as seguintes ações (métodos): Construtor: com a finalidade de inicializar todos os atributos. CalculaDesconto: que deve receber como parâmetro a data de nascimento do cliente (do tipo Data) e caso seja menor de 12 anos, deve ser dado um desconto de 50% no valor normal. CalculaDesconto: que deve receber como parâmetro a data de nascimento do cliente (do tipo Data) e o número de sua carteira de estudante (do tipo int). Se o estudante tiver idade entre 12 e 15 anos, deve ser dado um desconto de 40%, de 16 a 20 um desconto de 30% e mais que 20 anos um desconto de 20% no valor normal. CalculaDescontoHorário: esse método deve dar um desconto de 10% sobre o valor aferido após todas as outras opções de desconto, caso o horário do filme seja antes das 16 horas. toString(): que deve imprimir todos os dados do ingresso.

4-) Crie uma classe Aluno contendo seu nome, número de matrícula e telefone.  
 a)Crie dois construtores, um iniciando valores “vazios” e outro iniciando valores dados pelo teclado.
b)Faça um método que imprima dados de dois alunos simultâneamente.

5-) Dado o exercício do calendário transforme-o em uma classe com seus 3 métodos e crie um objeto no “main “ e manipule a classe.
