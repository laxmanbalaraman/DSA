#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n, dl;
    scanf("%lld %lld", &n, &dl);
    vector<ll> theight;
    for(ll i = 0; i < n; i++){
        ll num;
        scanf("%lld", &num);
        theight.push_back(num);
    }
    sort(theight.begin(),theight.end());
    ll r = theight.back();  
    ll l = 0; 
    ll ans = -1;
    while(l<=r){
        ll height = l + (r-l) / 2;
        ll length = 0;

        for(ll i = 0; i < n; i++){
            if(theight[i] > height){
                length += theight[i] - height;
            }
        }
        if(length == dl){
            ans = height;
            break;
        }
        if(length > dl){
            l = height + 1;
            ans = height;
        }
        else{
            r = height - 1;
        }
    }
    printf("%lld\n",ans);
}