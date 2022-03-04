#include <bits/stdc++.h>
using namespace std;

void printSubsequence(string s, int index, int n, vector<string> &ans, string myString){
    
    // if index is equal to n then push the final string to vector 
    if(index == n){
        ans.push_back(myString);
        return;
    }

    // include character or not include it
    printSubsequence(s, index + 1, n, ans, myString + s[index]);
    printSubsequence(s, index + 1, n, ans, myString);

}


int main(){
    string s; cin >> s;
    vector<string> ans;
    int n = s.length();
    string myString = "";
    printSubsequence(s, 0, n, ans, myString);
    for(auto i : ans) cout << i << endl;
}

/*
input : abcd
output: 
abcd
abc
abd
ab
acd
ac
ad
a
bcd
bc
bd
b
cd
c
d
*/