
// disjoint set : used int kruskal algo

#include<iostream>
using namespace std;

int parent[100000];
int nodeRank[100000];

void makeSet(int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        nodeRank[i] = 0;
    }
}

int findPar(int node){
    if(node == parent[node]) return node;

    // while returning absolute parent node is stored in each child nodes leading to path compression
    return parent[node] = findPar(parent[node]);   
}

void unions(int u, int v){
    u = findPar(u);
    v = findPar(v);

    if(nodeRank[u] < nodeRank[v]){
        parent[u] = v;
    }else if(nodeRank[u] > nodeRank[v]){
        parent[v] = u;
    }else{
        parent[v] = u;
        nodeRank[u]++;
    }
}

int main(){
    makeSet(6);
    cout << (findPar(4) == findPar(1) ? "Yes" : "No");
    cout << findPar(4);
    unions(4, 5);
    unions(1, 2);
    unions(2, 3);
    unions(3, 4);
    cout << (findPar(4) == findPar(1) ? "Yes" : "No");
    cout << findPar(4);

    // if(findPar(u) != findPar(v)) ? "Disjoint Set" : "forms a cycle"

}