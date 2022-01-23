#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n){
    int pos = 0, idx = 0;
    for(int i = 0; i < n; i++){
        if(arr[idx] >= 0){
            idx++;
        }
        else{
            swap(arr[pos++], arr[idx++]);
        }
    }
    
}
void printArray(int arr[] , int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}