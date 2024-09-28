class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index=word.find(ch);
        if (index == string::npos) {
            return word;
        }
        string result = word;
        for (int i = 0; i <= index / 2; ++i) {
            swap(result[i], result[index - i]);
        }
        return result;
    }
};