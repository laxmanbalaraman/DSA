#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j){
    while(i < j){
        if(s[i++] != s[j--]) return false;
    }
    return true;
}

int palindromePartition(string s, int i, int j){

    if(i == j) return 0;
    if(isPalindrome(s, i , j)) return 0;
    int mn, cnt = INT_MAX;
    for(int k = i; k < j; k++){
        mn = palindromePartition(s, i, k) + palindromePartition(s, k + 1, j) + 1;
        cnt = min(mn, cnt);
    }
    return cnt;
}

int main(){
    string s; cin >> s;
    int n = s.length();
    cout << palindromePartition(s, 0, n - 1);
    //cout << isPalindrome("niiin", 0, 3);
}
