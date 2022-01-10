// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        int l  = 0;
        int r = n-1;
        int min = arr[0];
        int first = arr[0];
        while(l <= r){
            int mid = l + (r-l)/2;
            int val = arr[mid];
            bool midbig = (val >= first);
            if( midbig ){
                l = mid + 1;
            }
            else{
                if( val <= min)
                min = val;
                r= mid - 1;
            }
        }
        return min;
    }
};

// { Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}  // } Driver Code Ends