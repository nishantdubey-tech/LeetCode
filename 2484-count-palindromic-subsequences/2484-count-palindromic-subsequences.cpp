class Solution {
public:
    int countPalindromes(string s) {
        int n = s.length();
        int MOD = 1e9 + 7;
        
        long long right_count[10] = {0};
        long long right_pair[10][10] = {0};
        for (int i = n - 1; i >= 0; --i) {
            int d = s[i] - '0';
            for (int j = 0; j < 10; ++j) {
                right_pair[d][j] += right_count[j];
            }
            right_count[d]++;
        }
        
        long long left_count[10] = {0};
        long long left_pair[10][10] = {0};
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            right_count[d]--;
            for (int j = 0; j < 10; ++j) {
                right_pair[d][j] -= right_count[j];
            }
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    ans = (ans + left_pair[j][k] * right_pair[k][j]) % MOD;
                }
            }
            for (int j = 0; j < 10; ++j) {
                left_pair[j][d] += left_count[j];
            }
            left_count[d]++;
        }
        
        return ans;
    }
};