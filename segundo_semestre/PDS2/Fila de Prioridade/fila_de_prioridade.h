#include <list>
#include <string>
#include <vector>

using std::list;
using std::string;
using std::vector;

// Dados associados a uma pessoa.
struct Pessoa {
  string nome;  
  int prioridade;  
};

class FilaDePrioridade {
 public:
  // Adiciona uma pessoa a fila.
  void Adicionar(Pessoa p);

  // Remove a pessoa com a maior prioridade, e retorna o nome.
  // PRECONDIÇÃO: A fila não está fazia();
  string RemoverMaiorPrioridade();

  // Remove uma pessoa pelo nome.
  // Caso não haja alguém com esse nome, a fila não se altera.
  void Remover(string nome);

  // Retorna o número de pessoas na fila.
  int tamanho();

  // Retorna o nome das pessoas na fila, em ordem decrescente de prioridade.
  vector<string> listar();
 private:
  // Lista de pessoas.
  // Está ordenada em ordem *decrescente* de prioridade.  
  // Em caso de empate, a ordem de inserção é respeitada.
  list<Pessoa> lista_;
};