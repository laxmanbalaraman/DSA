bool static comp(pair<int, string> a, pair<int, string> b){
    return a.first > b.first;
}

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string, int> m;
        for(int i = 0; i < n; i++){
            m[arr[i]]++;
        }
        vector<pair<int, string>> v;
        for(auto i : m){
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end(), comp);
        return v[1].second;
    }
};
