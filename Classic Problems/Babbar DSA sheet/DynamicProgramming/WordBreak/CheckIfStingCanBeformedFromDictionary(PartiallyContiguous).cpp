class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        string fullstr;
        for(string i : B) fullstr += i;
        //cout << fullstr;
        int n = fullstr.length();
        int alen = A.length();
        for(int i = 0; i <= n - alen; i++){
            int count = 0;
            int curr = i;
            for(int j = 0; j < alen; j++){
                if(A[j] == fullstr[i]){
                    count++;
                    i++;
                } 
            }
            if(count == alen) return 1;
            else count = 0, i = curr;
        }
        return 0;
    }
};