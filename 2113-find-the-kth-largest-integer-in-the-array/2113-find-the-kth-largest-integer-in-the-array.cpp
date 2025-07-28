class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = sizeof(nums) / sizeof(nums[0]);
        sort(nums.begin(), nums.end(), [](const string &a, const string &b) {
        if (a.size() != b.size()) {
            return a.size() > b.size(); // Compare by length first
        }
            return a > b; // Compare lexicographically
        });

        return nums[k-1];
    }
};