#include <bits/stdc++.h>
using namespace std;


int maxStock(vector<int> &prices, int n, int amount){
    // Write your code here
    int stocks = 0;
    vector<pair <int, int>> v(n);
    for(int i = 0; i < n; i++){
        v[i] = {prices[i], i+1};
	}
    sort(v.begin(), v.end());
	int tot_stocks = 0;
    for(int i = 0; i < n; i++){
        if(amount >= v[i].first){
        int max_stocks = min(amount / v[i].first, v[i].second);
        amount -= max_stocks*v[i].first;
        tot_stocks += max_stocks;
        }
        else
            break;
    }
    return tot_stocks ;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, amount;
        cin >> n >> amount;
        vector <int> prices(n);
        for(int i = 0; i < n; i++){
            cin >> prices[i];
        }
        cout << maxStock(prices, n, amount) << '\n';
    }
}