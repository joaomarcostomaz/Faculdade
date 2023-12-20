#ifndef PIZZA_H
#define PIZZA_H

#include "produto.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de um produto do tipo Pizza.
 *
 */
class Pizza : public Produto {
 public:
  /**
   * @brief Construtor padrao que inicializa todas as variaveis da classe.
   *
   * @param sabor Sabor da pizza: Ex: 4 queijos
   * @param pedacos Quantidade de pedacos da pizza
   * @param borda_recheada Informa se a pizza tem borda recheada ou nao
   * @param qtd Quantidade de pizzas
   * @param valor_unitario Valor unitario de cada pizza
   */
  Pizza(const std::string& sabor,
        int pedacos,
        bool borda_recheada,
        int qtd,
        float valor_unitario);

  /**
   * @brief Retorna uma descricao detalhada da pizza.
   *
   * @return std::string Descricao da pizza.
   */
  std::string descricao() const override;

 private:
  // TODO: Declare aqui as variaveis da classe. Note que as variaveis quantidade
  // (qtd) e valor ja sao herdadas de Produto
  std::string sabor_;
  int pedacos_;
  bool borda_recheada_;
};

#endif