class Solution {
public:
    string removeOccurrences(string s, string part){
        string result;
        for(int i=0; i<s.length(); i++){
            result.push_back(s[i]);

            if(result.size()>=part.size() && result.substr(result.size()-part.size())==part){
                result.erase(result.size()-part.size());
            }
        }
        return result;
    }
};