class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;           // Stores all subsets
        vector<int> currentSubset;             // Temporary array to build each subset
      
        // Recursive function to generate all subsets using backtracking
        function<void(int)> generateSubsets = [&](int index) -> void {
            // Base case: reached the end of the input array
            if (index == nums.size()) {
                result.push_back(currentSubset);  // Add current subset to result
                return;
            }
          
            // Choice 1: Exclude current element from subset
            generateSubsets(index + 1);
          
            // Choice 2: Include current element in subset
            currentSubset.push_back(nums[index]);
            generateSubsets(index + 1);
          
            // Backtrack: remove the element we just added
            currentSubset.pop_back();
        };
      
        // Start the recursive generation from index 0
        generateSubsets(0);
      
        return result;
    }
};