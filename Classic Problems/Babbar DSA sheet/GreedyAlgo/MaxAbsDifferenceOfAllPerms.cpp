long long int maxSum(int arr[], int n)
{
    
    sort(arr, arr + n);
    vector <int> v;
    for(int i = 0; i < n/2; ++i){
        v.push_back(arr[i]);
        v.push_back(arr[n - i - 1]);
    }
    if(n % 2 != 0) v.push_back((arr[n/2]));
    int diff = 0;
    for(int i = 0; i < n-1; i++){
        diff += abs(v[i] - v[i+1]);
    }
    diff += abs(v[0] - v[n-1]);
    return diff;
    
    
}