class Solution {
  public:
    // Function to find the number of islands.
    void connect(int x, int y, queue<pair<int, int>> &q, vector<vector<char>>& grid, int visited[501][501], int n, int m){
         // connect a land to unvisited 8-neighnor co-land;
        if( x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == '1' and !visited[x][y]){
            q.push({x, y});
            visited[x][y] = 1;
        }
    }
    
    void bfs(vector<vector<char>> &grid, int i, int j, int n, int m, int visited[501][501]){
        queue<pair<int, int>>q;
        q.push({i, j});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            // check for land in 8 directions
            connect(x, y + 1, q, grid, visited, n, m);
            connect(x, y - 1, q, grid, visited, n, m);
            connect(x - 1, y, q, grid, visited, n, m);
            connect(x + 1, y, q, grid, visited, n, m);
            connect(x + 1, y + 1, q, grid, visited, n, m);
            connect(x - 1, y - 1, q, grid, visited, n, m);
            connect(x + 1, y - 1, q, grid, visited, n, m);
            connect(x - 1, y + 1, q, grid, visited, n, m);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        int visited[501][501];
        int islands = 0;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(grid[i][j] == '1' and !visited[i][j]){
                    // found an island
                    islands++;
                    visited[i][j] = 1;
                    bfs(grid, i, j, n, m, visited);
                }
            }
        }
        
        // for(int i = 0; i < n ; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        return islands;
    }
};