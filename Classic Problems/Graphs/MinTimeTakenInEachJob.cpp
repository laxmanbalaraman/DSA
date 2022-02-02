vector<int> timeTakenByJob(vector<int>adj[], int n){
    
    vector<int> inDegree(n, 0);
    vector<int> jobTime(n, 0);
    // create inDegree array
    for(int i = 0; i < n; i++){
        for(auto it : adj[i]){
            inDegree[it]++;
        }
    }
    
    queue<int> q;
    
    for(int i = 0; i < n; i++){
        if(!inDegree[i]){
            q.push(q);
            jobTime[i] = 1;
        }
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        // remove connections
        for(auto it : adj[node]){
            inDegree[it]--;
            if(!inDegree[it]){
                q.push(it);
                // this node proceeds to do the job after its latest parent node
                jobTime[it] = jobTime[node] + 1;
            }
        }
    }
    
    return jobTime;
    
}