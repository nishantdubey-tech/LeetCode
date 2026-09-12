class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        
        if (dict.find(endWord) == dict.end()) return ans;
        
        unordered_map<string, vector<string>> adj; 
        queue<string> q;
        
        q.push(beginWord);
        dict.erase(beginWord);
        
        bool found = false;
        
        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> visitedThisLevel;
            
            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();
                
                string temp = curr;
                for (int j = 0; j < temp.size(); ++j) {
                    char originalChar = temp[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (temp[j] == c) continue;
                        temp[j] = c;
                        
                        if (dict.count(temp)) {
                            if (temp == endWord) found = true;
                            visitedThisLevel.insert(temp);
                            adj[temp].push_back(curr);
                        }
                    }
                    temp[j] = originalChar; 
                }
            }
            for (const string& w : visitedThisLevel) {
                q.push(w);
                dict.erase(w);
            }
        }
        if (found) {
            vector<string> path = {endWord};
            dfs(endWord, beginWord, adj, path, ans);
        }
        
        return ans;
    }
    
private:
    void dfs(string& curr, string& beginWord, unordered_map<string, vector<string>>& adj, vector<string>& path, vector<vector<string>>& ans) {
        if (curr == beginWord) {
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end());
            ans.push_back(validPath);
            return;
        }
        
        for (string& parent : adj[curr]) {
            path.push_back(parent);
            dfs(parent, beginWord, adj, path, ans);
            path.pop_back();
        }
    }
};