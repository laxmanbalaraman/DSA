// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/killing-spree3020/1#

 // } Driver Code Ends
class Solution {
public:
    long long int killinSpree(long long int n)
    {
        // Code Here
        long long l = 0;
        long long r = n;
        long long max = 0;
        while(l <= r ){
            long long  mid = l + (r-l) / 2;
            long long sqrsum = (mid+1)*(mid+2)*(2*mid+3)/6;
            if(sqrsum ==  n){
                return mid+1;
            }
            if( n > sqrsum ){
                l = mid + 1;
                max = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return max;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    }
    return 0;
}
  // } Driver Code Ends