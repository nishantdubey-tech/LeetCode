class Solution {
public:
    void dfs(int index, vector<vector<int>>& stones, vector<bool>& visited) {
       
        visited[index] = true;

        for (int i = 0; i < stones.size(); i++) {
            if (!visited[i]) {
               
                if (stones[index][0] == stones[i][0] || stones[index][1] == stones[i][1]) {
                    dfs(i, stones, visited);
                }
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int connectedComponents = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {

                dfs(i, stones, visited);
                connectedComponents++;
            }
        }

        return n - connectedComponents;
    }
};