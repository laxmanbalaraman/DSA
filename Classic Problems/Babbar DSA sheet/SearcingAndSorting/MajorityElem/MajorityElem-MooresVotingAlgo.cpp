// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        int candidate = -1;
        int num = a[0];
        int count = 0;
        for(int i = 0; i < size; i++){
            if(count == 0){
                candidate = a[i];
            }
            if(candidate == a[i])
            count++;
            else
            count--;
        }
        //cout << candidate << " ";
        int c = 0;
        for(int i = 0; i < size; i++){
            if (a[i] == candidate)
            c++;
        }
        if(c > size/2)
            return candidate;
        return -1;
    }
    
    // O(n+n) = O(n);
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends