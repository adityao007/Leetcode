class Solution {
public:
    int lengthOfLastWord(string s) {
        // Start from the end of the string
        int endIndex = s.size() - 1;
      
        // Skip trailing spaces from the end
        while (endIndex >= 0 && s[endIndex] == ' ') {
            --endIndex;
        }
      
        // Mark the end position of the last word
        int startIndex = endIndex;
      
        // Move backwards to find the start of the last word
        while (startIndex >= 0 && s[startIndex] != ' ') {
            --startIndex;
        }
      
        // Calculate and return the length of the last word
        // startIndex points to space before word or -1, endIndex points to last char of word
        return endIndex - startIndex;
    }
};
