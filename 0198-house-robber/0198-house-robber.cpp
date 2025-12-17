class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
      
        // dp[i] represents the maximum amount that can be robbed from houses [i, n-1]
        // Initialize with -1 to indicate uncomputed state
        int dp[n];
        memset(dp, -1, sizeof(dp));
      
        // Recursive function with memoization to calculate maximum robbery amount
        // starting from index i
        auto dfs = [&](this auto&& dfs, int i) -> int {
            // Base case: if index is out of bounds, no money can be robbed
            if (i >= n) {
                return 0;
            }
          
            // If not yet computed, calculate the maximum amount
            if (dp[i] < 0) {
                // Two choices at each house:
                // 1. Rob current house and skip next house (nums[i] + dfs(i + 2))
                // 2. Skip current house and move to next house (dfs(i + 1))
                dp[i] = max(nums[i] + dfs(i + 2), dfs(i + 1));
            }
          
            return dp[i];
        };
      
        // Start the recursion from the first house (index 0)
        return dfs(0);
    }
};
