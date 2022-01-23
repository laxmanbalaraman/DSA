class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
     sort(intervals.begin(), intervals.end());
     vector <vector<int>> ans;
     if(intervals.empty()) return ans;
     
     vector<int> prev = intervals[0];
     for(auto interval : intervals){
         if(prev[1] >= interval[0]){
             prev[1] = max(interval[1], prev[1]);
         }
         else{
             ans.push_back(prev);
             prev = interval;
         }
     }
        ans.push_back(prev);
        return ans;
    }
};