
// Applying Euler Tour
// store  the time we enter the node and exit the node in dfs travers.
// can be used to check if the one node is in same subtree of another node if we use the intime and outtime
// if one node B to be in subtree of node A, then intime[A] < intime[B] && outtime[A] > outTime[B];


void dfs(vector<int> adj[], int &time, int src, int parent){
		// cout << "Src is" << src << endl;
	inTime[src] = time++;
	for(auto it : adj[src]){
		if(it != parent)
		dfs(adj, time, it, src);
	}
	outTime[src] = time++;
}

bool checkSameSubtree(vector<int> inTime, vector<int> outTime, int src, int dst){

	if(inTime[src] < inTime[dst] && outTime[src] > outTime[dst]) return true;
	return false;
}

checkSameSubtree(inTime, outTime, src, dst) ? "YES\n" : "NO\n";