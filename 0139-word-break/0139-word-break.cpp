class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Convert word dictionary to hash set for O(1) lookup
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
      
        int n = s.size();
      
        // dp[i] represents whether substring s[0...i-1] can be segmented into dictionary words
        // dp[0] = true means empty string can always be segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true;
      
        // Iterate through each position in the string
        for (int i = 1; i <= n; ++i) {
            // Check all possible split positions before index i
            for (int j = 0; j < i; ++j) {
                // If s[0...j-1] can be segmented (dp[j] is true)
                // AND s[j...i-1] exists in the dictionary
                // Then s[0...i-1] can also be segmented
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;  // No need to check other split positions
                }
            }
        }
      
        // Return whether the entire string can be segmented
        return dp[n];
    }
};
