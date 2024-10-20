class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.length();
        int totalCount = 0;
    
    for (int start = 0; start < n; start++) {
        unordered_map<char, int> freqMap;
        
        for (int end = start; end < n; ++end) {
            freqMap[s[end]]++;
            
            bool valid = false;
            for (auto& [ch, freq] : freqMap) {
                if (freq >= k) {
                    valid = true;
                    break;
                }
            }
            
            if (valid) {
                totalCount++;
            }
        }
    }
    
    return totalCount;
    }
};