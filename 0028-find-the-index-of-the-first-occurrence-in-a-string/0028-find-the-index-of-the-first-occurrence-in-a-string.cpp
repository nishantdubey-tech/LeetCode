class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.length();
        int n = haystack.length();
        if (m == 0) return 0;
        vector<int> lps(m, 0);
        int prevLPS = 0; 
        int i = 1;

        while (i < m) {
            if (needle[i] == needle[prevLPS]) {
                prevLPS++;
                lps[i] = prevLPS;
                i++;
            } else {
                if (prevLPS == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    prevLPS = lps[prevLPS - 1]; 
                }
            }
        }
        int haystackPointer = 0; 
        int needlePointer = 0;   

        while (haystackPointer < n) {
            if (haystack[haystackPointer] == needle[needlePointer]) {
                haystackPointer++;
                needlePointer++;
            }

            if (needlePointer == m) {
                return haystackPointer - m; 
            } else if (haystackPointer < n && haystack[haystackPointer] != needle[needlePointer]) {
                if (needlePointer == 0) {
                    haystackPointer++;
                } else {
                    needlePointer = lps[needlePointer - 1];
                }
            }
        }

        return -1;
    }
};