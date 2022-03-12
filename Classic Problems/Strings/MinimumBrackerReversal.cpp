int countRev (string s){
    stack<char>st;
    int n = s.length();
    if(n % 2 != 0) return -1;
    int closed = 0;
    for(int i = 0; i < n; i++){
        // if its '{', then add it to stack
        if(s[i] == '{') st.push('{');
        else{
            if(!st.empty()) st.pop();
            // if the stack is empty but there is no '{' to pop, 
            // then simply count them, nothing can be done
            else closed++;
        }
    }
        // }}{{ -> 2 (even + even) / 2
        if(closed % 2 == 0) return (closed + st.size()) / 2;
        // }{{{{ -> (odd + odd) / 2 + 1
        else return ((closed + st.size())  / 2 + 1);
}