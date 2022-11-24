#ifndef RACIONAL_H_
#define RACIONAL_H_

#include <iostream>

// Representa um número racional.
// Vide: https://pt.wikipedia.org/wiki/N%C3%BAmero_racional
class Racional {
 public:
  // Cria o número 0/1.
  Racional();

  // Cria o número n/1.
  Racional(int n);  

  // Cria o número n/d.
  // PRÉ-CONDIÇÃO: d != 0 
  Racional(int n, int d); 

  // Retorna o numerador.
  int numerador() const; 

  // Retorna o denominador.
  int denominador() const; 

  // Retorna o simétrico de *this.
  Racional simetrico() const;  

  // Retorna a soma de *this e k.
  Racional somar(Racional k) const;

  // Retorna a subtração de *this e k.
  Racional subtrair(Racional k) const;

  // Retorna a multiplicação de *this e k.
  Racional multiplicar(Racional k) const;

  // Retorna a divisão de *this por k.
  Racional dividir(Racional k) const;

  // Divide o numerador e denominador pelo MDC, e
  // garante que o denominador é sempre positivo.
  void Normalizar();

 private:
  int numerador_; // Numerador do número racional.
  int denominador_; // Denominador do número racional.

};

#endif