class Solution {
public:
int dfs(vector<vector<int>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0) {
            return 0;
        }

        
        int fish = grid[i][j];
        grid[i][j] = 0;

        fish += dfs(grid, i + 1, j); // Down
        fish += dfs(grid, i - 1, j); // Up
        fish += dfs(grid, i, j + 1); // Right
        fish += dfs(grid, i, j - 1); // Left

        return fish;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] > 0) {
                    maxFish = max(maxFish, dfs(grid, i, j));
                }
            }
        }
        return maxFish;
    }
};