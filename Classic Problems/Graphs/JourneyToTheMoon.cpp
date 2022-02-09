// using disjoing set method
// find all unique set and their size 
// then sum the pairwise product of set sizes

typedef long long ll;

 void makeSet(vector<int> &parent, int n){
     for(int i = 0; i < n; i++) parent[i] = i;
 }

 int findParent(int node, vector<int> &parent){
     if(node == parent[node]) return node;
    return parent[node] = findParent(parent[node], parent);
 }
 
 void unions(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(u, parent);
    v = findParent(v, parent);
    if(rank[u] > rank[v]) parent[v] = u;
    else if(rank[v] > rank[u]) parent[u] = v;
    else{
        parent[v] = u;
        rank[u]++;
    }
 }
 
 
ll journeyToMoon(int n, vector<vector<int>> astronaut) {
vector<int> parent(n);
vector<int> rank(n, 0);
makeSet(parent, n);
for(auto pair : astronaut){
    int u = pair[0];
    int v = pair[1];
    if(findParent(u, parent) != findParent(v, parent)) unions(u, v, parent, rank);
}
for(ll i = 0; i < n; i++){
    // iterating once again so that each element is mapped to its correct parent
    findParent(i, parent);
}
unordered_map<int, vector<int>> map;
for(int i = 0; i < n; i++){
    map[parent[i]].push_back(i); 
}
vector<int> setSize;
int len = 0;
for(auto i : map){
    setSize.push_back(i.second.size());
    len++;
}


// find product of each element pairs (dont try n^2 way, gives tle)
// instead use suffixSum (becoz sum of product results common out of each element)

ll suffixSum[len];
ll sum = 0;
for(ll i = len - 1; i >= 0; i--){
    sum += setSize[i];
    suffixSum[i] = sum;
}
ll totalPairs = 0;
for(ll i = 0; i < len - 1; i++){
    totalPairs += setSize[i] * suffixSum[i + 1];
}
return totalPairs;
}
