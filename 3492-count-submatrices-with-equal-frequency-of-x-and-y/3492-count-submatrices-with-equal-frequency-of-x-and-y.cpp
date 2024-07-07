class Solution {
public:
    vector<vector<int>> computePrefixSum(const vector<vector<char>>& grid, char target) {
    int numRows = grid.size();
    int numCols = grid[0].size();
    vector<vector<int>> prefixSum(numRows + 1, vector<int>(numCols + 1, 0));
    
    for (int i = 1; i <= numRows; ++i) {
        for (int j = 1; j <= numCols; ++j) {
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + (grid[i - 1][j - 1] == target ? 1 : 0);
        }
    }
    return prefixSum;
}
    int numberOfSubmatrices(vector<vector<char>>& grid) {
      int numRows = grid.size();
    int numCols = grid[0].size();
    int count = 0;

    vector<vector<int>> prefixX = computePrefixSum(grid, 'X');
    vector<vector<int>> prefixY = computePrefixSum(grid, 'Y');

    for (int endRow = 1; endRow <= numRows; ++endRow) {
        for (int endCol = 1; endCol <= numCols; ++endCol) {
            int numX = prefixX[endRow][endCol];
            int numY = prefixY[endRow][endCol];
            if (numX == numY && numX > 0) {
                count++;
            }
        }
    }
    return count;
    }
};