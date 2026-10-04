class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int row = 1; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                
                int up = matrix[row - 1][col];
                
                int leftDiagonal = (col > 0) ? matrix[row - 1][col - 1] : 1e9; 
                int rightDiagonal = (col < n - 1) ? matrix[row - 1][col + 1] : 1e9;
                
                matrix[row][col] += min({up, leftDiagonal, rightDiagonal});
            }
        }
        
        int minSum = 1e9;
        for (int col = 0; col < n; ++col) {
            minSum = min(minSum, matrix[n - 1][col]);
        }
        
        return minSum;
    }
};