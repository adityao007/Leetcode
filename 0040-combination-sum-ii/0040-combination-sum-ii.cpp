class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort the candidates array to handle duplicates and enable early termination
        sort(candidates.begin(), candidates.end());
      
        // Store all valid combinations
        vector<vector<int>> result;
      
        // Current combination being built
        vector<int> currentCombination;
      
        // Define recursive backtracking function using lambda
        function<void(int, int)> backtrack = [&](int startIndex, int remainingTarget) {
            // Base case: found a valid combination
            if (remainingTarget == 0) {
                result.emplace_back(currentCombination);
                return;
            }
          
            // Pruning: stop if we've exhausted all candidates or remaining target is too small
            if (startIndex >= candidates.size() || remainingTarget < candidates[startIndex]) {
                return;
            }
          
            // Try each candidate starting from startIndex
            for (int currentIndex = startIndex; currentIndex < candidates.size(); ++currentIndex) {
                // Skip duplicates at the same recursion level
                // Allow the first occurrence, skip subsequent duplicates
                if (currentIndex > startIndex && candidates[currentIndex] == candidates[currentIndex - 1]) {
                    continue;
                }
              
                // Include current candidate in the combination
                currentCombination.emplace_back(candidates[currentIndex]);
              
                // Recursively search with updated parameters
                // Move to next index since each element can only be used once
                backtrack(currentIndex + 1, remainingTarget - candidates[currentIndex]);
              
                // Backtrack: remove the current candidate for next iteration
                currentCombination.pop_back();
            }
        };
      
        // Start the backtracking process from index 0 with the full target
        backtrack(0, target);
      
        return result;
    }
};