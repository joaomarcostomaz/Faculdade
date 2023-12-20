#ifndef functions_HPP
#define functions_HPP


namespace functions{
    void Refaz(int esq, int dir, int *vetor){
        int i,x,j;
        i = esq; 
        j = i * 2;
        x = vetor[i];

        while(j <= dir){
            if(j < dir)
                if(vetor[j] < vetor[j+1]) j++;
            if(x >= vetor[j]) break;
            vetor[i] = vetor[j];
            i = j;
            j = i * 2;
        }
        vetor[i] = x;

    }
    void constroi_heap(int *vetor, int tam){
        int esq;
        
        esq = tam/2 + 1;
        while(esq > 1){
            esq--;
            Refaz(esq, tam, vetor);
        }
    }

    void heapsort(int *vetor, int tam){
        int esq, dir;
        int x;
        constroi_heap(vetor, tam); //Constroi o heap
        esq = 1; dir = tam;
        while(dir > 1){
            //Ordena o vetor
            x = vetor[1];
            vetor[1] = vetor[dir];
            vetor[dir] = x;
            dir--;
            Refaz(esq,dir,vetor);

        }
    }
    void shellsort(int *vetor,int tam){
        int h = 1;
        int i, j;

        while(h < tam){
            h *= 10;
        }
        while(h>0){
            for(i = h; i <= tam; i++){
                int aux = vetor[i];
                j = i;

                while(j >= h && aux < vetor[j - h]){
                    vetor[j] = vetor[j-h];
                    j -= h;
                    

                }
                
                vetor[j] = aux;

            }
            if (h == 1) break;
            h /= 5;
            if (h == 0) h = 1;      
        }
    }

}



#endif
