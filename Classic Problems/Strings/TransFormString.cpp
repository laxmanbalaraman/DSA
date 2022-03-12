class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        int n = A.length(), m = B.length();
        
        if(n!= m) return -1;
        
        map<char, int>m1, m2;
        for(int i = 0; i < n; i++){
            m1[A[i]]++, m2[B[i]]++;
        }
        if(m1 != m2) return -1;
        
        int i = n - 1, j = n - 1;
        int ans = 0;
        while(i >= 0){
            if(A[i] != B[j]){
                i--;
                ans++;
            }else{
                i--, j--;
            }
        }
        return ans;
    }
};