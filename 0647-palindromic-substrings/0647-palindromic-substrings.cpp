class Solution {
public:
    int countSubstrings(string s) {
        int palindromeCount = 0;
        int stringLength = s.size();
      
        // Iterate through all possible palindrome centers (2n - 1 total)
        // This includes n single characters and n-1 positions between characters
        for (int centerIndex = 0; centerIndex < stringLength * 2 - 1; ++centerIndex) {
            // Calculate left and right pointers based on center index
            // For even centerIndex (0, 2, 4...): represents single character center
            //   - left = centerIndex / 2, right = (centerIndex + 1) / 2 (same position)
            // For odd centerIndex (1, 3, 5...): represents position between two characters
            //   - left = centerIndex / 2, right = (centerIndex + 1) / 2 (adjacent positions)
            int left = centerIndex / 2;
            int right = (centerIndex + 1) / 2;
          
            // Expand around the center while characters match
            // ~left is equivalent to left >= 0 (bitwise NOT of -1 is 0)
            while (left >= 0 && right < stringLength && s[left] == s[right]) {
                // Found a palindrome substring from s[left] to s[right]
                ++palindromeCount;
              
                // Expand the window
                --left;
                ++right;
            }
        }
      
        return palindromeCount;
    }
};
