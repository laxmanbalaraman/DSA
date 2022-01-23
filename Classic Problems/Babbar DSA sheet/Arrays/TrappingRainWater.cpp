// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        if(n < 2)
        return 0;
        
        int maxleft = arr[0];
        int maxright = arr[n-1];
        int trap = 0;
        int i = 1;
        int j = n-2;
        while(i <= j){
             if(maxleft < maxright){
                maxleft = max(maxleft, arr[i]);
                trap += (maxleft - arr[i]);
                i++;
             }
             else{
                 maxright = max(maxright, arr[j]);
                 trap += (maxright - arr[j]);
                 j++;
             }
        }
        return trap;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends