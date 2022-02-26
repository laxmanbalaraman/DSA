#include <bits/stdc++.h>
using namespace std;


void heapify(int arr[], int i, int n){
    
    // assuming root is largest 
    int largest = i;
    int r = 2 * i + 1;
    int l = 2 * i + 2;
    if(r < n && arr[r] > arr[largest]) largest = r;
    if(l < n && arr[l] > arr[largest]) largest = l;

    // root node wasn't the largest, swap the max node with the root node
    if(largest != i){
        swap(arr[largest], arr[i]);
        // recurse through the node that got swapped as the the prev node could have be smaller 
        // the other nodes below this subtree.
        heapify(arr, largest, n); 
    }

}

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    // start from the last internal node => n/2 - 1;

    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, i, n);
    } 

    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}