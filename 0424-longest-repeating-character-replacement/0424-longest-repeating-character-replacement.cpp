class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        int l = 0;
        int max_freq = 0;
        unordered_map<char, int> mpp;

        for (int r = 0; r < s.length(); r++) {
            mpp[s[r]]++;
            max_freq = max(max_freq, mpp[s[r]]);
            while ((r - l + 1) - max_freq > k) {
                mpp[s[l]]--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};