#ifndef VENDA_H
#define VENDA_H

#include <list>

#include "pedido.hpp"

/**
 * @brief Esta classe e responsavel pelo gerenciamento dos pedidos.
 * Ela armazenda a lista de pedidos que foram recebidos e imprime um relatorio
 * de vendas.
 */
class Venda {
 public:
  /**
   * @brief Adiciona um novo pedido a lista de pedidos processados.
   * @param p Representa o novo pedido que foi recebido.
   */
  void adicionaPedido(Pedido* p);

  /**
   * @brief Imprime um relatorio de vendas detalhado com a lista de todos
   * os pedidos realizados, a quantidade de pedidos recebidos e o total de
   * venda.
   */
  void imprimeRelatorio() const;

  /**
   * @brief Destrutor da classe
   *
   */
  ~Venda();

 private:
  /**
   * @brief Lista de pedidos recebidos
   */
  std::list<Pedido*> m_pedidos;
};
#endif
