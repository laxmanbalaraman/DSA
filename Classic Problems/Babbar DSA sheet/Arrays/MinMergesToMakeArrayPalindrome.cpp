#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n){
    int i = 0, j = n-1;
    int ans = 0;
    while(i <= j){
        if(arr[i] == arr[j]){
            i++; j--;
        }
        else if(arr[i] < arr[j]){
            i++;
            arr[i] += arr[i-1];
            ans++;
        }
        else{
            j--;
            arr[j] += arr[j+1];
            ans++;
        }
    }
    cout << ans;
}

int main() {
	//code
    int arr[] = {11, 14, 15, 99};
    int n = sizeof(arr)/sizeof(arr[0]);
	solve(arr, n);
	return 0;
}