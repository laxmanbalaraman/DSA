#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int countRemoval(int arr[], int i, int j, int k){
    if(i >= j) return 0;
    if(arr[j] - arr[i] <= k) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = 1 + min(countRemoval(arr, i + 1, j, k) , countRemoval(arr, i, j - 1, k));
}

int main(){
    int n; cin >> n; int k;  cin >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    memset(dp, -1, sizeof(dp));
    cout << countRemoval(arr, 0, n - 1, k) << endl;
}