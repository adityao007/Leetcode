class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // Get dimensions of the grid
        int rows = grid.size();
        int cols = grid[0].size();
      
        // Create a 2D DP table to store minimum path sum to each cell
        // dp[i][j] represents the minimum path sum from (0,0) to (i,j)
        vector<vector<int>> dp(rows, vector<int>(cols));
      
        // Initialize the starting point
        dp[0][0] = grid[0][0];
      
        // Initialize the first column (can only come from above)
        for (int i = 1; i < rows; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
      
        // Initialize the first row (can only come from left)
        for (int j = 1; j < cols; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
      
        // Fill the rest of the DP table
        // For each cell, choose the minimum path from either top or left
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
      
        // Return the minimum path sum to reach the bottom-right corner
        return dp[rows - 1][cols - 1];
    }
};