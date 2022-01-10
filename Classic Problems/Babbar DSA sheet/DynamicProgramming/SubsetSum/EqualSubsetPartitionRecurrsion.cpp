// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[100001][100001];
    int solve(int arr[], int N, int sum){
        if(sum == 0) return 1;
        if(N == 0) return 0;
        
        if(dp[N][sum] != -1 ) return dp[N][sum];
        if(arr[N-1] > sum) return solve(arr, N-1, sum);
        return solve(arr, N-1, sum - arr[N-1]) || solve(arr, N-1, sum);
        
        
        
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        
        int sum = 0;
        for(int i = 0; i < N; i++) sum += arr[i];
        if(sum % 2 != 0) return 0; 
        //int dp[N+1][sum+1];
        memset(dp, -1, sizeof(dp));
        return solve(arr, N, sum/2);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends