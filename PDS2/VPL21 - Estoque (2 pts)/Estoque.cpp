#include <string>

#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  // TODO
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  // TODO
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  // TODO
  return 0;
}

void Estoque::imprime_estoque() const {
  // TODO
}

Estoque& Estoque::operator += (const Estoque& rhs) {
  // TODO
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  // TODO
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
  // TODO
  return false;
}

bool operator > (Estoque& lhs, Estoque& rhs) {
  // TODO
  return false;
}