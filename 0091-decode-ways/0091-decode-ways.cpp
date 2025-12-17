class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
      
        // dp[i] represents the number of ways to decode s[0...i-1]
        // dp[0] represents empty string (base case)
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
      
        // Empty string has one way to decode
        dp[0] = 1;
      
        // Iterate through each position in the string
        for (int i = 1; i <= n; ++i) {
            // Single digit decode: Check if current digit is valid (1-9)
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }
          
            // Two digit decode: Check if previous two digits form a valid number (10-26)
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
                dp[i] += dp[i - 2];
            }
        }
      
        // Return the number of ways to decode the entire string
        return dp[n];
    }
};