class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result;
        int partLength=part.length();
        for(int i=0;i<s.length();i++){
            result.push_back(s[i]);

            if(result.size() >= partLength && result.compare(result.size() - partLength, partLength, part)==0){
                result.erase(result.size() - partLength);
            }
        }
        return result;
    }
};