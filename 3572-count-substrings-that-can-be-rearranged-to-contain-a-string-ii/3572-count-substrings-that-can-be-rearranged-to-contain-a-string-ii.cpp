class Solution {
public:
    long long validSubstringCount(std::string word1, std::string word2) {
        int length1 = word1.length();
        int length2 = word2.length();

        if (length2 > length1) return 0;

        std::unordered_map<char, int> charCount1;
        std::unordered_map<char, int> charCount2;
        
        // Populate the frequency map for word2
        for (char c : word2) {
            charCount2[c]++;
        }

        long long validSubstringCount = 0;
        int requiredChars = charCount2.size();
        int formedChars = 0;
        int leftPointer = 0;

        for (int rightPointer = 0; rightPointer < length1; rightPointer++) {
            char currentChar = word1[rightPointer];
            charCount1[currentChar]++;

            // Check if the current character matches the required count
            if (charCount2.count(currentChar) && charCount1[currentChar] == charCount2[currentChar]) {
                formedChars++;
            }
            
            // When all required characters are formed, count valid substrings
            while (formedChars == requiredChars) {
                validSubstringCount += length1 - rightPointer;

                char leftChar = word1[leftPointer];
                charCount1[leftChar]--;
                
                // Check if we need to decrease the formed character count
                if (charCount2.count(leftChar) && charCount1[leftChar] < charCount2[leftChar]) {
                    formedChars--;
                }
                leftPointer++;
            }
        }
        return validSubstringCount; 
    }
};
