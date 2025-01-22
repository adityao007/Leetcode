class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        
        // Phase 1: Find a candidate for the majority element
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        
        // Phase 2: Verify the candidate (optional if the problem guarantees a majority element)
        count = 0;
        for (int num : nums) {
            if (num == candidate) {
                count++;
            }
        }
        
        return (count > nums.size() / 2) ? candidate : -1;
    }
};