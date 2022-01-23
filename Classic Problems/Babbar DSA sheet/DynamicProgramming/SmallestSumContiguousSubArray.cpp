#include<iostream>
using namespace std;

int smallestContiguousSum(int a[], int size)
{
    int total_min = a[0], curr_min = a[0];
    for(int i = 1; i < size; i++){
        curr_min = min(a[i], curr_min + a[i]);
        total_min = min(total_min, curr_min);
    }
    return total_min;
}

/* Driver program to test smallestContiguousSum */
int main()
{
int a[] = {2, 6, 8, 1, 4};
int n = sizeof(a)/sizeof(a[0]);
int min_sum = smallestContiguousSum(a, n);
cout << "Maximum contiguous sum is " << min_sum;
return 0;
}


link: https://ide.geeksforgeeks.org/X5GBdwbM6b