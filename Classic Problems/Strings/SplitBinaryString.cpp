#include<bits/stdc++.h>
using namespace std;

int main(){
    string b; cin >> b;
    char curr = b[0];
    int n = b.length();
    int count = 0;
    vector<int> freq;
    for(int i = 0; i < n; i++){
        if(b[i] == curr) count ++;
        else{
            freq.push_back(count);
            count = 1;
            curr = b[i];
        }
    }
    freq.push_back(count);
    // for(auto i : freq) cout << i << endl;
    int ans = 0;
    for(int i = 0; i < freq.size() - 1; i++){
        ans = max(ans, min(freq[i], freq[i + 1]));
    }

    cout << (ans == 0 ? -1 : ans);
}