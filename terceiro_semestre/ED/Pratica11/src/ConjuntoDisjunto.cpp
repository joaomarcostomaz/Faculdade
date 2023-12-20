#include "ConjuntoDisjunto.hpp" 

	
ConjuntoDisjunto::ConjuntoDisjunto(int n){
    parent = new int[n];
    rank = new int[n];

    for(int i = 0;i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}
ConjuntoDisjunto::~ConjuntoDisjunto(){
    delete[] parent;
    delete[] rank;
}

void ConjuntoDisjunto::makeSet(long x){
    parent[x] = x;
    rank[x] = 0;
}
void ConjuntoDisjunto::unionSet(long x, long y){
    int rootX = findSet(x);
    int rootY = findSet(y);

    if(rootX == rootY)
        return; 
    
    if(rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else{
        parent[rootX] = rootY;
        if(rank[rootX] == rank[rootY])
            rank[rootY]++;
    }

}
long ConjuntoDisjunto::findSet(long x){
    if(parent[x] != x)
        parent[x] = findSet(parent[x]);
    
    return parent[x];
}

