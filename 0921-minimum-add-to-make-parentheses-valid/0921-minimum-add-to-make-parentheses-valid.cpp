class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_needed = 0; 
        int close_needed = 0; 
        
        for (char ch : s) {
            if (ch == '(') {
                close_needed++; 
            } else if (ch == ')') {
                if (close_needed > 0) {
                    close_needed--; 
                } else {
                    open_needed++; 
                }
            }
        }
        
        return open_needed + close_needed;
    }
};