class Solution{
    public:
    
    bool canMove(int row, int col, vector<vector<int>> &visited, int n, vector<vector<int>> &m){
        if(row == n || row == -1 || col == -1 || col == n) return false;
        if(visited[row][col] || m[row][col]==0) return false;
        return true;
    }
    
     void helper(vector<vector<int>> &m, int row, int col, int n, 
     vector<vector<int>> &visited, string &path, vector<string> &paths){
      
    if(row == n - 1 and col == n - 1){
        //cout << "Yes";
        paths.push_back(path);
        return;
    }
    
    visited[row][col] = true;
    
    if(canMove(row - 1, col, visited, n, m)){

        path.push_back('U');
        helper(m, row - 1, col,  n, visited, path, paths);
        path.pop_back();
    }
    if(canMove(row + 1, col, visited, n, m)){
        path.push_back('D');
        helper(m, row + 1, col, n, visited, path, paths);
        path.pop_back();
    }
    if(canMove(row , col - 1, visited, n, m)){
        path.push_back('L');
        helper(m, row, col - 1,  n, visited, path, paths);
        path.pop_back();
    }
    if(canMove(row , col + 1, visited, n, m)){
        path.push_back('R');
        helper(m, row, col + 1,  n, visited, path, paths);
        path.pop_back();
    }
    
    visited[row][col] = false;
    //push_back("-1");
    //return;
        
     }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path;
        vector<string>paths;
        //visited[0][0] = true;
        if(m[0][0])
        helper(m, 0, 0, n, visited, path, paths);
        return paths;
        
    }