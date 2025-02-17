class Solution {
public:
void backtrack(unordered_map<char, int>& freq, int& count) {
    for (auto& [ch, val] : freq) {
        if (val > 0) {
            freq[ch]--;  // Use this tile
            count++;     // Count this sequence
            backtrack(freq, count);  // Recurse
            freq[ch]++;  // Backtrack
        }
    }
}
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
    for (char ch : tiles) freq[ch]++;  // Count character frequencies
    
    int count = 0;
    backtrack(freq, count);
    return count;
    }
};