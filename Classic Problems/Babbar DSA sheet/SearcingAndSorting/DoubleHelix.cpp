#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n;
    scanf("%lld", &n);
    while(n!=0){
        vector <ll> p;
        for(ll i = 0; i < n; i++){
            ll num;
            scanf("%lld", &num);
            p.push_back(num);
        }
        ll m;
        scanf("%lld", &m);
        vector <ll> q;
        for(ll i = 0; i < m; i++){
            ll num;
            scanf("%lld", &num);
            q.push_back(num);
        }
        sort(p.begin(), p.end());
        sort(q.begin(), q.end());
        ll i = 0, j = 0;
        ll ans = 0;
        ll psum = 0, qsum = 0;
        while(i < n && j < m ){
            if(p[i] > q[j]){
                qsum += q[j];
                j++;
            }
            else if(q[j] > p[i]){
                psum += p[i];
                i++;
            }
            else{
                ans += max(psum, qsum) + p[i];
                psum = qsum = 0;
                i++;
                j++;
            }
            
        }
        while(i < n){
            psum += p[i++];
        }
        while(j < m){
            qsum +=q[j++];
        }
        ans += max(psum, qsum);
        printf("%lld \n" , ans);
        scanf("%lld", &n);
    }
}