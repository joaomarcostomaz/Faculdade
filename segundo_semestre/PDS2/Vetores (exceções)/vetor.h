#ifndef VETOR_H_
#define VETOR_H_

#include <string>

using std::string;

// Define um vetor de std::string cujos índices variam em
// qualquer intervalo, inclusive negativos.
class Vetor {
  public:
    // Cria um vetor cujos índices variam de 'inicio' até 'fim'.
    // PRECONDIÇÃO: fim >= inicio.
    Vetor(int inicio, int fim);

    // Altera o valor do índice i.
    // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
    void atribuir(int i, std::string valor);

    // Retorna o valor do índice i.
    // PRECONDIÇÕES: 
    // (1) i está dentro do intervalo de índices do vetor.
    // (2) i foi inicializando anteriormente.
    string valor(int i) const; 

    // Desaloca a memória reservada para os elementos do vetor.
    ~Vetor();
  
  private:
    int inicio_; 
    int fim_; // Primeiro índice válido do vetor.
    string* elementos_;  // Elementos do vetor.
    bool* inicializados_;
};

struct IntervaloVazio{
  int inicio;
  int fim;
};

struct IndiceInvalido{
  int inicio;
  int fim;
  int indice;
};

struct IndiceNaoInicializado{
  int indice;
};

#endif