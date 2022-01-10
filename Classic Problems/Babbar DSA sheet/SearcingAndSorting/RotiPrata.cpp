#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll t;
    scanf("%lld", &t);
    while(t--){
        ll p, c;
        scanf("%lld %lld",&p ,&c);
        vector <ll> rank;
        for(ll i = 0; i < c; i++){  
            ll r;
            scanf("%lld", &r);
            rank.push_back(r);
        }
        ll l = 0;
        ll r = rank.front() *p * (p+1) / 2;
        ll ans = -1;
        while(l <= r){
            ll time = l + (r-l) / 2;
            //cout << time << endl;
            ll  i = 0;
            ll count  = 0;
            while(count < p && i < c){
                count += (-1 + sqrt(1 + 8*time/rank[i]))/2;
                i++;
            }
            //cout << count << " Count" << endl;
            if (count < p){
                l = time + 1;
            }
            else{
                r = time - 1;
                ans = time;
            }
        }
        printf("%lld\n", ans); 
    }
}