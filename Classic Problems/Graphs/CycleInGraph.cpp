    
    //BFS

    /*
    intution: if already visited node is trying to be visited, then there is a cycle.
    */

   // BFS sol 1: visit = 1 when popping;
    
    bool findCycleBFS(vector<int> adj[], int src, vector<bool> &visited ){
        queue<int> q;
        q.push(src);
        int parent = -1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(visited[node]) return true;
            visited[node] = 1;
            for(auto it : adj[node]){
                if(!visited[it]){
                    q.push(it);
                } 
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector <bool> visited(V, 0);
        for(int src = 0; src < V; src++){
        if(!visited[src]){
            if(findCycleBFS(adj, src, visited)) return true;
            }
        }
        return false;
    }


    // BFS sol 2: visit = 1 when checking unvisited;

        bool findCycleBFS(vector<int> adj[], int src, vector<bool> &visited ){
        queue<pair<int, int>> q;
        // node : parent
        visited[src] = 1;
        q.push({src, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(!visited[it]){
                    q.push({it, node});
                    visited[it] = 1; 
                }
                else{
                    if(it != parent) return true;
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector <bool> visited(V, 0);
        for(int src = 0; src < V; src++){
        if(!visited[src]){
            if(findCycleBFS(adj, src, visited)) return true;
            }
        }
        return false;
    }

    // DFS 

        bool findCycleDFS(vector<int> adj[], int node, int parent, vector<bool> &visited ){
        for(auto it : adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                if(findCycleDFS(adj, it,  node, visited)) return true;
            }
            else{
                if(it != parent) return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector <bool> visited(V, 0);
        for(int src = 0; src < V; src++){
        if(!visited[src]){
            visited[src] = 1;
            if(findCycleDFS(adj, src, -1, visited)) return true;
            }
        }
        return false;
    }