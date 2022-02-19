#include <bits/stdc++.h>
using namespace std;

vector<int> inTime;
vector<int> outTime;

void resize(int v){
	inTime.resize(v + 1);
	outTime.resize(v + 1);
}

void makeAdjacency(vector<int> adj[], int e){
	// since edges is v - 1 and there is unique connection between every node
	// it is nothing but a tree to be precise. 
	for(int i = 0; i < e; i++){
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

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

	// check if the dst is in the same subtree of src if moving away from node (or)
	// src in same subtree of dst if moving towards root.  
	
	if(inTime[src] < inTime[dst] && outTime[src] > outTime[dst]) return true;
	return false;
}

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);

int v; scanf("%d", &v);
vector<int> adj[v + 1];
makeAdjacency(adj, v - 1);


int time = 0;
resize(v);
dfs(adj, time, 1, 0);



int q; scanf("%d", &q);

while(q--){
	int dir, dst, src; scanf("%d%d%d", &dir, &dst, &src);
	if(dir == 0) swap(src, dst); 
	printf(checkSameSubtree(inTime, outTime, src, dst) ? "YES\n" : "NO\n");
}

}