class neighborSum {
private:
    std::vector<std::vector<int>> grid;
    std::unordered_map<int, std::pair<int, int>> valuePositionMap;
    int n;

public:
    // Constructor to initialize the object with the grid
    neighborSum(std::vector<std::vector<int>>& grid) : grid(grid) {
        n = grid.size();
        // Create a map to store the position of each value
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                valuePositionMap[grid[i][j]] = {i, j};
            }
        }
    }

    // Function to get the sum of adjacent neighbors
    int adjacentSum(int value) {
        if (valuePositionMap.find(value) == valuePositionMap.end()) {
            throw std::invalid_argument("Value not found in the grid");
        }
        int sum = 0;
        int i = valuePositionMap[value].first;
        int j = valuePositionMap[value].second;

        // Check the top neighbor
        if (i > 0) sum += grid[i-1][j];
        // Check the bottom neighbor
        if (i < n-1) sum += grid[i+1][j];
        // Check the left neighbor
        if (j > 0) sum += grid[i][j-1];
        // Check the right neighbor
        if (j < n-1) sum += grid[i][j+1];

        return sum;
    }

    // Function to get the sum of diagonal neighbors
    int diagonalSum(int value) {
        if (valuePositionMap.find(value) == valuePositionMap.end()) {
            throw std::invalid_argument("Value not found in the grid");
        }
        int sum = 0;
        int i = valuePositionMap[value].first;
        int j = valuePositionMap[value].second;

        // Check the top-left diagonal
        if (i > 0 && j > 0) sum += grid[i-1][j-1];
        // Check the top-right diagonal
        if (i > 0 && j < n-1) sum += grid[i-1][j+1];
        // Check the bottom-left diagonal
        if (i < n-1 && j > 0) sum += grid[i+1][j-1];
        // Check the bottom-right diagonal
        if (i < n-1 && j < n-1) sum += grid[i+1][j+1];

        return sum;
    }
};