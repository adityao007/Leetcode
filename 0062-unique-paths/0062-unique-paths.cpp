class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2D DP table to store the number of unique paths to each cell
        // dp[i][j] represents the number of unique paths to reach cell (i, j)
        vector<vector<int>> dp(m, vector<int>(n));
      
        // Initialize the starting position with 1 path (we start here)
        dp[0][0] = 1;
      
        // Fill the DP table row by row
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                // Add paths from the cell above (if it exists)
                if (row > 0) {
                    dp[row][col] += dp[row - 1][col];
                }
              
                // Add paths from the cell to the left (if it exists)
                if (col > 0) {
                    dp[row][col] += dp[row][col - 1];
                }
            }
        }
      
        // Return the number of unique paths to the bottom-right corner
        return dp[m - 1][n - 1];
    }
};