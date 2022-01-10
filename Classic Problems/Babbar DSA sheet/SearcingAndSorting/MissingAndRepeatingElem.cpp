// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        map <int, int> mp;
        
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        int max = 2, min = 0;
        int rep, miss;
        for(int i = 0; i < n; i++){
            if(mp[i+1] == max)
            rep = i+1;
            else if(mp[i+1] == min)
            miss = i+1;
        }
        int *ans = new int(2);
        ans[0] = rep;
        ans[1] = miss;
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends