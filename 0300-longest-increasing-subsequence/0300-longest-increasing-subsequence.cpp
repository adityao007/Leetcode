class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
      
        // dp[i] represents the length of the longest increasing subsequence 
        // ending at index i
        vector<int> dp(n, 1);
      
        // Iterate through each position as potential end of subsequence
        for (int i = 1; i < n; ++i) {
            // Check all previous elements that could form an increasing subsequence
            for (int j = 0; j < i; ++j) {
                // If current element is greater than previous element,
                // we can extend the subsequence ending at j
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
      
        // Return the maximum length among all possible ending positions
        return *max_element(dp.begin(), dp.end());
    }
};
