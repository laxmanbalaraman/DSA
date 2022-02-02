class Solution {
public:
    
    void dfs(int i, vector<int>adj[], vector<int> &visited){
        visited[i] = 1;
        for(auto it : adj[i]){
            if(!visited[it]){
                dfs(it, adj, visited);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& edges){
        int numOfEdges = edges.size();
        if(numOfEdges < n - 1) return -1;
        
        vector<int> adj[n];
        for(auto node : edges){
            adj[node[0]].push_back(node[1]);
            adj[node[1]].push_back(node[0]);
        }
        vector<int> visited(n, 0);
        int disconnected = 0;
        for(int i = 0; i <n; i++){
            if(!visited[i]){
                disconnected++;
                dfs(i, adj,visited);
            }
        }
        return disconnected - 1;
    }
};