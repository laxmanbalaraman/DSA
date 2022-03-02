#include <bits/stdc++.h>
using namespace std;

bool checkRotation(string a, string b){

    if(a.length() != b.length()) return false;
    
    string temp = a + a;
    return (temp.find(b) != string::npos);
}

int main(){
    string a, b; cin >> a >> b;
    cout << checkRotation(a, b);
}