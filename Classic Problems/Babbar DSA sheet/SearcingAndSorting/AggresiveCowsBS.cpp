#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, c;
        cin >> n >> c;
        vector <ll> barn;
        int loc;
        for(ll i = 0; i < n; i++){
            cin >> loc;
            barn.push_back(loc);
        }
        sort(barn.begin(),barn.end());
        int last = barn.back();
        int l = 1, r = last;
        int maxdist = -1;
        while(l <= r){
            int k = 1;
            int count = 1;
            int gapdist = l + (r-l)/2;
            //cout << gapdist << "gp ";
            int curcow = barn[0];
            while(k < n){
                if( (barn[k] - curcow) >= gapdist){
                    count++;
                    curcow = barn[k];
                }
                k++;
            }
            if(count >=c){
                l = gapdist + 1;
                if(maxdist < gapdist){
                maxdist = gapdist;
                }
            }
            else{
                r = gapdist - 1;
            }
        }
        cout << maxdist << endl;
    }

}