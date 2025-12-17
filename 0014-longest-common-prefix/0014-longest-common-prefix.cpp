
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Get the number of strings in the array
        int numStrings = strs.size();
      
        // Iterate through each character position of the first string
        for (int charIndex = 0; charIndex < strs[0].size(); ++charIndex) {
            // Compare this character position across all other strings
            for (int stringIndex = 1; stringIndex < numStrings; ++stringIndex) {
                // Check if current string is shorter than current position
                // or if the character at this position doesn't match the first string
                if (strs[stringIndex].size() <= charIndex || 
                    strs[stringIndex][charIndex] != strs[0][charIndex]) {
                    // Return the common prefix found so far
                    return strs[0].substr(0, charIndex);
                }
            }
        }
      
        // If we've checked all characters of the first string without mismatch,
        // the entire first string is the common prefix
        return strs[0];
    }
};