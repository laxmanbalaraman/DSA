#include<bits/stdc++.h>
using namespace std;

int subsequenceProductLessThanK(int arr[], int n, int k){
    int dp[k + 1][n + 1];
    for(int prod = 0; prod <= k; prod++){
        for(int num = 0; num <= n; num++){
            if(num == 0) dp[prod][0] = 0;
            else if(prod == 0) dp[0][num] = 0;
            else{
                if(arr[num - 1] > prod) dp[prod][num] = dp[prod][num - 1];
                else{
                    dp[prod][num] = 1 + dp[prod / arr[num - 1]][num - 1] + dp[prod][num - 1];
                }
            }
        }
    }
    return dp[k][n];
}

int main(){
    int arr[] = {4, 8, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 50;
    cout << subsequenceProductLessThanK(arr, n, k);
}


// basically subset sum but with product
// https://ide.geeksforgeeks.org/wU10ddfEZ1