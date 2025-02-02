class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int openCount = 0;

        for (char c : s) {
            if (c == '(') {
                if (openCount > 0)  // Avoid adding outermost '('
                    result += c;
                openCount++;
            } else { // c == ')'
                openCount--;
                if (openCount > 0)  // Avoid adding outermost ')'
                    result += c;
            }
        }
        return result;
    }
};