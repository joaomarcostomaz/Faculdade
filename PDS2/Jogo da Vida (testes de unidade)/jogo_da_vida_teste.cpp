#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "jogo_da_vida.h"

TEST_CASE("JogoDaVida::JogoDaVida(int l, int c)") {
  JogoDaVida t(3, 3);
  for (int i : {0, 1, 2}) {
    for (int j : {0, 1, 2}) {
      CHECK_FALSE(t.viva(i,j));
    }
  }
}

TEST_CASE("JogoDaVida::Reviver(int i, int j)") {
  JogoDaVida t(3, 3);
  // Revive as células da diagonal inferior.
  for (int i : {0, 1, 2}) {
    for (int j : {0, 1, 2}) {
      if (i < j) {
        t.Reviver(i, j);
      }
    }
  }
  // Checa se as células da diagonal inferior estão vivas,
  // e se as outras estão mortas.
  for (int i : {0, 1, 2}) {
    for (int j : {0, 1, 2}) {
      if(i < j){
      CHECK(t.viva(i,j));
      }else{
        CHECK_FALSE(t.viva(i,j));
      }
    }
  }
}

TEST_CASE("JogoDaVida::Matar(int i, int j)") {
  JogoDaVida t(3, 3);
  // Revive todas as células.
  for (int i : {0, 1, 2}) {
    for (int j : {0, 1, 2}) {
      t.Reviver(i, j);
      REQUIRE(t.viva(i, j));
    }
  }
  // Mata as células da diagonal inferior.
  for (int i : {0, 1, 2}) {
    for (int j : {0, 1, 2}) {
      if (i < j) {
        t.Matar(i, j);
      }
    }
  }
  // Checa se as células da diagonal inferior estão mortas,
  // e se as outras estão vivas.
  for (int i : {0, 1, 2}) {
    for (int j : {0, 1, 2}) {
      if(i < j){
      CHECK_FALSE(t.viva(i,j));
      }else{
        CHECK(t.viva(i,j));
      }
    }
  }
} 

TEST_CASE("JogoDaVida::ExecutarProximaIteracao()") {
  // Cria o seguinte estado.
  // |           |
  // |     *     |
  // |       *   |
  // |   * * *   |
  // |           |
  JogoDaVida t(5, 5);
  t.Reviver(1, 2);
  t.Reviver(2, 3);
  t.Reviver(3, 1);
  t.Reviver(3, 2);
  t.Reviver(3, 3);

  // Cria o seguinte estado (que é a iteração seguinte a 't').
  // |           | 
  // |           |
  // |   *   *   |
  // |     * *   |
  // |     *     |
  JogoDaVida p(5, 5);
  p.Reviver(2, 1);
  p.Reviver(2, 3);
  p.Reviver(3, 2);
  p.Reviver(3, 3);
  p.Reviver(4, 2);

  // Checa se t == f depois de "t.ProximaIteracao()".
  t.ExecutarProximaIteracao();
  for (int i : {0, 1, 2, 3, 4}) {
    for (int j : {0, 1, 2, 3, 4}) {
      CHECK(t.viva(i,j) == p.viva(i,j));
    }
  }
}

TEST_CASE("Testa o lancamento de ExcecaoCelulaInvalida") {
  int l = 3;
  int c = 3;
  JogoDaVida t(l, c);
  for (int i = -1; i <= l; i++) {
    for (int j = -1; j <= c; j++) {
      if (i < 0 || j < 0 || i == l || j == c) {  
        // Se a célula NÃO é valida, deve lançar uma exceção.
        CHECK_THROWS_AS(t.Reviver(i, j),ExcecaoCelulaInvalida); 
        CHECK_THROWS_AS(t.Matar(i, j), ExcecaoCelulaInvalida);
        CHECK_THROWS_AS(t.viva(i, j), ExcecaoCelulaInvalida);
      } else {
         // Se a célula é valida, NÃO deve lançar uma exceção.
        CHECK_NOTHROW(t.Reviver(i, j)); 
        CHECK_NOTHROW(t.Matar(i, j));
        CHECK_NOTHROW(t.viva(i, j));    
      }
    }
  }
}