class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
      
        // dp[i] represents the length of the longest valid parentheses ending at index i-1
        // We use 1-indexed dp array for easier calculation
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
      
        // Iterate through the string starting from index 2 (1-indexed)
        // because we need at least 2 characters to form a valid parentheses pair
        for (int i = 2; i <= n; ++i) {
            // Only closing parenthesis can end a valid sequence
            if (s[i - 1] == ')') {
                // Case 1: Current ')' matches with previous '(' to form "()"
                if (s[i - 2] == '(') {
                    // Add 2 to the valid length before the "()" pair
                    dp[i] = dp[i - 2] + 2;
                } 
                // Case 2: Current ')' might match with a '(' before a valid sequence
                // Pattern: "...(...)))" where middle part is already valid
                else {
                    // Find the index before the valid sequence ending at i-1
                    int matchIndex = i - dp[i - 1] - 1;
                  
                    // Check if there's a matching '(' at the calculated position
                    if (matchIndex > 0 && s[matchIndex - 1] == '(') {
                        // Current valid length = previous valid length + 2 (for the new pair)
                        // + any valid sequence before the matching '('
                        dp[i] = dp[i - 1] + 2 + dp[matchIndex - 1];
                    }
                }
            }
        }
      
        // Return the maximum value in the dp array
        return *max_element(dp, dp + n + 1);
    }
};
