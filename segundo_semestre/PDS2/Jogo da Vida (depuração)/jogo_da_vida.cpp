#include "jogo_da_vida.h"


JogoDaVida::JogoDaVida(int l, int c)
    :vivas_(l, std::vector<bool>(c,false)){
    }

bool JogoDaVida::viva(int i, int j){
    return vivas_[i][j];
}

void JogoDaVida::Matar(int i, int j){
    vivas_[i][j] = 0;
}

void JogoDaVida::Reviver(int i, int j){
    vivas_[i][j] = 1;
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y){
    int n = 0;
    for(int i : {x - 1, x, x + 1}){
        for(int j : {y - 1, y, y + 1}){
            if(i != x  || j != y){
                int linha_vizinha = (i + linhas()) % linhas();
                int coluna_vizinha = (j + colunas()) % colunas();
                if(viva(linha_vizinha, coluna_vizinha)){
                    n++;
                }
            }
        }
    }
    return n;
}


void JogoDaVida::ExecutarProximaIteracao(){
    JogoDaVida new_board(linhas(),colunas());

    for(int i = 0; i < linhas(); i++){
        for(int j = 0; j < colunas(); j++){
            int n = NumeroDeVizinhasVivas(i, j);
            if(n == 3  || n == 2 && viva(i,j)){
                new_board.Reviver(i,j);
            }
        }
    }
    *this = new_board;
} 