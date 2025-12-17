class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;              // Store all valid combinations
        vector<int> currentCombination;          // Track current combination being built
      
        // Recursive function to generate combinations
        // Parameter: current number to consider (1 to n)
        function<void(int)> backtrack = [&](int currentNumber) {
            // Base case: found a valid k-sized combination
            if (currentCombination.size() == k) {
                result.emplace_back(currentCombination);
                return;
            }
          
            // Base case: exceeded the range of available numbers
            if (currentNumber > n) {
                return;
            }
          
            // Choice 1: Include current number in the combination
            currentCombination.emplace_back(currentNumber);
            backtrack(currentNumber + 1);
          
            // Backtrack: Remove current number to explore other possibilities
            currentCombination.pop_back();
          
            // Choice 2: Skip current number and move to next
            backtrack(currentNumber + 1);
        };
      
        // Start the recursion from number 1
        backtrack(1);
      
        return result;
    }
};