class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> inDegree(V, 0);
	    for(int i = 0; i < V; i++){
	        for(auto it : adj[i]){
	            // current node pointing to the it node
	            inDegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i = 0; i < V; i++){
	        if(inDegree[i] == 0){
	            q.push(i);
	        }
	    }
	    vector<int> topOrder;
	    while(!q.empty()){
	        int node = q.front();
	        topOrder.push_back(node);
	        q.pop();
	        for(auto it : adj[node]){
	            inDegree[it]--;
	            if(inDegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
        return topOrder;
	}
};