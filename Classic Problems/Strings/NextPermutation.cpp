class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int i;
        for( i = N - 1; i >= 1; i--){
            if(arr[i - 1] < arr[i]) break;
        }
        if(i == 0){
            reverse(arr.begin(), arr.end());
            return arr;
        }
        for(int j = N - 1; j > i - 1; j--){
            if(arr[i - 1] < arr[j]){
                swap(arr[i - 1], arr[j]);
                break;
            }
        } 
        reverse(arr.begin() + i, arr.end());
        return arr;
    }
};