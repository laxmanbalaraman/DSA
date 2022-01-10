class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int n = S.length();
	    int first = (S[0] == '0' ? 1 : -1); 
	    int total_max = first, curr_max = first;
	    for(int i = 1; i < n; i++){
	        int num = (S[i] == '0' ? 1 : -1);
	        curr_max = max(num, curr_max + num);
	        total_max = max(total_max, curr_max);
	    }
	    return total_max;
	}
};