class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool canMove(int x, int y, int mx, int my, int n){
        if(x + mx >= 0 && x + mx < n && y + my >= 0 && y + my < n)
            return true;
        return false;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // if the starting and destination are same
	    if(KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1])
	        return 0;
	    
	    int dp[N][N];
	    memset(dp, 0, sizeof(dp));
	    
	    // all possible moves
	    vector<pair<int, int>> moves = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, 
	                                    {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};

	   queue<pair<int, int>> q;
	   q.push({KnightPos[0] - 1, KnightPos[1] - 1});
	   
	   while(!q.empty()){
	       auto curr = q.front();
	       q.pop();
	       int x = curr.first;
	       int y = curr.second;
	       
	       for(int i = 0; i < 8; i++){
	           int mx = moves[i].first;
	           int my = moves[i].second;
	           if(canMove(x, y, mx, my, N)){
	               int nx = x + mx;
	               int ny = y + my;
	               // if cell is not visited
	               if(!dp[nx][ny]){
	                    // new cell min moves = prevcell min moves + 1
	                    dp[nx][ny] = dp[x][y] + 1;
	                    q.push({nx, ny});
	               }
	           }
	       }
	       
	   }
	    return dp[TargetPos[0] - 1][TargetPos[1] - 1];
	}
};