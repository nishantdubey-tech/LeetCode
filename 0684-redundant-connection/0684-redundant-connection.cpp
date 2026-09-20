 class Solution {
    vector<int> parent;
    
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]); 
    }
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (find(u) == find(v)) {
                return edge; 
            }
            unite(u, v);
        }
        
        return {}; 
    }
};