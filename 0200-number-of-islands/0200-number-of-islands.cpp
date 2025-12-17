class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Get grid dimensions
        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;
      
        // Direction vectors for exploring 4 adjacent cells (up, right, down, left)
        // Using pairs: (-1,0), (0,1), (1,0), (0,-1)
        int directions[5] = {-1, 0, 1, 0, -1};
      
        // DFS function to mark all connected land cells as visited
        function<void(int, int)> dfs = [&](int row, int col) {
            // Mark current cell as visited by changing '1' to '0'
            grid[row][col] = '0';
          
            // Explore all 4 adjacent directions
            for (int k = 0; k < 4; ++k) {
                int nextRow = row + directions[k];
                int nextCol = col + directions[k + 1];
              
                // Check if the adjacent cell is within bounds and is unvisited land
                if (nextRow >= 0 && nextRow < rows && 
                    nextCol >= 0 && nextCol < cols && 
                    grid[nextRow][nextCol] == '1') {
                    // Recursively visit the adjacent land cell
                    dfs(nextRow, nextCol);
                }
            }
        };
      
        // Traverse the entire grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // If we find an unvisited land cell, it's a new island
                if (grid[i][j] == '1') {
                    // Use DFS to mark all connected land cells
                    dfs(i, j);
                    // Increment island count
                    ++islandCount;
                }
            }
        }
      
        return islandCount;
    }
};