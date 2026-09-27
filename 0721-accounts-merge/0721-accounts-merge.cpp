class DisjointSet {
    vector<int> parent;
public:
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionNodes(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU != rootV) {
            parent[rootV] = rootU; 
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> emailToNode;
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (emailToNode.find(mail) == emailToNode.end()) {
                    emailToNode[mail] = i;
                } else {
                    ds.unionNodes(i, emailToNode[mail]);
                }
            }
        }

        vector<vector<string>> mergedMails(n);
        for (auto it : emailToNode) {
            string mail = it.first;
            int rootNode = ds.findParent(it.second);
            mergedMails[rootNode].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMails[i].empty()) continue;
            
            sort(mergedMails[i].begin(), mergedMails[i].end());
            
            vector<string> temp;
            temp.push_back(accounts[i][0]); 
            for (auto mail : mergedMails[i]) {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};