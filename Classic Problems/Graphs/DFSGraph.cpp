
    void dfs(vector<int> adj[], int i, vector<int> &ansDFS, vector<int> &visited ){
        ansDFS.push_back(i);
        for(auto j : adj[i]){
            if(!visited[j]){
                visited[j] = 1;
                dfs(adj, j, ansDFS, visited);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector <int> visited(V, 0);
        vector<int> ansDFS;
        visited[0] = 1;
        dfs(adj, 0, ansDFS, visited);
        return ansDFS;
    }