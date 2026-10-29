class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.length();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        if (st.empty()) return "0";
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        int start = 0;
        while (start < res.size() && res[start] == '0') {
            start++;
        }
        res = res.substr(start);

        return res.empty() ? "0" : res;
    }
};