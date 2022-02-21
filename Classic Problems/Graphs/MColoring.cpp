bool canColor(int node, bool graph[101][101], vector<int> color, int V, int vcolor){
    for(int i = 0; i < V; i++){
        // if node color is not aleady taked by adjacent nodes.
        if(vcolor == color[i] and graph[node][i]){
            return false;
        }
    }
    return true;
}

bool mColor(int node, vector<int> &color, int m, int V, bool graph[101][101]){
    
    if(node == V) return true;
    
    // color node with each node and check possibility.
    for(int i = 1; i <= m; i++){
        if(canColor(node, graph, color, V, i)){
            color[node] = i;
            if(mColor(node + 1, color, m, V, graph)) return true;
            // backtrack and remove if not satisfied
            color[node] = 0;
        }
    }

    // if no color can be painted 
    return false;
    
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    
    vector<int> color(V, 0);
    bool posibility = mColor(0, color, m, V, graph);
    if(posibility){
        for(auto c : color) cout << c << " ";
        cout << endl;
    }
    return posibility;
}
