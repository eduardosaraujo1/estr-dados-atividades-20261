#include "src/exercicioA.cpp"
#include "src/exercicioB.cpp"
#include "src/exercicioC.cpp"
#include "src/exercicioD.cpp"
#include "src/exercicioE.cpp"
#include "src/exercicioF.cpp"
#include <memory>

using namespace std;

int main() {
  const short EXERCICIO = 6;

  unique_ptr<Exercicio> exercicio;

  switch (EXERCICIO) {
  case 1:
    exercicio = make_unique<ExercicioA>();
    break;
  case 2:
    exercicio = make_unique<ExercicioB>();
    break;
  case 3:
    exercicio = make_unique<ExercicioC>();
    break;
  case 4:
    exercicio = make_unique<ExercicioD>();
    break;
  case 5:
    exercicio = make_unique<ExercicioE>();
    break;
  case 6:
    exercicio = make_unique<ExercicioF>();
    break;
  }

  return exercicio->execute();
}