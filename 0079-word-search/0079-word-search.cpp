class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
      
        // Direction vectors for moving up, right, down, left
        // dirs[i] and dirs[i+1] form a coordinate pair for each direction
        int dirs[5] = {-1, 0, 1, 0, -1};
      
        // DFS function to search for the word starting from position (row, col)
        // index represents the current character index in the word we're matching
        function<bool(int, int, int)> dfs = [&](int row, int col, int index) -> bool {
            // Base case: reached the last character of the word
            if (index == word.size() - 1) {
                return board[row][col] == word[index];
            }
          
            // Current cell doesn't match the character we're looking for
            if (board[row][col] != word[index]) {
                return false;
            }
          
            // Temporarily mark the current cell as visited by storing its value
            char originalChar = board[row][col];
            board[row][col] = '0';  // Use '0' as a visited marker
          
            // Explore all four directions
            for (int dir = 0; dir < 4; ++dir) {
                int nextRow = row + dirs[dir];
                int nextCol = col + dirs[dir + 1];
              
                // Check if the next position is valid and unvisited
                if (nextRow >= 0 && nextRow < rows && 
                    nextCol >= 0 && nextCol < cols && 
                    board[nextRow][nextCol] != '0') {
                  
                    // Recursively search from the next position
                    if (dfs(nextRow, nextCol, index + 1)) {
                        return true;
                    }
                }
            }
          
            // Backtrack: restore the original character
            board[row][col] = originalChar;
            return false;
        };
      
        // Try starting the search from every cell in the board
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(i, j, 0)) {
                    return true;  // Word found
                }
            }
        }
      
        return false;  // Word not found
    }
};