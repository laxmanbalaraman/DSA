class Solution{
public:
    int maximumPath(int N, vector<vector<int>> m)
    {
        int cost = INT_MIN;
        for(int row = 1; row < N; row++){
            for(int col = 0; col < N; col++){
                if(col == 0) m[row][col] += max(m[row - 1][col], m[row - 1][col + 1]);
                else if (col == N - 1) m[row][col] += max(m[row - 1][col], m[row - 1][col - 1]);
                else{
                m[row][col] += max({m[row - 1][col], m[row - 1][col - 1], m[row - 1][col + 1]});
                }
            }
        }
        for(int col = 0; col < N; col++){
            cost = max(cost, m[N-1][col]);
        }
        return cost;
    }
};