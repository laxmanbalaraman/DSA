// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        int n = v.size();
        int l = 0;
        int r = n-1;
        int min = n;
        while(l <= r){
            int mid = l + (r-l) / 2;
            int val = v[mid];
            
            if(x ==  val){
                if(min  > mid)
                min = mid;
                
                r = mid - 1;
                
            }
            else{
                
                if (val < x){
                    l = mid + 1;
                }
                if (val > x){
                    r = mid - 1;
                }
                
            }
        
        }
        if (min != n){
        int max = min;
        for(int i = min; i < n-1; i++){
            if( v[i] == v[i+1] && v[i] == x )
            max++;
        }
        return {min, max};
        }
        return {-1, -1};
    }
};

// { Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}
  // } Driver Code Ends