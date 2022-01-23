// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    int findPages(int arr[], int n, int m) 
    {
        //code here
        int sum = 0;
        for(int k = 0; k < n; k++) sum+=arr[k];
        int l = arr[n-1],r= sum;
        int result = -1;

        while(l <= r){
            int flag = 0;
            int mid = l + (r-l) / 2;
            int pages = 0;
            int i = 0;
            int student = 1;
            while(i < n){
                if(arr[i] > mid){
                flag = 1;
                break;
                }
                pages += arr[i];
                if(pages > mid){
                    student ++;
                    pages = arr[i];
                }
                i++;
            }
            if(student <= m && flag == 0){
                r = mid - 1;
                if(student == m) // check if no student is leftout
                result = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return result;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends