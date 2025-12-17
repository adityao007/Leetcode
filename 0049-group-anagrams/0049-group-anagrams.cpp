class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Hash map to store sorted string as key and list of anagrams as value
        unordered_map<string, vector<string>> anagramGroups;
      
        // Iterate through each string in the input array
        for (const auto& str : strs) {
            // Create a copy of the current string to use as key
            string sortedKey = str;
          
            // Sort the characters to create a unique key for all anagrams
            sort(sortedKey.begin(), sortedKey.end());
          
            // Add the original string to the corresponding anagram group
            anagramGroups[sortedKey].emplace_back(str);
        }
      
        // Result vector to store all groups of anagrams
        vector<vector<string>> result;
      
        // Extract all anagram groups from the hash map
        for (auto& [key, group] : anagramGroups) {
            result.emplace_back(group);
        }
      
        return result;
    }
};