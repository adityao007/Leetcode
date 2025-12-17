class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
      
        // Initialize memoization table with -1 (unvisited state)
        vector<vector<int>> memo(rows, vector<int>(cols, -1));
      
        // Define recursive DFS function with memoization
        auto dfs = [&](this auto&& dfs, int row, int col) -> int {
            // Base case: out of bounds or obstacle encountered
            if (row >= rows || col >= cols || obstacleGrid[row][col] == 1) {
                return 0;
            }
          
            // Base case: reached destination (bottom-right corner)
            if (row == rows - 1 && col == cols - 1) {
                return 1;
            }
          
            // Check if already computed
            if (memo[row][col] == -1) {
                // Compute and store the result: sum of paths going down and right
                memo[row][col] = dfs(row + 1, col) + dfs(row, col + 1);
            }
          
            return memo[row][col];
        };
      
        // Start DFS from top-left corner (0, 0)
        return dfs(0, 0);
    }
};