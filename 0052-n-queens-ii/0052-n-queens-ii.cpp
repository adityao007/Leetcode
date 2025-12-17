class Solution {
public:
    int totalNQueens(int n) {
        // Use bitsets to track occupied columns and diagonals
        // cols[j] = 1 means column j is occupied by a queen
        bitset<10> cols;
        // dg[k] = 1 means diagonal with sum index k is occupied
        // For diagonal: row + col = constant
        bitset<20> diagonals;
        // udg[k] = 1 means anti-diagonal with difference index k is occupied  
        // For anti-diagonal: row - col = constant (shifted by n to avoid negative indices)
        bitset<20> antiDiagonals;
      
        int count = 0;  // Total number of valid N-Queens solutions
      
        // Recursive function to place queens row by row
        function<void(int)> placeQueens = [&](int row) {
            // Base case: all queens successfully placed
            if (row == n) {
                ++count;
                return;
            }
          
            // Try placing a queen in each column of the current row
            for (int col = 0; col < n; ++col) {
                // Calculate diagonal and anti-diagonal indices
                int diagonalIdx = row + col;
                int antiDiagonalIdx = row - col + n;  // Add n to handle negative values
              
                // Check if current position conflicts with existing queens
                if (cols[col] || diagonals[diagonalIdx] || antiDiagonals[antiDiagonalIdx]) {
                    continue;
                }
              
                // Place the queen and mark the column and diagonals as occupied
                cols[col] = true;
                diagonals[diagonalIdx] = true;
                antiDiagonals[antiDiagonalIdx] = true;
              
                // Recursively place queens in the next row
                placeQueens(row + 1);
              
                // Backtrack: remove the queen and unmark the positions
                cols[col] = false;
                diagonals[diagonalIdx] = false;
                antiDiagonals[antiDiagonalIdx] = false;
            }
        };
      
        // Start placing queens from the first row
        placeQueens(0);
      
        return count;
    }
};