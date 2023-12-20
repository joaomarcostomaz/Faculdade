#include "pedido.hpp"
#include <string>

using namespace std;


Pedido::~Pedido() {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */
  while(!m_produtos.empty()){
    delete m_produtos.front();
    m_produtos.pop_front();

  }
}

void Pedido::setEndereco(const std::string& endereco) {
  // TODO: Implemente este metodo.
  m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  // TODO: Implemente este metodo.
  float soma;
  for (auto it = m_produtos.begin(); it != m_produtos.end(); it++){
    soma += (*it)->getValor() * (*it)->getQtd();
  }
  return soma;
}

void Pedido::adicionaProduto(Produto* p) {
  // TODO: Implemente este metodo.
  m_produtos.push_back(p);
}

std::string Pedido::resumo() const {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */
  string texto;
  for (auto it = m_produtos.begin(); it != m_produtos.end(); it++){
    texto += (*it)->descricao() + "\n";
  }
  texto += "Endereco: " + m_endereco;
  return texto;
}