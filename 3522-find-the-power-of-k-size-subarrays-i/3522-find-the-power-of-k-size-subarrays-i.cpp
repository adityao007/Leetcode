class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> results;
    
    for (int i = 0; i <= nums.size() - k; ++i) {
        // Extract the subarray from index i to i+k-1
        bool isConsecutive = true;
        
        // Check if the subarray is sorted in ascending order and has consecutive elements
        for (int j = i; j < i + k - 1; ++j) {
            if (nums[j] + 1 != nums[j + 1]) {
                isConsecutive = false;
                break;
            }
        }
        
        // If the subarray is sorted and consecutive, find its maximum
        if (isConsecutive) {
            int maxElement = *max_element(nums.begin() + i, nums.begin() + i + k);
            results.push_back(maxElement);
        } else {
            results.push_back(-1);
        }
    }
    
    return results;

    }
};