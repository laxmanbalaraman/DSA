#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, r; cin >> n >> r;
    int dp[n + 1][r + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= r; j++){
            if (i == 0 && j == 0) dp[0][0] = 1;
            else if(i == 0) dp[i][j] = 0;
            else if(j == 0) dp[i][j] = 1;
            else{
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]*j;
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    cout << dp[n][r] << endl;
}

// ref: https://ide.geeksforgeeks.org/TkN6lT3JTp