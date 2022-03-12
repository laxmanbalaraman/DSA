class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        if(m != n) return false;
        
        map<char, char> m1, m2;
        
        for(int i = 0; i < n; i++){
            if(!m1[s[i]] and !m2[t[i]]){
                m1[s[i]] = t[i], m2[t[i]] = s[i];
                continue;
            }
            if(m1[s[i]] != t[i]) return false;
            if(m2[t[i]] != s[i]) return false;
        }
        return true;
    }
};