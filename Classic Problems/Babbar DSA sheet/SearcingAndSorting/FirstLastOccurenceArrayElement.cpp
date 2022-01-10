// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int l = 0;
    int r = n-1;
    int min = n;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(arr[mid] == x){
            if(min > mid){
            min = mid;
            r = mid - 1;
            }
        }
        if(arr[mid]  < x){
            l = mid + 1;
        }
        else{
            r = mid-1;
        }
    }
    int last = min;
    vector <int> v{-1,-1};
    if(min == n){
        return v;
    }
    for(int i = min; i < n-1; i++){
        if(arr[i] != arr[i+1])
        break;
        else{
            last++;
        }
    }
    v[0] = min;
    v[1] = last;
    return v;
        
}

//binary search to find the first occurence of element and 
//then linear search last occurence from first occurence;