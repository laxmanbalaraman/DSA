#include<bits/stdc++.h>
using namespace std;


void solve(int arr[], int n, int k){
    priority_queue<pair<int, int>> pq;

    // push first k elements.
    for(int i = 0; i < k; i++) pq.push({arr[i], i});

    // pop the top element of the first K
    cout << pq.top().first << " ";
    
    // add each element from k one by one
    for(int i = k; i < n; i++){
        pq.push({arr[i], i});
        // if the top element doesnot belong to the window, pop it and repeat it until it belongs.
        while(i - pq.top().second >= k){
            pq.pop();
        }
        // display the highest element of that window
        cout << pq.top().first << " ";
    }
}


int main(){
    int n, k; cin >> n >> k; 
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    solve(arr, n, k);
}