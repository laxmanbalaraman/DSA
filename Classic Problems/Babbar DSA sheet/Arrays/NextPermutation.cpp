class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int peak = -1;
        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums[i] < nums[i+1])
                peak = i+1;
        }
        // if no peak exists then just reverse the array
        if(peak == -1){
            reverse(nums.begin(), nums.end());
        }
        // if peak exists then we need to swap the previous element with the element from the
        // peak till the end of the array that is lies bewteen prev and peak (incl peak)
        else{
            int idx = peak;
            for(int i = peak; i < nums.size(); ++i){
                if(nums[peak-1] < nums[i] && nums[i] <= nums[peak]){
                    idx = i;
                }
            }
            swap(nums[idx], nums[peak-1]);
            reverse(nums.begin() + peak, nums.end());
        }
    }
};