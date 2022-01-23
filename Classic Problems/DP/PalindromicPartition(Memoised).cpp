#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

bool isPalindrome(string s, int i, int j){
    while(i < j){
        if(s[i++] != s[j--]) return false;
    }
    return true;
}

int palindromePartition(string s, int i, int j){

    if(dp[i][j] != -1) return dp[i][j];
    if(i == j) return dp[i][j] = 0;
    if(isPalindrome(s, i , j)) return dp[i][j] = 0;
    dp[i][j] = INT_MAX;
    for(int k = i; k < j; k++){
        dp[i][j] = min(dp[i][j], palindromePartition(s, i, k) + palindromePartition(s, k + 1, j) + 1);
    }
    return dp[i][j];
}

int main(){
    string s; cin >> s;
    int n = s.length();
    memset(dp, -1, sizeof(dp));
    cout << palindromePartition(s, 0, n - 1);
    //cout << isPalindrome("niiin", 0, 3);
}
