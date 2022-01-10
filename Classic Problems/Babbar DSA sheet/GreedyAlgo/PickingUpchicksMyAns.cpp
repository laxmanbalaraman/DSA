#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(ll t){
    ll N, K, B, T;
    cin >> N >> K >> B >> T;
    vector<ll> dist, speed;
    for(ll i = 0; i < N; i++){
        ll num;
        cin >> num;
        dist.push_back(num);
    }
    vector <bool> eligibile;
    ll reachable = 0;
    for(ll i = 0; i < N; i++){
        ll num;
        cin >> num;
        speed.push_back(num);
        if( (B - dist[i]) <= num * T ){
             eligibile.push_back(1);
             reachable++;
        }
        else eligibile.push_back(0);
    }
    if(reachable < K){
        cout << "Case #" << t + 1 << ": IMPOSSIBLE" << '\n';
        return;
    }
    ll swaps = 0;
    ll slow = 0;
    ll reached = 0;
    for(ll i = N - 1; i >= 0; i--){
        if(!eligibile[i]) slow++;
        else{
            if(reached == K){
                cout << "Case #" << t + 1 << ": " << swaps << '\n';
                return;
            }
            reached++;
            if(slow > 0)
                swaps += slow;
            if(reached == K){
                cout << "Case #" << t + 1 << ": " << swaps << '\n';
                return;
            }
        }
        
    }

}

int main(){
    ll t;
    cin >> t;
    ll test = 0;
    while(test < t){
        solve(test);
        test++;
    }

}