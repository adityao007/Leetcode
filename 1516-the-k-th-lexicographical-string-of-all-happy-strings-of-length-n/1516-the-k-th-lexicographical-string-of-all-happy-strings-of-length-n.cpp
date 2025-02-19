class Solution {
public:
    void generateHappyString(int n, int k, string current, string &result, int &count) {
        if (current.size() == n) {
            count++;
            if (count == k) {
                result = current;
            }
            return;
        }
        
        for (char ch : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != ch) {
                generateHappyString(n, k, current + ch, result, count);
                if (!result.empty()) return;  // Stop early if found
            }
        }
    }
    string getHappyString(int n, int k) {
        string ans;
        int count = 0;
        generateHappyString(n, k, "", ans, count);
        return ans;
    }

};