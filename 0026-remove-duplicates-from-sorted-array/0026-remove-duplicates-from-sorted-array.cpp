class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    set <int> set;
        for (int i = 0; i < nums.size(); i++) {
            set.insert(nums[i]);
        }
        int k = set.size();
        int j = 0;
        for (int x: set) {
            nums[j++] = x;
        }
        return k;
    }
};