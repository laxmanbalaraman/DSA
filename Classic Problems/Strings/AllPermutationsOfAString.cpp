// using stl
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    
		    vector<string> ans;
		    sort(S.begin(), S.end());
		    do{
		        ans.push_back(S);
		    } while(next_permutation(S.begin(), S.end()));
		    return ans;
	    }
};

// without stl - upcoming