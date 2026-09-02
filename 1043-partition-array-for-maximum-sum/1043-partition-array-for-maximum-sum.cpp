class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = (int)arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int maxElem = 0;
            int maxSum = 0;
            for (int length = 1; length <= k && i + length <= n; length++) {
                maxElem = max(maxElem, arr[i + length - 1]);
                int currentSum = maxElem * length + dp[i + length];
                maxSum = max(maxSum, currentSum);
            }
            dp[i] = maxSum;
        }
        return dp[0];
    }
};