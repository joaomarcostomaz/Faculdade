#include "google_password.h"

#include <iostream>

using namespace std;

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
  // TODO: Implemente este metodo
  Usuario novo;
  novo.login = login;
  if(validPassword(password)){
    novo.password = password;
    passwords_.insert({url,novo});
  }
}

void GooglePassword::remove(const std::string& url) {
  // TODO: Implemente este metodo
  passwords_.erase(url);
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  // TODO: Implemente este metodo
  /**
   * Este metodo nao pode inserir novas credenciais, apenas atualizar as
   * ja existentes. Alem disso, o login e/ou senha do usuario so podem ser
   * atualizados se a senha armazenada no sistema for igual a old_password.
   * Nao esqueca de verificar se o novo password tambem e valido.
   */
  if(passwords_.find(url) != passwords_.end()){
    if(passwords_[url].password == old_password){
      if(validPassword(new_password)){
        passwords_[url].login = login;
        passwords_[url].password = new_password;
      }
    }
  }
}

void GooglePassword::printPasswords() {
  // TODO: Implemente este metodo
  /**
   * Exemplo de saida:
   * 3
   * aaa.site.com: login and password
   * www.site.com: login and password
   * zzz.site.com: login and password
   *
   */
  cout << passwords_.size() << endl;
  for(auto it = passwords_.begin(); it != passwords_.end(); it++){
    cout << it->first << ": " << it->second.login << " and " << it->second.password << endl;
  }
}

bool GooglePassword::validPassword(const std::string& password) const {
  // TODO: Implemente este metodo
  if((password.find("123456") != string::npos)|| (password.size() > 50) || (password.size() < 6) || (password.find(' ') != string::npos)){
    return 0;
  }else{
    return 1;
  }
}
