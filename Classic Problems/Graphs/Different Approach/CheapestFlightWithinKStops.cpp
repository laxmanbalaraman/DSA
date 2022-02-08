class Solution {
public:
    
    struct node{
        int num, wt, stops;
        node(int number, int weight, int kstops){
            num = number;
            wt = weight;
            stops = kstops;
        }
    };
    
    struct compareWeight{
      bool operator()(node const& n1, node const& n2){
            return n1.wt > n2.wt;
        }  
    };
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        int edges = flights.size();
        for(int i = 0; i < edges; i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        
        vector<int> distance(n, INT_MAX);
        vector<bool> visited(n, 0);
        priority_queue<node, vector<node>, compareWeight> pq;
        pq.push(node(src, 0, -1));
        
        while(!pq.empty()){
            auto currNode = pq.top();
            int num = currNode.num;
            int wt = currNode.wt;
            int stops = currNode.stops;
            visited[num] = true;
            pq.pop();
            if(dst == num and stops <= k) return distance[num];
            stops++;
            for(auto it : adj[num]){
                int fcost = it.second;
                int target = it.first;
                if(wt + fcost < distance[target] and !visited[target] and stops <= k){
                    distance[target] = wt + fcost;
                    pq.push(node(target, distance[target], stops));
                }
            }
        }
        return -1;
        
    }
};