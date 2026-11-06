class Solution {
private:
    pair<int, int> getTreeProperties(int n, const vector<vector<int>>& edges) {
        if (n == 1) return {0, 0};
        
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        
        int levels = 0;
        int remainingNodes = n;
        
        while (remainingNodes > 2) {
            int sz = q.size();
            remainingNodes -= sz;
            levels++;
            for (int i = 0; i < sz; ++i) {
                int curr = q.front();
                q.pop();
                for (int neighbor : adj[curr]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }
        int diameter = (remainingNodes == 2) ? 2 * levels + 1 : 2 * levels;
        int radius = levels; 
        if (remainingNodes == 2) radius++;
        
        return {diameter, radius};
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        
        auto [d1, r1] = getTreeProperties(n, edges1);
        auto [d2, r2] = getTreeProperties(m, edges2);
        
        return max({d1, d2, r1 + r2 + 1});
    }
};