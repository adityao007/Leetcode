class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Return empty vector if input is empty
        if (digits.empty()) {
            return {};
        }
      
        // Mapping of digits to corresponding letters (2-9)
        // Index 0 corresponds to digit '2', index 1 to digit '3', etc.
        vector<string> digitToLetters = {
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
      
        // Initialize result with empty string to build upon
        vector<string> result = {""};
      
        // Process each digit in the input string
        for (char digit : digits) {
            // Get the corresponding letters for current digit
            string letters = digitToLetters[digit - '2'];
          
            // Temporary vector to store new combinations
            vector<string> newCombinations;
          
            // For each existing combination in result
            for (const string& existingCombination : result) {
                // Append each possible letter to create new combinations
                for (char letter : letters) {
                    newCombinations.push_back(existingCombination + letter);
                }
            }
          
            // Replace result with the new combinations
            result = move(newCombinations);
        }
      
        return result;
    }
};