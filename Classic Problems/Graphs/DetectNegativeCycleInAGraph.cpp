class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    
	    // Bellman-Ford algo
	    
	    vector<int> dist(n, INT_MAX);
	    dist[0] = 0;
	    // iterate n -1 times;
	    for(int i = 0; i < n; i ++){
	        for(auto it : edges){
	            int u = it[0], v = it[1], wt = it[2];
	            if(dist[u] + wt < dist[v] and dist[u] != INT_MAX){
	                dist[v] = dist[u] + wt;
	            }
	        }
	    }
	    // if there is any change at nth time, then there is a -ve cycle
	    for(auto it : edges){
	            int u = it[0], v = it[1], wt = it[2];
	            // value changes again due to negative value
	            if(dist[u] + wt < dist[v]){
                    return 1;
	            }
        }
        return 0;
	}
};