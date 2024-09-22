class Solution {
public:
    long long validSubstringCount(std::string source, std::string target) {
        int sourceLength = source.length();
        int targetLength = target.length();

        if (targetLength > sourceLength) return 0;

        std::unordered_map<char, int> sourceCharCount;
        std::unordered_map<char, int> targetCharCount;
        
        for (char c : target) {
            targetCharCount[c]++;
        }

        long long validSubstringCount = 0;
        int requiredUniqueChars = targetCharCount.size();
        int formedUniqueChars = 0;
        int leftPointer = 0;

        for (int rightPointer = 0; rightPointer < sourceLength; rightPointer++) {
            char currentChar = source[rightPointer];
            sourceCharCount[currentChar]++;

            if (targetCharCount.count(currentChar) && sourceCharCount[currentChar] == targetCharCount[currentChar]) {
                formedUniqueChars++;
            }
            
            while (formedUniqueChars == requiredUniqueChars) {
                validSubstringCount += sourceLength - rightPointer;

                char leftChar = source[leftPointer];
                sourceCharCount[leftChar]--;
                
                if (targetCharCount.count(leftChar) && sourceCharCount[leftChar] < targetCharCount[leftChar]) {
                    formedUniqueChars--;
                }
                leftPointer++;
            }
        }
        return validSubstringCount; 
    }
};