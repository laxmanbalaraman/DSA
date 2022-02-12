class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    
	    int V = matrix.size();
	    //  iterate via each third party node route
	    for(int k = 0; k < V; k++){
	        // distance between each pair of vertices
	        for(int i = 0; i < V; i++){
	            for(int j = 0; j < V; j++){
	                // if distance via third party node is not infinite
	                if(matrix[i][k] != -1 and matrix[k][j] != -1){
	                        // if distance via our route is infite but route via third party route
	                        // if non finite, then update
	                        if(matrix[i][j] == -1) matrix[i][j] = matrix[i][k] + matrix[k][j];
	                        // if distance via third party route is lesser that our direct route
	                        else matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	                        
	                    }
	            }
	        }
	    }
	}
};