#include <bits/stdc++.h>
using namespace std;

void solve(){
    int h, a;
    cin >> h >> a;
    int live = 0;
    while( h > 0 and a > 0){
        if(a - 8 > 0){
            if(h - 2  > 0){
                h -= 2;
                a -= 8;
                live += 2;
            }
            else{
                h -= 2;
                live ++;
                break;
            }
        }
        else{
            if( h - 17 > 0){
                h -= 17;
                a += 7;
                live += 2;
            }
            else{
                a -= 8;
                live++;
                break;
            }
        }
    }
    cout << live << '\n';
}


int main(){

int t;
cin >>t;
while(t--)
    solve();

}