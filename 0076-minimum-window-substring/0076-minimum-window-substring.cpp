class Solution {
public:
    string minWindow(string s, string t) {
        // Frequency map for characters needed from string t
        vector<int> targetFreq(128, 0);
        // Frequency map for characters in current window
        vector<int> windowFreq(128, 0);
      
        // Count frequency of each character in t
        for (char c : t) {
            targetFreq[c]++;
        }

        int sLen = s.length();
        int tLen = t.length();
      
        // Variables to track the minimum window
        int minStart = -1;  // Starting index of minimum window
        int minLength = sLen + 1;  // Length of minimum window
        int validCharCount = 0;  // Count of characters from t that are satisfied in current window

        // Sliding window with two pointers
        int left = 0;
        for (int right = 0; right < sLen; right++) {
            // Expand window by including character at right pointer
            char rightChar = s[right];
            windowFreq[rightChar]++;
          
            // If this character contributes to satisfying the requirement
            if (windowFreq[rightChar] <= targetFreq[rightChar]) {
                validCharCount++;
            }

            // Contract window from left while it still contains all characters from t
            while (validCharCount == tLen) {
                // Update minimum window if current window is smaller
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minStart = left;
                }

                // Try to shrink window from left
                char leftChar = s[left];
              
                // If removing this character breaks the valid window
                if (windowFreq[leftChar] <= targetFreq[leftChar]) {
                    validCharCount--;
                }
              
                windowFreq[leftChar]--;
                left++;
            }
        }

        // Return empty string if no valid window found, otherwise return the minimum window
        return minStart == -1 ? "" : s.substr(minStart, minLength);
    }
};
