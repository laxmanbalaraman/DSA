// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here

        int n = arr.size();
        vector<int> ar;
        for(int a = 0; a < n; a++) ar.push_back(arr[a]);
        sort(ar.begin(), ar.end());
        set<vector<int>> s;
        for(int i = 0; i < n-3;i++){
            for(int j = i+1; j < n-2; j++){
                int sum = ar[i] + ar[j];
                int l = j+1;
                int m = n-1;
                int res = k - sum;
                while( l < m ){
                    if(ar[l] + ar[m] == (res)){
                        s.insert({ar[i], ar[j], ar[l], ar[m]});
                        l++;
                    }
                    if(ar[l] + ar[m] > (res)){
                        m--;
                    }
                    else{
                        l++;
                    }
                }
            }
        }
        vector<vector<int>> v1(s.begin(), s.end());
        return v1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends