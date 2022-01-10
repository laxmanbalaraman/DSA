class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        int total_sum = arr[0], curr_sum = arr[0];
        for(int i = 1; i < n; i++){
            curr_sum = max(arr[i], curr_sum + arr[i]);
            total_sum = max(total_sum, curr_sum);
        }
        return total_sum;
    }
};