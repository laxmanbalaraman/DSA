    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
        vector <pair<int , int>> t(n);
        for(int i = 0; i < n; i++ ){
            t[i].first = arr[i];
            t[i].second = dep[i];
        }
        sort(t.begin(), t.end());
    	priority_queue <int, vector<int>, greater<int>> pq;
    	pq.push(t[0].second);
    	int pf = 1;
    	for(int i = 1; i < n; i++){
    	    if(t[i].first <= pq.top() ){
    	        pq.push(t[i].second);
    	        pf++;
    	    }
    	    else{
    	        pq.pop();
    	        pq.push(t[i].second);
    	    }
    	}
    	return pf;
    }