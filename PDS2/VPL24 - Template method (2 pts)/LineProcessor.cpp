#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana/100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
    std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo
  bool valid = false;
  for(char v : str){
    int _valid = v - '\0';
    if(_valid >= 48 && _valid <= 57){
      valid = true;
    }else if(_valid != 32){
      return false;
    }

  }

  
  return valid;
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:

  std::string number;
  int count = 0;
  for(char v : str){
    int _valid = v - '\0';
    if(_valid == 32){
      if(number != ""){
        count += std::stoi(number);
      }
      number = "";
    }else{
        number += v;
    }
  }
  if(number != ""){
    count += std::stoi(number);
  }

  std::cout << count << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo
  std::regex regularExpr("\\s*\\w+\\s*\\d+\\s*\\w+\\s*\\d+\\s*");
  return std::regex_match(str, regularExpr);
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  std::stringstream ss(str);
  int number1,number2;
  std::string team1,team2;

  ss >> team1 >> number1 >> team2 >> number2;
  if(number1 > number2){
  std::cout << "Vencedor: " << team1 << std::endl;
  }else if(number1 == number2){
    std::cout << "Empate" << std::endl;
  }else{
    std::cout << "Vencedor: " << team2 << std::endl;
  }
}

void ContadorDePalavras::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  std::stringstream ss(str);
  int count = 0;
  std::string W_readed;

  while(ss >> W_readed){
    count++;
  }
  std::cout << count << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo
  std::stringstream ss(str);
  std::string W_readed;
  bool valid = true;

  while(ss>>W_readed){
    valid &= std::regex_match(W_readed, std::regex("\\b[a-zA-Z]+\\b"));
  }
  return valid;
}

void InversorDeFrases::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  std::vector<std::string> v;
  std::stringstream ss(str);
  std::string W_readed;

  while(ss>>W_readed){
    v.push_back(W_readed);
  }
  reverse(v.begin(),v.end());

  for(auto it = v.begin(); it != v.end(); it++){
    std:: cout << *it << ((it + 1) == v.end() ? "" : " ");
  }
  std::cout << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
  std::regex dateFormat("\\s*\\d\\d?/\\d\\d?/\\d{4}");
  // TODO: Implemente este metodo
  // Note que você pode usar uma expressao regular como:
  // "\\s*\\d\\d?/\\d\\d?/\\d{4}" para saber se a linha eh valida:
  return std::regex_match(str, dateFormat);
}

void EscritorDeDatas::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  // Lembre-se que as iniciais dos meses sao:
  // "Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out",
  // "Nov", e "Dez".

  std::string conversor[] = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out","Nov", "Dez"};
  int count = 0;
  for(count; str[count] != '/'; count++);
    std::string mes;
  for(++count; str[count]!= '/'; count++){
    mes += str[count];
  }



  std::cout << conversor[std::stoi(mes) - 1] << std::endl;
}