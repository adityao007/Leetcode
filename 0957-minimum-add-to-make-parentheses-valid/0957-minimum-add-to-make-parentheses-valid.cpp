class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>sa;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(s[i]=='('){
                sa.push(ch);
            }
            else{
                if(!sa.empty() && sa.top()=='('){
                    sa.pop();
                }
                else{
                    sa.push(ch);
                }
            }
        }
        return sa.size();
    }
};