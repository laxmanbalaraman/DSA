#include <bits/stdc++.h>
using namespace std;


int main(){
    int S, N, M;
    cin >> S >> N >> M;
    if(N < M){
    cout << "No" << " " << 0;
    }
    else{
        // if he can stocks for 6 days must last for 7 days because sunday is holiday and he can't buy
        if( N * 6 >= M * 7){
            cout << "Yes" << " " << ceil(( S * M )/ N);
        }
        else{
            cout << "No" << " " << 0;
        }
    } 
}