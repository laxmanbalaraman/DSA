class Solution{
public:	

    void heapify(int arr[], int n, int i){
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        
        if( l < n && arr[largest] < arr[l]) largest = l;
        if(r < n && arr[largest] < arr[r]) largest = r;
        
        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    
	    vector<int> ans;
	    
	    for(int i = n / 2 - 1; i >= 0; i--){
	        heapify(arr, n, i);
	    }
	    
	    for(int i = n - 1; i >= n - k; i--){
	        swap(arr[i], arr[0]);
	        ans.push_back(arr[i]);
	        heapify(arr, i, 0);
	    }
	    return ans;
	}

};


// using priority queue for

class solution{
public:	

	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int> pq;
	    vector<int> ans;
	    for(int i = 0; i < n; i++) pq.push(arr[i]);
	    
	    for(int i = 0; i < k; i++){
	        ans.push_back(pq.top());
	        pq.pop();
	    }
	    
	    return ans;
	}
}