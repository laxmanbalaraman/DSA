class Solution {
public:
    bool canFlood(int x, int y, int m, int n){
        if(x >= 0 and x < m and y >= 0 and y < n) return true;
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int m = image.size();
        int n = image[0].size();
        int visited[m][n];
        memset(visited, 0, sizeof(visited));
        queue <pair<int, int>> q;
        q.push({sr, sc});
        int currColor =  image[sr][sc]; 
        while(!q.empty()){
            auto currPix = q.front();
            q.pop();
            int x = currPix.first;
            int y = currPix.second;
            //cout << x << " " << y <<  << endl;
            image[x][y] = newColor;
            if(canFlood(x, y + 1, m, n) and !visited[x][y + 1] and currColor == image[x][y + 1]){
                visited[x][y + 1] = 1;
                q.push({x, y + 1});
            }
            if(canFlood(x, y - 1, m, n) and !visited[x][y - 1] and currColor == image[x][y - 1]){
                visited[x][y - 1] = 1;
                q.push({x, y - 1});
            }
            if(canFlood(x + 1, y, m, n) and !visited[x + 1][y] and currColor == image[x + 1][y]){
                visited[x + 1][y] = 1;
                q.push({x + 1, y});
            }
            if(canFlood(x - 1, y, m, n) and !visited[x - 1][y] and currColor == image[x - 1][y]){
                visited[x - 1][y] = 1;
                q.push({x - 1, y});
            }
        }
        return image;
    }
};