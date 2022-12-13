#ifndef GOOGLE_PASSWORD_H
#define GOOGLE_PASSWORD_H

#include <map>
#include <string>

using std::map;
using std::string;

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das
 *  credenciais salvas de um site.
 */
class GooglePassword {
 public:
  /**
   * @brief Adiciona uma nova credencial.
   * @param url Endereco do site.
   * @param login Login utilizado no cadastro.
   * @param password Password utilizado no cadastro.
   */
  void insert(const string& url,
              const string& login,
              const string& password);

  /**
   * @brief Remove as informacoes de um determinado site.
   * @param url Endereco do site.
   */
  void remove(const string& url);

  /**
   * @brief Atualiza as credenciais utilizadas em um site.
   * @param url Endereco do site.
   * @param login Novo login que deve ser atualizado.
   * @param old_password Password antigo.
   * @param new_password Novo password que deve ser atualizado.
   */
  void update(const string& url,
              const string& login,
              const string& old_password,
              const string& new_password);

  /**
   * @brief Imprime as informacoes salvas de todos os sites.
   */
  void printPasswords();

 private:
  /**
   * @brief Verifica se o password satisfaz as condições:
   *
   * Condicao 1: A senha nao pode ter a seguencia '123456'.
   * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
   * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
   * Condicao 4: A senha nao pode ter caracteres em branco ' '.
   *
   * Exemplos de senhas invalidas:
   * 123456
   * test_123456
   * 123456_test
   * test_123456_test
   * senha test
   */
  bool validPassword(const string& password) const;

 private:
  /**
   * @brief Struct que armazena e gerencia as informacoes do usuario.
   *
   */
   struct Usuario {
    string login;  // Login do usuario.
    string password;  // Password do usuario.  
  };

  /**
   * @brief Container que armazena as informacoes salvas dos sites. Ele
   * utiliza a url do site como chave e as informacoes sao do tipo Usuario.
   * Logo, um site nao pode estar associado a mais de um usuario e senha.
   */
  map<string, Usuario> passwords_;
};
#endif