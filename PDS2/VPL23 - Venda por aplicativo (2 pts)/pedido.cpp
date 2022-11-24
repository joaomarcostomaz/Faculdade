#include "pedido.hpp"


Pedido::~Pedido() {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */
}

void Pedido::setEndereco(const std::string& endereco) {
  // TODO: Implemente este metodo.
}

float Pedido::calculaTotal() const {
  // TODO: Implemente este metodo.
  return 0;
}

void Pedido::adicionaProduto(Produto* p) {
  // TODO: Implemente este metodo.
}

std::string Pedido::resumo() const {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */
  return "";
}