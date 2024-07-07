class Solution {
public:
    string getEncryptedString(string s, int k) {
        string encrypted_string;
    int n = s.length();
    
    for (int i = 0; i < n; ++i) {
        int new_index = (i + k) % n;
        encrypted_string += s[new_index];
    }

    return encrypted_string;
    }
};