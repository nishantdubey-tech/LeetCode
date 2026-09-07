class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh_count++;
                }
            }
        }
        
        int minutes = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty() && fresh_count > 0) {
            int q_size = q.size();
            
            for (int i = 0; i < q_size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                
                for (auto d : directions) {
                    int nr = r + d.first;
                    int nc = c + d.second;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh_count--; 
                        q.push({nr, nc});
                    }
                }
            }
            minutes++; 
        }
        return fresh_count == 0 ? minutes : -1;
    }
};