class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Create 2D arrays to track numbers in rows, columns, and 3x3 sub-boxes
        // rows[i][num] = true if number (num+1) exists in row i
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        // columns[j][num] = true if number (num+1) exists in column j
        vector<vector<bool>> columns(9, vector<bool>(9, false));
        // subBoxes[k][num] = true if number (num+1) exists in sub-box k
        vector<vector<bool>> subBoxes(9, vector<bool>(9, false));
      
        // Iterate through each cell in the 9x9 board
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                char currentCell = board[row][col];
              
                // Skip empty cells
                if (currentCell == '.') {
                    continue;
                }
              
                // Convert character to 0-indexed number (e.g., '1' -> 0, '9' -> 8)
                int digitIndex = currentCell - '0' - 1;
              
                // Calculate sub-box index (0-8) based on current position
                // Sub-boxes are numbered 0-8 from left to right, top to bottom
                int subBoxIndex = (row / 3) * 3 + (col / 3);
              
                // Check if this number already exists in the same row, column, or sub-box
                if (rows[row][digitIndex] || 
                    columns[col][digitIndex] || 
                    subBoxes[subBoxIndex][digitIndex]) {
                    return false;  // Invalid Sudoku: duplicate found
                }
              
                // Mark this number as seen in the current row, column, and sub-box
                rows[row][digitIndex] = true;
                columns[col][digitIndex] = true;
                subBoxes[subBoxIndex][digitIndex] = true;
            }
        }
      
        // All cells checked without duplicates found
        return true;
    }
};