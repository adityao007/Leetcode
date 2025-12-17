class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // Count frequency of each word in the words array
        unordered_map<string, int> wordCount;
        for (const auto& word : words) {
            wordCount[word]++;
        }

        vector<int> result;
        int stringLength = s.length();
        int wordArraySize = words.size();
        int wordLength = words[0].length();

        // Try starting from each possible offset (0 to wordLength-1)
        // This ensures we check all possible alignments
        for (int offset = 0; offset < wordLength; ++offset) {
            int left = offset;
            int right = offset;
            unordered_map<string, int> currentWindowCount;
          
            // Slide the window through the string
            while (right + wordLength <= stringLength) {
                // Extract the next word from position right
                string currentWord = s.substr(right, wordLength);
                right += wordLength;

                // If current word is not in our target words, reset the window
                if (!wordCount.contains(currentWord)) {
                    currentWindowCount.clear();
                    left = right;
                    continue;
                }

                // Add current word to our window
                currentWindowCount[currentWord]++;

                // Shrink window from left while we have excess of any word
                while (currentWindowCount[currentWord] > wordCount[currentWord]) {
                    string leftWord = s.substr(left, wordLength);
                    currentWindowCount[leftWord]--;
                  
                    // Remove from map if count becomes zero to keep map clean
                    if (currentWindowCount[leftWord] == 0) {
                        currentWindowCount.erase(leftWord);
                    }
                    left += wordLength;
                }

                // Check if current window size matches the total length of all words
                // If yes, we found a valid starting position
                if (right - left == wordArraySize * wordLength) {
                    result.push_back(left);
                }
            }
        }

        return result;
    }
};