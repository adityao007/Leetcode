class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int numCoins = coins.size();
      
        // dp[i][j] represents the minimum number of coins needed to make amount j
        // using the first i types of coins
        int dp[numCoins + 1][amount + 1];
      
        // Initialize with a large value (infinity)
        // 0x3f3f3f3f is commonly used as infinity in competitive programming
        memset(dp, 0x3f, sizeof(dp));
      
        // Base case: 0 coins are needed to make amount 0
        dp[0][0] = 0;
      
        // Fill the dp table
        for (int i = 1; i <= numCoins; ++i) {
            for (int j = 0; j <= amount; ++j) {
                // Option 1: Don't use the current coin type
                dp[i][j] = dp[i - 1][j];
              
                // Option 2: Use the current coin type (if possible)
                if (j >= coins[i - 1]) {
                    // We can use the same coin type multiple times (unbounded knapsack)
                    // So we check dp[i][j - coins[i - 1]] instead of dp[i - 1][j - coins[i - 1]]
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
                }
            }
        }
      
        // If the minimum coins needed exceeds the amount itself, it's impossible
        // Return -1 for impossible cases, otherwise return the minimum coins needed
        return dp[numCoins][amount] > amount ? -1 : dp[numCoins][amount];
    }
};