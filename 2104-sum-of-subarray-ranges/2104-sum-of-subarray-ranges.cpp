class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftmin(n), rightmin(n), leftmax(n), rightmax(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            leftmin[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            rightmin[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            leftmax[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            rightmax[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        long long minsum = 0;
        long long maxsum = 0;
        for (int i = 0; i < n; i++) {
            minsum += 1LL * leftmin[i] * rightmin[i] * nums[i];
            maxsum += 1LL * leftmax[i] * rightmax[i] * nums[i];
        }

        return maxsum - minsum;
    }
};