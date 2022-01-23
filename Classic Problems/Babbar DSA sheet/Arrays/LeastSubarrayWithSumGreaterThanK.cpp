// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        int minlen = n;
        int i = 0;
        int j = 1;
        int sum = arr[i] + arr[j]; 
        while(j < n && i <= j){
            if(i == j and sum > x)
            return 1;
            if(sum > x){
                int pos = j - i + 1;
                minlen = min(minlen, pos);
                sum -= arr[i];
                i++;
            }
            else{
                j++;
                sum += arr[j];
            }
        }
        return minlen;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends