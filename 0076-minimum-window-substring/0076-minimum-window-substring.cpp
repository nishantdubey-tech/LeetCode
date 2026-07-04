class Solution {
public:
   string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";
    
    int hash[128] = {0};
    for (char c : t) hash[c]++;
    
    int minLen = INT_MAX, stind = -1;
    int l = 0, r = 0, cnt = 0, m = t.size();
    
    while (r < s.size()) {
       
        if (hash[s[r]] > 0) cnt++;
        hash[s[r]]--;
        r++;
        
       
        while (cnt == m) {
            if (r - l < minLen) {
                minLen = r - l;
                stind = l;
            }
            
            hash[s[l]]++;
            if (hash[s[l]] > 0) cnt--;
            l++;
        }
    }
    return stind == -1 ? "" : s.substr(stind, minLen);
}
};