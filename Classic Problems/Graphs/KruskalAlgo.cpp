class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	struct node{
	    int u, v, wt;
	    node(int first, int second, int weight){
	        u = first;
	        v = second;
	        wt = weight;
	    }
	};
	
	// comparator
	static bool comp(node a, node b){
	    return a.wt < b.wt;
	}
    
    // Init parent array. Each element is the parent of it own.
    void makeSet(vector<int> &parent, int V){
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
    }
    
    int findPar(int u, vector<int> &parent){
        if( u == parent[u])  return u;
        
        return parent[u] = findPar(parent[u], parent);
    }
    
    void unions(int u, int v, vector<int> &parent, vector<int> &rank){
        // find the absolute parent of both set and create a link
        u = findPar(u, parent);
        v = findPar(v, parent);
        if(rank[u] < rank[v]) parent[u] = v;
        else if(rank[v] < rank[u]) parent[v] = u;
        // connect one set to another set that has higher tree height when not path compressed
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<node> edges;
        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                edges.push_back(node(i, it[0], it[1]));
            }
        }
        
        // kruskal: sort the edges and connect the edges that do not form cycle during the process
        sort(edges.begin(), edges.end(), comp);
        
        // disjoint set
        vector<int> parent(V);
        vector<int> rank(V, 0);
        makeSet(parent, V);

        int totalCost = 0;
        //cout << endl;
        for(auto it : edges){
            // check if two nodes belong to the same set
            if(findPar(it.u, parent) != findPar(it.v, parent)){
                unions(it.u, it.v, parent, rank);
                totalCost += it.wt;
            }
        }
        return totalCost;
    }
};