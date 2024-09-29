class Solution {
public:
    char kthCharacter(int k) {
        string currentWord = "a";
        while (currentWord.length() < k) {
            string newWord = "";
                for (char ch : currentWord) {
                    newWord += (ch == 'z') ? 'a' : ch + 1;
                }
            currentWord += newWord;
        }
        return currentWord[k - 1];
    }
};