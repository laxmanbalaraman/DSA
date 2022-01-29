    bool checkCycle(int node, vector<int> adj[], int vis[], int oneDfsVis[]){
        vis[node] = 1;
        // for each one depth search we check if there is a cycle
        oneDfsVis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(checkCycle(it, adj, vis, oneDfsVis)) return true;
            }
            else{
                if(oneDfsVis[it]) return true;
            }
        }
        oneDfsVis[node] = 0;
        return false;
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V], oneDfsVis[V];
        memset(vis, 0, sizeof(vis));
        memset(oneDfsVis, 0, sizeof(oneDfsVis));
        for(int i = 0; i < V; i++){
            // this visited are is to make sure that all inward nodes that are not part of cycle are visited and not left alone;
            // if all nodes are outward execpt the inward node of the cycle then i think this visited array is not needed.
            if(!vis[i]){
                if(checkCycle(i, adj, vis, oneDfsVis)) return true;
            }
        }
        return false;
    }