class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
      
        // Define recursive function to generate valid parentheses combinations
        // Parameters:
        // - openCount: number of opening parentheses used so far
        // - closeCount: number of closing parentheses used so far
        // - currentString: current parentheses string being built
        function<void(int, int, string)> backtrack = [&](int openCount, int closeCount, string currentString) {
            // Base case: invalid conditions
            // 1. Too many open parentheses
            // 2. Too many close parentheses  
            // 3. More close parentheses than open (invalid sequence)
            if (openCount > n || closeCount > n || openCount < closeCount) {
                return;
            }
          
            // Valid combination found: both counts equal n
            if (openCount == n && closeCount == n) {
                result.push_back(currentString);
                return;
            }
          
            // Try adding an opening parenthesis
            backtrack(openCount + 1, closeCount, currentString + "(");
          
            // Try adding a closing parenthesis
            backtrack(openCount, closeCount + 1, currentString + ")");
        };
      
        // Start the recursive generation with empty string and zero counts
        backtrack(0, 0, "");
      
        return result;
    }
};
