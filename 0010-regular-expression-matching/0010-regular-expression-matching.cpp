class Solution {
public:
    bool isMatch(string s, string p) {
        int stringLength = s.size();
        int patternLength = p.size();
      
        // Memoization table: -1 = not computed, 0 = false, 1 = true
        // memo[i][j] represents if s[i:] matches p[j:]
        vector<vector<int>> memo(stringLength + 1, vector<int>(patternLength + 1, -1));
      
        // Recursive function to check if s[stringIdx:] matches p[patternIdx:]
        function<bool(int, int)> matchHelper = [&](int stringIdx, int patternIdx) -> bool {
            // Base case: if pattern is exhausted, string must also be exhausted
            if (patternIdx >= patternLength) {
                return stringIdx == stringLength;
            }
          
            // Check if result is already memoized
            if (memo[stringIdx][patternIdx] != -1) {
                return memo[stringIdx][patternIdx] == 1;
            }
          
            // Initialize result
            bool isMatchFound = false;
          
            // Check if next character in pattern is '*' (zero or more of preceding element)
            if (patternIdx + 1 < patternLength && p[patternIdx + 1] == '*') {
                // Two options with '*':
                // 1. Skip the current pattern char and '*' (match zero occurrences)
                // 2. If current chars match, use '*' to match one or more occurrences
                isMatchFound = matchHelper(stringIdx, patternIdx + 2) ||  // Match zero occurrences
                              (stringIdx < stringLength && 
                               (s[stringIdx] == p[patternIdx] || p[patternIdx] == '.') && 
                               matchHelper(stringIdx + 1, patternIdx));  // Match one or more occurrences
            }
            // No '*' follows current pattern character
            else {
                // Check if current characters match and continue matching rest
                isMatchFound = stringIdx < stringLength && 
                              (s[stringIdx] == p[patternIdx] || p[patternIdx] == '.') && 
                              matchHelper(stringIdx + 1, patternIdx + 1);
            }
          
            // Store result in memoization table
            memo[stringIdx][patternIdx] = isMatchFound ? 1 : 0;
          
            return isMatchFound;
        };
      
        // Start matching from the beginning of both strings
        return matchHelper(0, 0);
    }
};