    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> dist(V, 1e8);
        // distance from source to source is 0;
        dist[S] = 0;
        
        // why V - 1 times?:
        // we get shortest path from source to all nodes at a time when all the node are relaxed.
        // since there are n - 1 nodes(excluding source for which we already know the distance),
        // it takes a maximum of n - 1 times for all nodes to get relaxed which happens when 
        // graph is linear or cyclic (worst case).
        // the graph must become stable within n - 1 iteration, else it means that we have a -ve cycle and
        // the array never becomes stable.
        // it makes sense because a negative cycle cannot have shortest path because each node will
        // get updated to a lesser value infinitly so we cannot predict a shortest path.
        // using this stability of weight array intuituion, we will be able to detect if a graph
        // has cycle or not using bellman ford algo
        // it is single source shortest path because, first the relaxation happens for 
        // adjacent nodes of source node and then for subsequent iteration for rest of the nodes
        // hence each node will carry the potentially shortest path from source.
        
        for(int i = 0; i < V - 1; i++){
            for(auto it : adj){
                int u = it[0], v = it[1], weight = it[2];
                if(dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
                }
            }
        }
        return dist;
                
    }