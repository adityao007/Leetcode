class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        vector<string> words;
        
        while(iss>>word){
            words.push_back(word);
            
        } 
        reverse(words.begin(), words.end());
        ostringstream oss;

        for (size_t i = 0; i < words.size(); ++i) {
        if (i != 0) {
            oss << " "; // Add a space between words
        }
        oss << words[i];
    }

    return oss.str();
    }
};