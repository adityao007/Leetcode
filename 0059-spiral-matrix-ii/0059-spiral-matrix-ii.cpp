class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Initialize n x n matrix filled with zeros
        vector<vector<int>> matrix(n, vector<int>(n, 0));
      
        // Direction vectors: right(0,1), down(1,0), left(0,-1), up(-1,0)
        // Using array format: [rowDelta1, colDelta1, rowDelta2, colDelta2, ...]
        const int directions[5] = {0, 1, 0, -1, 0};
      
        // Current position (row, col) and direction index
        int currentRow = 0;
        int currentCol = 0;
        int directionIndex = 0;  // 0=right, 1=down, 2=left, 3=up
      
        // Fill the matrix with values from 1 to n*n in spiral order
        for (int value = 1; value <= n * n; ++value) {
            // Place current value at current position
            matrix[currentRow][currentCol] = value;
          
            // Calculate next position based on current direction
            int nextRow = currentRow + directions[directionIndex];
            int nextCol = currentCol + directions[directionIndex + 1];
          
            // Check if we need to change direction:
            // - If next position is out of bounds
            // - If next position is already filled (non-zero)
            if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n || 
                matrix[nextRow][nextCol] != 0) {
                // Turn clockwise to next direction
                directionIndex = (directionIndex + 1) % 4;
            }
          
            // Move to next position using current (possibly updated) direction
            currentRow += directions[directionIndex];
            currentCol += directions[directionIndex + 1];
        }
      
        return matrix;
    }
};