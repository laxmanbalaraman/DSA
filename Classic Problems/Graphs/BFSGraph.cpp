#include <bits/stdc++.h>
using namespace std;

void addEdge(vector <int> adj[], int n1, int n2){
    adj[n1].push_back(n2);
    adj[n2].push_back(n1);
}

void BFSGraph(vector <int> adj[], int V){
    // initialise all elements to zero (or) false
    vector <bool> visited(V);

    int source = 0;
    queue<int> q;
    q.push(source);

    // intially the node 0 is already visited 
    visited[source] = 1;

    while(!q.empty()){
        int currNode = q.front();
        cout << currNode << " ";
        q.pop();
        
        // discover more nodes neighbor of current node
        for(auto adjNode : adj[currNode]){
            if(!visited[adjNode]){
              q.push(adjNode); 
              visited[adjNode] = 1; 
            } 
        }
    }

}

int main(){

int v = 7;
vector <int> adj[v];
addEdge(adj, 0, 1);
addEdge(adj, 0, 2);
addEdge(adj, 1, 3);
addEdge(adj, 1, 4);
addEdge(adj, 2, 4);
addEdge(adj, 3, 4);
addEdge(adj, 3, 5);
addEdge(adj, 4, 5);



BFSGraph(adj, v);
}