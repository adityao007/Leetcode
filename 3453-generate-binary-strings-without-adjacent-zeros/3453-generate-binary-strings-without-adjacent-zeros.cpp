class Solution {
public:
void generateValidStrings(std::string current, int n, std::vector<std::string>& result) {
    if (current.length() == n) {
        result.push_back(current);
        return;
    }

    if (current.length() == 0 || current.back() == '1') {
        generateValidStrings(current + '0', n, result);
    }
    generateValidStrings(current + '1', n, result);
}
    vector<string> validStrings(int n) {
        std::vector<std::string> result;
    generateValidStrings("", n, result);
    return result;
    }
};