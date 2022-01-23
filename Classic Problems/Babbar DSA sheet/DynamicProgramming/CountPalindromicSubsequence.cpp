    public:
    /*You are required to complete below method */
    int dp[1001][1001];
    int MOD = 1000000007;
    int solve(string str, int i, int j){
        if(dp[i][j] != -1) return dp[i][j];
        if(i > j) return dp[i][j] = 0;
        if(i == j) return dp[i][j] = 1;

        if(str[i] == str[j]){
            return dp[i][j] = (MOD + 1 + (solve(str, i + 1, j) % MOD + solve(str, i, j - 1) % MOD)) % MOD;    
        }
        else{
            return dp[i][j] = (((solve(str, i + 1, j) % MOD + solve(str, i, j - 1) %MOD)
            %MOD - solve(str, i + 1, j - 1) + MOD) % MOD);
        }
    }
    long long int  countPS(string str)
    {
       //Your code here
       memset(dp, -1, sizeof(dp));
       int n = str.length();
       
       
    return solve(str, 0, n -1) % MOD;
  }
 // for some reason it gives tle (My code)
// AC code 


class Solution{
    public:
int dp[1000][1000];
int mod  = 1000000007;
long long int countpalindrome(string &s, int i, int e) {
if (i > e)
return 0;
if (i == e)
return dp[i][e] = 1;
if (dp[i][e] != -1)
return dp[i][e];
else if (s[i] == s[e])
return dp[i][e] = (countpalindrome(s, i + 1, e) % mod + countpalindrome(s, i, e - 1) % mod + 1 + mod) % mod;
else
return dp[i][e] = (countpalindrome(s, i + 1, e) % mod + countpalindrome(s, i, e - 1) % mod - countpalindrome(s, i + 1, e - 1) % mod + mod) % mod;
}
long long int countPS(string str)
{

memset(dp, -1, sizeof(dp));
return countpalindrome(str, 0, str.size() - 1) % mod;


}