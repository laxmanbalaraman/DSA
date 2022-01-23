// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    long long count = 0;
	    long long i, j;
	    sort(arr, arr+n);
	    for(int k = 0; k < n-1; k++){
	        i = k + 1;
	        j = n - 1;
	        long long num = arr[k];
	        while(i < j){
	            if(num + arr[i] + arr[j] < sum){
	                count += j - i;
	                i++;
	            }
	            else{
	                j--;
	            }
	        }
	    }
	  return count;
	        
	}

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends