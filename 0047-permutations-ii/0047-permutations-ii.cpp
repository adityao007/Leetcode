class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // Sort the input array to group duplicates together
        sort(nums.begin(), nums.end());
      
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> currentPermutation(n);
        vector<bool> visited(n, false);
      
        // Define recursive function to generate permutations
        function<void(int)> backtrack = [&](int position) {
            // Base case: if we've filled all positions, add current permutation to result
            if (position == n) {
                result.push_back(currentPermutation);
                return;
            }
          
            // Try placing each unused number at the current position
            for (int i = 0; i < n; ++i) {
                // Skip if number is already used
                if (visited[i]) {
                    continue;
                }
              
                // Skip duplicates: if current number equals previous number
                // and previous number hasn't been used yet in this branch
                // This ensures we only use duplicates in the order they appear
                if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                    continue;
                }
              
                // Choose: place nums[i] at current position
                currentPermutation[position] = nums[i];
                visited[i] = true;
              
                // Explore: recurse to fill next position
                backtrack(position + 1);
              
                // Unchoose: backtrack for next iteration
                visited[i] = false;
            }
        };
      
        // Start the backtracking process from position 0
        backtrack(0);
      
        return result;
    }
};