class Solution {
public:

    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

public:
    int minCut(string s) {
        int n = (int)s.size();
        vector<int> dp(n + 1, 0); 
        dp[n] = -1;
        for (int i = n - 1; i >= 0; i--) {
            int minCuts = INT_MAX;
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    minCuts = min(minCuts, 1 + dp[j + 1]);
                }
            }

            dp[i] = minCuts;
        }
        return dp[0];
    }
    
};