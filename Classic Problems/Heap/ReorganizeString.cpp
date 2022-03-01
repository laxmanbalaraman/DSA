class Solution {

// using map get the frequency
// put it in priority queue {freq, key} because highest charter first
// init ans var
// pop two characters and attach it to ans string provided they are not same
// decrement character freq and push to queue if freq > 0

// aaaaa
// bb
// cc

// ans -> ababacaca basically alternating string with largest character freq
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        int n = s.length();
        map<char, int> m;
        
        for(int i = 0; i < n; i++) m[s[i]]++;
        for(auto i : m) pq.push({i.second, i.first});
        
        string ans;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            if(!pq.empty()){
                auto q = pq.top();
                pq.pop();
                if(p.second == q.second) return "";
                ans += p.second;
                ans += q.second;
                p.first--, q.first--;
                if(p.first) pq.push(p);
                if(q.first) pq.push(q);
            }else{
                if(p.first > 1) return "";
                ans += p.second;
                p.first--;
            }
        }
        return ans;
    }
};