#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>

/**
 * @brief Classe base responsavel pelo armazenamento e manipulacao das
 * informacoes basicas de um produto.
 */
class Produto {
 public:
  /**
   * @brief Retorna a quantidade de itens do produto
   *
   * @return int Quantidade de itens do produto
   */
  int getQtd() const;

  /**
   * @brief Retorna o valor unitario do produto
   *
   * @return float Valor unitario do produto
   */
  float getValor() const;

  /**
   * @brief Retorna a descricao detalhada do produto
   *
   * @return std::string Descricao do produto
   */
  virtual std::string descricao() const = 0;

  /**
   * @brief Destrutor da classe
   *
   */
  virtual ~Produto() = default;

 protected:
  /**
   * @brief Quantidade de itens do produto
   */
  int m_qtd{0};

  /**
   * @brief Valor unitatio do produto
   */
  float m_valor_unitario{0};
};
#endif