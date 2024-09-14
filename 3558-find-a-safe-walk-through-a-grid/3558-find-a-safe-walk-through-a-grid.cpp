class Solution {
public:
    const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<tuple<int, int, int>> q;
        q.push({0, 0, health - grid[0][0]});
        
        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0] = health - grid[0][0];
        
        while (!q.empty()) {
            auto [x, y, current_health] = q.front();
            q.pop();
            
            if (x == m - 1 && y == n - 1) {
                return current_health > 0;
            }
            
            for (int i = 0; i < 4; i++) {
                int new_x = x + directions[i][0];
                int new_y = y + directions[i][1];

                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                    int new_health = current_health - grid[new_x][new_y];

                    if (new_health > 0 && new_health > visited[new_x][new_y]) {
                        visited[new_x][new_y] = new_health;
                        q.push({new_x, new_y, new_health});
                    }
                }
            }
        }
        
        return false;
    }
};
