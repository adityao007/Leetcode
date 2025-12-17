class Solution {
private:
    // Build the failure function (partial match table) for KMP algorithm
    // The failure function tells us where to continue matching after a mismatch
    vector<int> buildFailureFunction(const string& pattern) {
        int patternLength = pattern.length();
        vector<int> failureTable(patternLength);
      
        // First character always has failure value of -1
        failureTable[0] = -1;
      
        int currentIndex = 0;
        int prefixIndex = -1;
      
        // Build the failure table by comparing pattern with itself
        while (currentIndex < patternLength) {
            // If there's a mismatch, backtrack using the failure table
            while (prefixIndex >= 0 && pattern[currentIndex] != pattern[prefixIndex]) {
                prefixIndex = failureTable[prefixIndex];
            }
          
            currentIndex++;
            prefixIndex++;
          
            // Prevent out of bounds access
            if (currentIndex >= patternLength) {
                break;
            }
          
            // Optimization: if next characters match, we can skip further
            if (pattern[currentIndex] == pattern[prefixIndex]) {
                failureTable[currentIndex] = failureTable[prefixIndex];
            } else {
                failureTable[currentIndex] = prefixIndex;
            }
        }
      
        return failureTable;
    }

public:
    // Find the first occurrence of needle in haystack using KMP algorithm
    // Returns the index of first occurrence, or -1 if not found
    int strStr(string haystack, string needle) {
        // Empty needle matches at position 0
        if (needle.length() == 0) {
            return 0;
        }
      
        // Build the failure function for the pattern (needle)
        vector<int> failureTable = buildFailureFunction(needle);
      
        // Calculate the maximum starting position for a potential match
        int maxStartPosition = haystack.length() - needle.length() + 1;
      
        // Try each possible starting position
        for (int startPos = 0; startPos < maxStartPosition; startPos++) {
            int patternIndex = 0;  // Current position in needle
            int textIndex = startPos;  // Current position in haystack
          
            // Match characters one by one
            while (patternIndex < needle.length() && textIndex < haystack.length()) {
                // If characters don't match
                if (haystack[textIndex] != needle[patternIndex]) {
                    // Use failure function to skip unnecessary comparisons
                    if (failureTable[patternIndex] >= 0) {
                        patternIndex = failureTable[patternIndex];
                        continue;  // Retry with new pattern position
                    } else {
                        break;  // No more backtracking possible, try next start position
                    }
                }
              
                // Characters match, move both pointers forward
                textIndex++;
                patternIndex++;
            }
          
            // Check if we found a complete match
            if (patternIndex >= needle.length()) {
                return textIndex - patternIndex;  // Return starting index of match
            }
        }
      
        // No match found
        return -1;
    }
};