class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: if only one row, return original string
        if (numRows == 1) {
            return s;
        }
      
        // Create a vector of strings, each representing a row in the zigzag pattern
        vector<string> rows(numRows);
      
        // currentRow: tracks which row we're currently adding characters to
        // direction: controls whether we're moving down (+1) or up (-1) in the zigzag
        int currentRow = 0;
        int direction = -1;
      
        // Iterate through each character in the input string
        for (char ch : s) {
            // Add current character to the appropriate row
            rows[currentRow] += ch;
          
            // Change direction when reaching the top row (0) or bottom row (numRows - 1)
            if (currentRow == 0 || currentRow == numRows - 1) {
                direction = -direction;
            }
          
            // Move to the next row based on current direction
            currentRow += direction;
        }
      
        // Concatenate all rows to form the final result
        string result;
        for (const auto& row : rows) {
            result += row;
        }
      
        return result;
    }
};