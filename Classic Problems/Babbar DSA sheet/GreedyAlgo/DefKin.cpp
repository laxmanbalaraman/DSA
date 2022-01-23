#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll l, b;
    cin >> l >> b;
    ll n;
    cin >> n;
    vector <ll> x, y;
    x.push_back(0);
    y.push_back(0);
    for(ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    x.push_back(l + 1);
    y.push_back(b + 1);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll maxx = 0;
    ll maxy = 0;
    for(ll i = 0; i < n + 1 ; i++){
        maxx = max(maxx,x[i+1] - x[i] - 1);
        maxy = max(maxy,y[i+1] - y[i] - 1 );
    }

    cout << maxx * maxy << endl;
}


int main(){

    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}