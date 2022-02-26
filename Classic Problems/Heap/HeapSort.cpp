#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){

    int largest = i;
    int r = 2 * i + 1;
    int l = 2 * i + 2;

    if( l < n && arr[largest] < arr[l]) largest = l;
    if(r < n && arr[largest] < arr[r]) largest = r;

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}


void heapSort (int arr[], int n){
    
    // first heapify the whole tree, s.t. each node is maximum than its direct child nodes
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    // now the first element in the array is the largest number, swap it with the last leaf node

    for(int i = n - 1; i >= 0; i--){ 
        swap(arr[i], arr[0]);
        // since the whole tree is in heapfied state except the root node that was swapped, heapify from the root node.
        heapify(arr, i, 0);
    }
}

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    heapSort(arr, n);

    for(int i = 0; i < n; i++) cout << arr[i];
}