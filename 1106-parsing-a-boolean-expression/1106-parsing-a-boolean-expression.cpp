class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        
        for (char c : expression) {
            if (c == ',') continue; 
            
            if (c != ')') {
                st.push(c);
            } else {
                bool hasTrue = false, hasFalse = false;
                while (st.top() != '(') {
                    char val = st.top();
                    st.pop();
                    if (val == 't') hasTrue = true;
                    if (val == 'f') hasFalse = true;
                }
                
                st.pop(); 
                char op = st.top(); 
                st.pop(); 
                char res = 'f';
                if (op == '!') {
                    res = hasTrue ? 'f' : 't';
                } else if (op == '&') {
                    res = hasFalse ? 'f' : 't';
                } else if (op == '|') {
                    res = hasTrue ? 't' : 'f';
                }
                
                st.push(res); 
            }
        }
        
        return st.top() == 't';
    }
};