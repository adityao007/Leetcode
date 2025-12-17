class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int wordCount = words.size();
      
        for (int i = 0; i < wordCount;) {
            // Collect words that can fit in the current line
            vector<string> currentLineWords = {words[i]};
            int currentLineLength = words[i].size();
            i++;
          
            // Keep adding words while they fit within maxWidth (including minimum spaces)
            while (i < wordCount && currentLineLength + 1 + words[i].size() <= maxWidth) {
                currentLineLength += 1 + words[i].size();
                currentLineWords.push_back(words[i]);
                i++;
            }
          
            // Handle last line or single word line (left-justified)
            if (i == wordCount || currentLineWords.size() == 1) {
                string leftJustifiedLine = currentLineWords[0];
                for (int j = 1; j < currentLineWords.size(); j++) {
                    leftJustifiedLine += " " + currentLineWords[j];
                }
                // Pad with spaces on the right to reach maxWidth
                string rightPadding(maxWidth - leftJustifiedLine.size(), ' ');
                result.push_back(leftJustifiedLine + rightPadding);
                continue;
            }
          
            // Calculate space distribution for fully justified line
            // Total characters used by words (excluding spaces between them)
            int totalWordChars = currentLineLength - (currentLineWords.size() - 1);
            // Total spaces to distribute
            int totalSpaces = maxWidth - totalWordChars;
            // Base spaces between each word pair
            int baseSpaces = totalSpaces / (currentLineWords.size() - 1);
            // Extra spaces to distribute from left to right
            int extraSpaces = totalSpaces % (currentLineWords.size() - 1);
          
            // Build the fully justified line
            string justifiedLine;
            for (int j = 0; j < currentLineWords.size() - 1; j++) {
                justifiedLine += currentLineWords[j];
                // Add base spaces plus one extra if within the first 'extraSpaces' gaps
                int spacesToAdd = baseSpaces + (j < extraSpaces ? 1 : 0);
                justifiedLine += string(spacesToAdd, ' ');
            }
            // Add the last word without trailing spaces
            justifiedLine += currentLineWords.back();
          
            result.push_back(justifiedLine);
        }
      
        return result;
    }
};