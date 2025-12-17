class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Sort candidates in ascending order for optimization
        sort(candidates.begin(), candidates.end());
      
        // Store all valid combinations
        vector<vector<int>> result;
      
        // Current combination being built
        vector<int> currentCombination;
      
        // Define recursive backtracking function using lambda
        // Parameters: startIndex - current position in candidates array
        //            remainingSum - remaining target value to achieve
        function<void(int, int)> backtrack = [&](int startIndex, int remainingSum) {
            // Base case: found a valid combination
            if (remainingSum == 0) {
                result.emplace_back(currentCombination);
                return;
            }
          
            // Pruning: remaining sum is less than smallest available candidate
            if (remainingSum < candidates[startIndex]) {
                return;
            }
          
            // Try each candidate starting from current index
            // Allow reuse by starting from same index (j) in recursive call
            for (int j = startIndex; j < candidates.size(); ++j) {
                // Choose current candidate
                currentCombination.push_back(candidates[j]);
              
                // Explore with this choice (allow reuse by passing j, not j+1)
                backtrack(j, remainingSum - candidates[j]);
              
                // Backtrack: remove current candidate for next iteration
                currentCombination.pop_back();
            }
        };
      
        // Start backtracking from index 0 with full target sum
        backtrack(0, target);
      
        return result;
    }
};