#include <bits/stdc++.h>
using namespace std;

int solve(int h[], int v[], int m, int n){
    sort(h, h + m, greater<int>());
    sort(v, v + n, greater<int>());
    
    int i = 0, j = 0;
    int horz = 1, verti = 1;
    int cost = 0;
    while(i < m && j < n){
        if(h[i] >= v[j]){
            horz++;
            cost += h[i] * verti;
            i++;
        }
        else{
            verti++;
            cost += v[j] * horz;
            j++;
        }
    }
    while(i < m){
        cost += h[i] * verti; 
        i++;
    }
    while(j < n){
    cost +=  v[j] * horz;
    j++;
    }
    return cost;
    
}


int main(){
    int m, n;
    cin >> m >> n;
    int h[m-1], v[n-1];
    for(int i = 0; i < m-1; i++) cin >> h[i];
    for(int i = 0; i < n-1; i++) cin >> v[i];
    cout << solve(h, v, m-1, n-1);

}