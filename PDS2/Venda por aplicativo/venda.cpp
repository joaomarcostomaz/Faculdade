#include "venda.hpp"
#include <string>
#include <iomanip>

using namespace std;

Venda::~Venda() {
  // TODO: Implemente este metodo
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */
  while(!m_pedidos.empty()){
    delete m_pedidos.front();
    m_pedidos.pop_front();

}
}

void Venda::adicionaPedido(Pedido* p) {
  // TODO: Implemente este metodo
  m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
  // TODO: Implemente este metodo
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */
  int contador = 1;
  float total = 0.0;
  auto it = m_pedidos.begin();
  for (it; it != m_pedidos.end(); it++){
    total += (*it)->calculaTotal();
    cout << "Pedido " << contador << endl << (*it)->resumo()<< endl;
    contador++;
  }
  cout << setprecision(2) << fixed;
  cout << "Relatorio de Vendas" << endl << "Total de vendas: R$ " << total << endl << "Total de pedidos: " << m_pedidos.size();
}