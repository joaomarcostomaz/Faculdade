#include <string>
#include <iostream>
#include "Estoque.hpp"

/**
 * \brief Arquivo de testes.
 *
 * Atencao: este arquivo nao deve ser alterado! Sua alteracao (a fim de passar
 * pelos testes sem que o trabalhos seja efetivamente feito) levarah a anulacao
 * do trabalho entregue.
 */

void test0() {
  Estoque e0;
  e0.add_mercadoria("trigo", 30);
  e0.add_mercadoria("arroz", 45);
  if (e0.get_qtd("trigo") != 30) {
    std::cout << "Erro: quantidade invalida de trigo\n";
  } else if (e0.get_qtd("arroz") != 45) {
    std::cout << "Erro: quantidade invalida de arroz\n";
  } else {
    std::cout << "Teste 0 passou.\n";
  }
}

void test1() {
  Estoque e0;
  e0.add_mercadoria("trigo", 30);
  e0.add_mercadoria("trigo", 30);
  if (e0.get_qtd("trigo") != 60) {
    std::cout << "Erro: quantidade invalida de trigo\n";
  } else {
    std::cout << "Teste 1 passou.\n";
  }
}

void test2() {
  Estoque e0;
  e0.add_mercadoria("trigo", 30);
  e0.sub_mercadoria("trigo", 29);
  e0.add_mercadoria("trigo", 9);
  if (e0.get_qtd("trigo") != 10) {
    std::cout << "Erro: quantidade invalida de trigo\n";
  } else {
    std::cout << "Teste 2 passou.\n";
  }
}

void test_gt0() {
  Estoque e0;
  e0.add_mercadoria("trigo", 30);
  e0.add_mercadoria("arroz", 45);
  e0.add_mercadoria("leite", 15);
  Estoque e1;
  e1.add_mercadoria("trigo", 20);
  e1.add_mercadoria("leite", 5);
  std::cout << (e0 > e1) << std::endl;
}

void test_gt1() {
  Estoque e0;
  e0.add_mercadoria("trigo", 30);
  e0.add_mercadoria("arroz", 45);
  Estoque e1;
  e1.add_mercadoria("trigo", 20);
  e1.add_mercadoria("leite", 5);
  std::cout << (e0 > e1) << std::endl;
}

void test_gt2() {
  Estoque e0;
  e0.add_mercadoria("trigo", 30);
  e0.add_mercadoria("arroz", 45);
  e0.add_mercadoria("leite", 15);
  Estoque e1;
  e1.add_mercadoria("trigo", 20);
  e1.add_mercadoria("leite", 15);
  std::cout << (e0 > e1) << std::endl;
}

void test_lt0() {
  Estoque e0;
  e0.add_mercadoria("trigo", 30);
  e0.add_mercadoria("arroz", 45);
  e0.add_mercadoria("leite", 15);
  Estoque e1;
  e1.add_mercadoria("trigo", 20);
  e1.add_mercadoria("leite", 5);
  std::cout << (e1 < e0) << std::endl;
}

void test_lt1() {
  Estoque e0;
  e0.add_mercadoria("trigo", 30);
  e0.add_mercadoria("arroz", 45);
  Estoque e1;
  e1.add_mercadoria("trigo", 20);
  e1.add_mercadoria("leite", 5);
  std::cout << (e1 < e0) << std::endl;
}

void test_lt2() {
  Estoque e0;
  e0.add_mercadoria("trigo", 30);
  e0.add_mercadoria("arroz", 45);
  e0.add_mercadoria("leite", 15);
  Estoque e1;
  e1.add_mercadoria("trigo", 20);
  e1.add_mercadoria("leite", 15);
  std::cout << (e1 < e0) << std::endl;
}

void test_add() {
  Estoque e0;
  e0.add_mercadoria("trigo", 30);
  e0.add_mercadoria("arroz", 45);
  e0.add_mercadoria("leite", 15);
  Estoque e1;
  e1.add_mercadoria("trigo", 20);
  e1.add_mercadoria("carne", 15);
  e1.add_mercadoria("suco", 45);
  e0 += e1;
  e0.imprime_estoque();
}

void test_sub0() {
  Estoque e0;
  e0.add_mercadoria("trigo", 30);
  e0.add_mercadoria("arroz", 45);
  e0.add_mercadoria("leite", 15);
  Estoque e1;
  e1.add_mercadoria("trigo", 20);
  e1.add_mercadoria("leite", 10);
  e0 -= e1;
  e0.imprime_estoque();
}

void test_add_sub() {
  Estoque e0;
  e0.add_mercadoria("trigo", 30);
  e0.add_mercadoria("arroz", 45);
  e0.add_mercadoria("leite", 15);
  e0.add_mercadoria("trigo", 20);
  e0.add_mercadoria("prego", 100);
  e0.sub_mercadoria("trigo", 25);
  e0.imprime_estoque();
}

void test_read_add() {
  Estoque e0;
  std::string mercadoria;
  unsigned int qtd;
  while (std::cin >> mercadoria) {
    std::cin >> qtd;
    e0.add_mercadoria(mercadoria, qtd);
  }
  e0.imprime_estoque();
}

void test_read_add2() {
  Estoque e0;
  std::string mercadoria;
  unsigned int qtd;
  while (std::cin >> mercadoria) {
    Estoque e1;
    std::cin >> qtd;
    e1.add_mercadoria(mercadoria, qtd);
    e0 += e1;
  }
  e0.imprime_estoque();
}

void test_read_gt() {
  Estoque e0;
  Estoque e1;
  std::string mercadoria;
  unsigned int qtd;
  while (std::cin >> mercadoria) {
    std::cin >> qtd;
    e0.add_mercadoria(mercadoria, qtd);
    std::cin >> mercadoria;
    std::cin >> qtd;
    e1.add_mercadoria(mercadoria, qtd);
  }
  std::cout << (e0 > e1) << std::endl;
}

int main() {
  int option = 0;
  std::cin >> option;
  switch (option) {
    case 0:
      test_add();
      break;
    case 1:
      test_add_sub();
      break;
    case 2:
      test_sub0();
      break;
    case 3:
      test_lt0();
      break;
    case 4:
      test_lt1();
      break;
    case 5:
      test_lt2();
      break;
    case 6:
      test_gt0();
      break;
    case 7:
      test_gt1();
      break;
    case 8:
      test_gt2();
      break;
    case 9:
      test_read_add();
      break;
    case 10:
      test_read_add2();
      break;
    case 11:
      test_read_gt();
      break;
    case 12:
      test0();
      break;
    case 13:
      test1();
      break;
    case 14:
      test2();
      break;
    default:
      std::cerr << "Teste invalido: " << option << std::endl;
  }
}