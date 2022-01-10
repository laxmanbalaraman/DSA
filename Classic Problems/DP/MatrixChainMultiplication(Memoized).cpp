#include<bits/stdc++.h>
using namespace std;

int dp[10001][10001];

int matrixOrder(int arr[], int i, int j){
    
    if(dp[i][j] != -1) return dp[i][j];

    if(i == j) return dp[i][j] = 0;

    dp[i][j] = INT_MAX;
    int count;
    for(int k = i; k < j; k++){

        count = matrixOrder(arr, i, k) + matrixOrder(arr, k + 1, j) + arr[i-1] * arr[k] * arr[j];

        dp[i][j] = min(dp[i][j], count);
    }

    return dp[i][j];
}

int main(){
    int arr[] = {40, 20, 30, 10, 30};
    memset(dp, -1, sizeof(dp));
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << matrixOrder(arr, 1, n - 1) << endl;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
}