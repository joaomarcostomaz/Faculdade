#ifndef JAPONESA_H
#define JAPONESA_H

#include "produto.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de um produto do tipo Comida Japonesa.
 *
 */
class Japonesa : public Produto {
 public:
  /**
   * @brief Construtor padrao que inicializa todas as variaveis da classe.
   *
   * @param combinado Item escolhido da comida japonesa. Ex: Combo 1 ou Barca 2
   * @param sushi Informa a quantidade de sushis no pedido
   * @param temaki Informa a quantidade de temakis no pedido
   * @param hots Informa a quantidade de hots no pedido
   * @param qtd Quantidade do item. Ex: 3x Combo 1
   * @param valor Valor unitario do item escolhido
   */
  Japonesa(const std::string& combinado,
           int sushis,
           int temakis,
           int hots,
           int qtd,
           float valor_unitario);

  /**
   * @brief Retorna a descricao detalhada da comida japonesa.
   * Ex: Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
   *
   * @return std::string Descricao da comida japonesa.
   */
  std::string descricao() const override;

 private:
  // TODO: Declare aqui as variaveis da classe. Note que as variaveis quantidade
  // (qtd) e valor ja sao herdadas de Produto
  std::string combinado_;
  int sushis_;
  int temakis_;
  int hots_;
};
#endif