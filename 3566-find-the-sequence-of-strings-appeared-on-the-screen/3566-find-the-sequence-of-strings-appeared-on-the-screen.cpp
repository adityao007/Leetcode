class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> annss;
        string ccrrr = "";

        for (char ch : target) {
            ccrrr += 'a';
            annss.push_back(ccrrr);

            while (ccrrr.back() != ch) {
                ccrrr.back()++;
                annss.push_back(ccrrr);
            }
        }

        return annss;
    }
};