#ifndef FILA_H_ 
#define FILA_H_

#include <string>

using std::string;

// Armazena um nó da lista encadeada na memória.
struct No {
  string chave;
  No* proximo;
};

// Representa uma fila de strings.
class Fila {
 public:
   // Cria uma fila vazia;
  Fila();

  // Retorna o primeiro elemento da fila.
  // Precondição: a fila *não* pode estar vazia.  
  string primeiro();

  // Retorna o último elemento da fila.
  // Precondição: a fila *não* pode estar vazia.  
  string ultimo();

  // Informa se a fila está vazia.
  bool vazia();

  // Insere um elemento no fim da fila.
  void Inserir(string k);

  // Remove o elemento no início da fila. 
  // Precondição: a fila *não* pode estar vazia.
  void Remover();

  // Retorna o número de elementos na fila.
  int tamanho();

  // Libera toda a memória alocada para a fila.
  ~Fila();
 private:
  No* primeiro_;
  No* ultimo_;
};

#endif