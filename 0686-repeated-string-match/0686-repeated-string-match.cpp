class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int min_repeats = (b.length() + a.length() - 1) / a.length();
        
        string repeated_a = "";
        for (int i = 0; i < min_repeats; ++i) {
            repeated_a += a;
        }
        if (repeated_a.find(b) != string::npos) {
            return min_repeats;
        }
        repeated_a += a;
        if (repeated_a.find(b) != string::npos) {
            return min_repeats + 1;
        }
        return -1;
    }
};