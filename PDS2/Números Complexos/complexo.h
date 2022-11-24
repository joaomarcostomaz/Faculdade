#ifndef COMPLEXO_H_
#define COMPLEXO_H_
 
// Representa um número complexo
// (https://pt.wikipedia.org/wiki/N%C3%BAmero_complexo)
class Complexo {
 public:
  // Cria o número complexo 0 + 0i.
  Complexo();

  // Cria o número complexo a + bi.
  Complexo(double a, double b);

  // Retorna a parte real do número complexo.
  double real();

  // Retorna a parte imaginária do número complexo.
  double imag();

  // Testa se o número complexo é igual a 'x'.
  bool igual(Complexo x);

  // Atribui 'x' ao número complexo.
  // Ou seja, faz "*this = x"
  void Atribuir(Complexo x);

  // Retorna o módulo do número complexo.
  double modulo();

  // Retorna o conjugado do número complexo.
  Complexo conjugado();

  // Retorna o simétrico do número complexo.
  Complexo simetrico();

  // Retorna o inverso multiplicativo do número complexo.
  Complexo inverso();

  // Soma o número complexo com 'y' e retorna o resultado.
  Complexo somar(Complexo y);

  // Subtrai o número complexo por 'y' e retorna o resultado.
  Complexo subtrair(Complexo y);

  // Multiplica o número complexo com 'y' e retorna o resultado.
  Complexo multiplicar(Complexo y);

  // Divide o número complexo por 'y' e retorna o resultado.
  Complexo dividir(Complexo y);

 private:
  // A implmentação atual utiliza representação polar/trigonométrica
  double modulo_;  // Módulo do vetor que representa o número.
  double argumento_;  // Argumento do vetor (em radianos) que representa o número.
};

#endif  // COMPLEXO_H_
