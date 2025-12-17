class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
      
        // dp[i][j] represents the minimum edit distance between 
        // the first i characters of word1 and the first j characters of word2
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
      
        // Initialize base case: converting empty string to word2[0...j-1]
        // requires j insertions
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
      
        // Fill the dp table
        for (int i = 1; i <= m; ++i) {
            // Base case: converting word1[0...i-1] to empty string
            // requires i deletions
            dp[i][0] = i;
          
            for (int j = 1; j <= n; ++j) {
                // If characters match, no operation needed
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                // Otherwise, take minimum of three operations:
                // 1. dp[i - 1][j] + 1: delete from word1
                // 2. dp[i][j - 1] + 1: insert into word1
                // 3. dp[i - 1][j - 1] + 1: replace character in word1
                else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
            }
        }
      
        // Return the edit distance between word1 and word2
        return dp[m][n];
    }
};