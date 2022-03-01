class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(long long i = 0; i < n; i++) pq.push(arr[i]);    
        
        long long sum = 0;
        while(pq.size() != 1){
            long long l1 = pq.top();
            pq.pop();
            long long l2 = pq.top();
            pq.pop();
            sum += l1 + l2;
            pq.push(l1 + l2);
        }
        return sum;
    }
};