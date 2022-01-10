int solve(int arr[], int n, int sum){
        if(n<=0)
            return sum;
        int l = solve(arr, n-2, sum + arr[n-1]);
        int r = solve(arr, n-1, sum);
        return max(l, r);
        
    }
    
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int sum = 0;
        int ans = solve(arr, n, 0);
        return ans;
        
    }