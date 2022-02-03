class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code 
        
        priority_queue<pair<int, int>> pq;
        vector<int> dist(V, INT_MAX);
        // start from the source vertex
        dist[S] = 0;
        pq.push({0, S});
        
        while(!pq.empty()){
            // vertex
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            for(auto it : adj[node]){
                int target = it[0];
                int weight = it[1];
                if(dist[node] + weight < dist[target]){
                    dist[target] = dist[node] + weight;
                    pq.push({-1*dist[target], target});
                }
            }
        }
        return dist;
    }
};