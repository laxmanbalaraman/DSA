#include<bits/stdc++.h>
using namespace std;


void addAdj(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector <int> adj[], int V){
    for(int i = 0; i < V; i++){
        for(auto vertex : adj[i]){
            cout << "->" << vertex;
        }
        cout << "\n";
    }
}


int main(){

    int v = 5;
    // array of vectors
    vector <int> adj[v];
    addAdj(adj, 0, 1);
    addAdj(adj, 0, 4);
    addAdj(adj, 1, 2);
    addAdj(adj, 1, 3);
    addAdj(adj, 1, 4);
    addAdj(adj, 2, 3);
    addAdj(adj, 3, 4);
    printGraph(adj, v);
}
