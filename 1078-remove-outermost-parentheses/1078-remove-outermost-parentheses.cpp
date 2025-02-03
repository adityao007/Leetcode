class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int openCount = 0;

        for (char c : s) {
            if (c == '(') {
                if (openCount > 0) 
                    result += c;
                openCount++;
            } else {
                openCount--;
                if (openCount > 0)
                    result += c;
            }
        }
        return result;
    }
};