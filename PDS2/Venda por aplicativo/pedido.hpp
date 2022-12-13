#ifndef PEDIDO_H
#define PEDIDO_H

#include <list>

#include "hamburguer.hpp"
#include "japonesa.hpp"
#include "pizza.hpp"
#include "produto.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de um pedido.
 */
class Pedido {
 public:
  /**
   * @brief Destrutor da classe.
   *
   */
  ~Pedido();

  /**
   * @brief Adiciona um novo produto ao pedido.
   * @param p Ponteiro do tipo base Produto.
   * Pode ser da classe derivada: Pizza, Hamburguer ou Japonesa.
   */
  void adicionaProduto(Produto* p);

  /**
   * @brief Calcula o valor total do pedido.
   * @return float Valor total do pedido
   */
  float calculaTotal() const;

  /**
   * @brief Retorna um resumo detalhado do pedido, com a lista de todos os
   * produtos.
   * @return std::string Resumo do pedido
   */
  std::string resumo() const;

  /**
   * @brief Atualiza o endereco de entrega
   *
   * @param endereco Endereco de entrega
   */
  void setEndereco(const std::string& endereco);

 private:
  /**
   * @brief Lista de produtos do pedido. Pode ser do tipo Pizza, Hamburguer
   * ou Japonesa.
   */
  std::list<Produto*> m_produtos;

  /**
   * @brief Endereco de entrega do pedido
   *
   */
  std::string m_endereco;
};
#endif