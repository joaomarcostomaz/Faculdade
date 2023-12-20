#include "Relacao.hpp"

Relacao::Relacao(long x){
	n = (x > 9)? x: 10;
	long id = 2;
	while (id*id < x) id++;
	p = id;
}

Relacao::~Relacao(){}	

bool Relacao::temRelacao(long x, long y){
	return (x>=0) && (y >=0) && ((x % p) == (y % p));
}
