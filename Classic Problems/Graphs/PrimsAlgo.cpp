class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<bool> MST(V, 0);
        vector<int> weight(V, INT_MAX);
        vector<int> parent(V, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        weight[0] = 0;
        pq.push({0, 0});
        int total_weight = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            MST[node] = true;
            pq.pop();
            for(auto it: adj[node]){
                if(!MST[it[0]] and weight[it[0]] > it[1]){
                    weight[it[0]] = it[1];
                    pq.push({weight[it[0]], it[0]});
                    parent[it[0]] = node;
                }
            }
        }
        
        for(auto w : weight){
            total_weight += w;
        }
        
        for(auto p : parent){
            cout << p << " ";
        } cout << endl;
        
        return total_weight;
    }
};
