class Solution {
public:
    string removeOccurrences(string s, string part){
        string ans;

        for(int i=0; i<s.length(); i++)
        {
            ans.push_back(s[i]);

            if(ans.size()>=part.size() && ans.substr(ans.size()-part.size())==part){
                ans.erase(ans.size()-part.size());
            }
        }
        return ans;
    }
};