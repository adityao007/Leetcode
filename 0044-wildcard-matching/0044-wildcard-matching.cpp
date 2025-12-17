class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
      
        // Create memoization table: dp[i][j] represents if s[i..] matches p[j..]
        // -1: not computed, 0: false, 1: true
        int dp[sLen + 1][pLen + 1];
        memset(dp, -1, sizeof(dp));
      
        // Define recursive function with memoization
        function<bool(int, int)> dfs = [&](int sIdx, int pIdx) -> bool {
            // Base case 1: Reached end of string s
            if (sIdx >= sLen) {
                // Either pattern is also finished, or current pattern char is '*' 
                // which can match empty sequence
                return pIdx >= pLen || (p[pIdx] == '*' && dfs(sIdx, pIdx + 1));
            }
          
            // Base case 2: Pattern exhausted but string still has characters
            if (pIdx >= pLen) {
                return false;
            }
          
            // Check memoization table
            if (dp[sIdx][pIdx] != -1) {
                return dp[sIdx][pIdx] == 1;
            }
          
            // Process current pattern character
            if (p[pIdx] == '*') {
                // '*' can match:
                // 1. One or more characters: dfs(sIdx + 1, pIdx)
                // 2. Zero characters: dfs(sIdx, pIdx + 1)
                dp[sIdx][pIdx] = (dfs(sIdx + 1, pIdx) || dfs(sIdx, pIdx + 1)) ? 1 : 0;
            } else {
                // '?' matches any single character, or characters must match exactly
                // Then move both pointers forward
                dp[sIdx][pIdx] = ((p[pIdx] == '?' || s[sIdx] == p[pIdx]) && 
                                  dfs(sIdx + 1, pIdx + 1)) ? 1 : 0;
            }
          
            return dp[sIdx][pIdx] == 1;
        };
      
        // Start matching from beginning of both strings
        return dfs(0, 0);
    }
};