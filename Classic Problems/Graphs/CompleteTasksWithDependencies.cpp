class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	 
	    // basically if a graph has cycle then the task cannot be completed due 
	    // to deadlock.
	    // if topological sort is not possible then the graph is cyclic
	 
	    vector<int> adj[N];
	    vector<int> inDegree(N, 0);
	    int n = prerequisites.size();
	    
   	    // create adjacency and inDegree list
	   	    
	    for(int i = 0; i < n; i++){
	     inDegree[prerequisites[i].second]++;  
	     
	     adj[prerequisites[i].first].push_back(prerequisites[i].second);
	    }
	    
	    queue<int> q;
	    int c = 0;
	    
	    for(int i = 0; i < N; i++){
	        if(!inDegree[i]){
	            c++;
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        for(auto it : adj[node]){
	            inDegree[it]--;
	            if(!inDegree[it]){
	                c++;
	                q.push(it);
	            }
	        }
	    }
        // return 0 if not all nodes were able to be completed
	    return (c == N ? 1 : 0);
	}
};
