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
        
        int num;
        int maj = 1;
        int maxmaj = 1;
        if(size == 1){
        return a[0];
        }
        sort(a, a+size);
        for(int i = 0; i < size-1; i++){
            if(a[i] == a[i+1]){
                maj++;
                if(maxmaj < maj){
                maxmaj = maj;
                num = a[i];
                }
            }
            if(a[i] < a[i+1]){
                maj = 1;
            }
        }
        if(maxmaj > (size/2)){
            return num;
        }
        return -1;
    }
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