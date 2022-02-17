// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	
	// dfs and store the reverse order of how nodes are visited
	void dfs(int node, vector<int> &visited, vector<int> adj[], vector<int> &order){
	    if(!visited[node]){
	        visited[node] = 1;
    	    for(int it : adj[node]){
    	        dfs(it, visited, adj, order);     
    	    }
    	    order.push_back(node);
	    }
	    return;
	}
	
	// do dfs on the revAjd
	void rdfs(int node, vector<int> &visited,vector<int> revAdj[]){
	    if(!visited[node]){
	        visited[node] = 1;
	        for(auto it : revAdj[node]){
	            rdfs(it, visited, revAdj);
	        }
	    }
	    return;
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> visited(V, 0);
        vector<int> order;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, visited, adj, order);
            }
        }

        
        vector<int> revAdj[V];
        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                revAdj[it].push_back(i);
            }
        }
        
        // erase the visited list to do reverse dfs
        for(auto &i : visited) i = 0; 
        
        // no of dfs calls = no of strongly connected components 
        int dfsCalls = 0;
        for(int i = V - 1; i >= 0; i--){
            if(!visited[order[i]]){
                dfsCalls++;
                rdfs(order[i], visited, revAdj);
            }
        }
        return dfsCalls;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends