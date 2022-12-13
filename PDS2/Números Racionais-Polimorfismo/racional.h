#ifndef RACIONAL_H_
#define RACIONAL_H_

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

// Representa um número racional.
// Vide: https://pt.wikipedia.org/wiki/N%C3%BAmero_racional
class Racional {
 public:
  // Representa a uma exceção.
  // Não tem atributos, porque o denominador neste caso é sempre zero.       
  struct ExcecaoDivisaoPorZero {};

  // Cria o número 0/1.
  Racional();

  // Cria o número n/1.
  Racional(int n);  

  // Cria o número n/d.
  // PRÉ-CONDIÇÃO: d != 0
  // LANÇA: ExcecaoDivisaoPorZero. 
  Racional(int n, int d); 

  // Retorna o numerador.
  int numerador() const; 

  // Retorna o denominador.
  int denominador() const; 

  // Retorna o simétrico de *this.
  Racional operator-() const;  

  // Retorna a soma de *this e k.
  Racional operator+(Racional k) const;

  // Retorna a subtração de *this e k.
  Racional operator-(Racional k) const;

  // Retorna a multiplicação de *this e k.
  Racional operator*(Racional k) const;

  // Retorna a divisão de *this por k.
  // PRÉ-CONDIÇÃO: d != 0
  // LANÇA: ExcecaoDivisaoPorZero. 
  Racional operator/(Racional k) const;

  // Converte um número Racional em um float.
  operator float() const;

  // Converte um número Racional em uma string no formato
  // "numerador_/denominador_".
  operator string() const;

  // Sobrecarrega o operador de inserção de streams.
  friend ostream& operator<<(ostream& out, Racional r);
  
  // Sobrecarrega o operador de extração de streams.
  friend istream& operator>>(istream& in, Racional& r); 
 private:
  int numerador_; // Numerador do número racional.
  int denominador_; // Denominador do número racional.

  // Divide o numerador e denominador pelo MDC, e
  // garante que o denominador é sempre positivo.
  void Simplificar();
};

#endif