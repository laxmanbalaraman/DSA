#include <bits/stdc++.h>
using namespace std;

bool equalSum(int arr[],int currsum,  int remsum, int n){
    
    if(n==0 || currsum > remsum) {
        //cout << "yes " << currsum << " " << remsum << endl;
        return false;
    }
    if(currsum == remsum){
        return true;
    } 
    
    return equalSum(arr, currsum + arr[n-1], remsum - arr[n-1], n-1) || 
	equalSum(arr, currsum, remsum, n-1); 
    
    
    
    
    
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    int currsum = 0;
    cout << equalSum(arr , currsum, sum, n);
}