class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Creating a min heap pq syntax 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        vector<int> dist(V, INT_MAX);
        vector<bool> processed(V, false);
        vector<int> parent(V, -1);
        // start from the source vertex
        dist[S] = 0;
        pq.push({0, S});
        while(!pq.empty()){
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            processed[node] = true;
            
            for(auto it : adj[node]){
                if(!processed[it[0]]){
                    int target = it[0];
                    int weight = it[1];
                    if(dist[node] + weight < dist[target]){
                        dist[target] = dist[node] + weight;
                        pq.push({dist[target], target});
                        parent[target] = node;
                    }
                }
            }
        }
        // *** //  optional for find the shortest path route, say(0) from source (2)
        
        // int currnode = 0, source = 2;
        // while(currnode != source){
        //     cout << currnode << "<-";
        //     currnode = parent[currnode];
        // } cout << source << endl;
        
        // for(int i = 0; i < V; i++){
        //     cout << "Parent of " << i << " is " << parent[i] << endl; 
        // }
        
        
        return dist;
    }
};