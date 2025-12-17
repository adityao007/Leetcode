class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;           // Store all permutations
        vector<int> currentPermutation(n);    // Current permutation being built
        vector<bool> visited(n, false);       // Track which elements are used
      
        // Define recursive lambda function for generating permutations
        auto generatePermutations = [&](this auto&& generatePermutations, int position) -> void {
            // Base case: if we've filled all positions, add current permutation to result
            if (position == n) {
                result.emplace_back(currentPermutation);
                return;
            }
          
            // Try placing each unused number at the current position
            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    // Mark element as used
                    visited[i] = true;
                    // Place element at current position
                    currentPermutation[position] = nums[i];
                    // Recursively fill next position
                    generatePermutations(position + 1);
                    // Backtrack: mark element as unused for next iteration
                    visited[i] = false;
                }
            }
        };
      
        // Start generating permutations from position 0
        generatePermutations(0);
        return result;
    }
};