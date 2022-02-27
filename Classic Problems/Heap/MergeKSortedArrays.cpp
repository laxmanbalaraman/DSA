class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        map<int, int> m;
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                m[arr[i][j]]++;
            }
        }
        vector<int> ans;
        for(auto i : m){
            for(int j = 0; j < i.second; j++){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};