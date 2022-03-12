class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        int n = x.length();
        int i = 0;
        while(i < n){
            if(x[i] == '[' || x[i] == '(' || x[i] == '{' ){
                s.push(x[i]);
            }
            else{
                if(s.empty()) return false;
                char t = s.top();
                if(x[i] == '}' and t != '{') return false;
                if(x[i] == ')' and t != '(') return false;
                if(x[i] == ']' and t != '[') return false;
                s.pop();
            }
            i++;
        }
        return s.empty();
    }
};