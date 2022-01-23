// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    
    int dp[10001];
    int solve(int arr[], int n){
        
        if (n <= 0)
            return 0;
        
        if(dp[n-1] != -1)
            return dp[n-1]; 
            
        int taken = arr[n-1] + solve(arr, n-2);
        int not_taken = solve(arr, n-1);
        return dp[n-1] = max(taken, not_taken);
        
        
    }
    
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
    
    memset(dp, -1, sizeof(dp));
    //dp[0] = 0;
    
    int ans = solve(arr, n);
    for(int i = 0; i <= n; i++){
        cout << dp[i] << " ";
    }
    // 5 5 15 105 105 110 -1 110
    return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends