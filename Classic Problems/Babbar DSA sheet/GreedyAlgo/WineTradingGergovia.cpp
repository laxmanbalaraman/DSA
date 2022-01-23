#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    while(1){
        ll n;
        cin >> n;
        if(n == 0)
            break;
        else{
            vector <pair<ll , ll>> sell;
            vector <pair<ll , ll>> buy;
            for(ll i = 0; i < n; i++){
                ll wine;
                cin >> wine;
                if(wine < 0){
                    sell.push_back({wine, i});
                }
                else{
                    buy.push_back({wine, i});
                }
            }
            ll i = 0;
            ll j = 0;
            ll ans = 0;
            while((i + j + 1) < n){
                ll small = min(abs(sell[i].first), buy[j].first);
                ans += (abs(sell[i].second - buy[j].second) * small);
                sell[i].first += small;
                buy[j].first -= small;
                if(buy[j].first == 0) j++;
                if(sell[i].first == 0 ) i++;
            }
            cout << ans << '\n';
        }
    }
}