class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
      
        // Create a 2D DP table where dp[i][j] represents the length of LCS
        // of text1[0...i-1] and text2[0...j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
      
        // Build the DP table bottom-up
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // If characters match, extend the LCS from the previous state
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } 
                // If characters don't match, take the maximum LCS from either
                // excluding current character from text1 or text2
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
      
        // Return the LCS length of the entire strings
        return dp[m][n];
    }
};
