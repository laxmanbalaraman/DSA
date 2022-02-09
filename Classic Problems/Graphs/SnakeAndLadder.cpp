// solved using bfs with priority queue where the top element is the least move.

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int lastCell = n * n;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // steps,  cellNumber; 
        pq.push({0, 1});
        // same cell is not visited again;
        bool visited[n][n];
        memset(visited, false, sizeof(visited));
        visited[n-1][0] = true;
        while(!pq.empty()){
            auto [steps, cell] = pq.top();
            if(cell == lastCell) return steps;
            pq.pop();
            for(int i = cell + 1; i <= cell + 6 && i <= lastCell; i++){
                auto [row, column] = findBoardCoordinates(i, n);
                if(visited[row][column]) continue;
                if(board[row][column] == -1) pq.push({steps + 1, i});
                else pq.push({steps + 1, board[row][column]});
                visited[row][column] = true;
            }
        }
        return -1;
    }
    
    pair<int, int> findBoardCoordinates(int cellNum, int n){
    int row = n - (cellNum - 1) / n - 1;
    int col = (cellNum - 1) % n;
    if(row % 2 != ((n - 1) % 2)) col =  n - col - 1;
    return {row, col};
    }
};