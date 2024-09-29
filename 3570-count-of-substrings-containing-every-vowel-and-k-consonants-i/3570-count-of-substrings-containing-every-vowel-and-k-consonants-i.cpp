class Solution {
public:
    bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
    int countOfSubstrings(string word, int k) {
        int totalCount = 0;
    unordered_map<char, int> vowelFreq;
    int consonantFreq = 0;
    int start = 0;

    for (int end = 0; end < word.size(); ++end) {
        char endChar = word[end];

        if (isVowel(endChar)) {
            vowelFreq[endChar]++;
        } else {
            consonantFreq++;
        }

        while (consonantFreq > k) {
            char startChar = word[start];
            if (isVowel(startChar)) {
                vowelFreq[startChar]--;
                if (vowelFreq[startChar] == 0) {
                    vowelFreq.erase(startChar);
                }
            } else {
                consonantFreq--;
            }
            start++;
        }

        if (vowelFreq.size() == 5 && consonantFreq == k) {
            int tempStart = start;
            while (tempStart <= end && vowelFreq.size() == 5 && consonantFreq == k) {
                totalCount++;
                if (isVowel(word[tempStart])) {
                    vowelFreq[word[tempStart]]--;
                    if (vowelFreq[word[tempStart]] == 0) {
                        vowelFreq.erase(word[tempStart]);
                    }
                } else {
                    consonantFreq--;
                }
                tempStart++;
            }

            while (tempStart > start) {
                tempStart--;
                if (isVowel(word[tempStart])) {
                    vowelFreq[word[tempStart]]++;
                } else {
                    consonantFreq++;
                }
            }
        }
    }

    return totalCount;
    }
};