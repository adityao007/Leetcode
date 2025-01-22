class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] > 0) {
                positive.push_back(nums[i]);
            } else {
                negative.push_back(nums[i]);
            }
        }
        vector<int> result(nums.size());
        int posIndex = 0, negIndex = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                result[i] = positive[posIndex++];
            } else {
                result[i] = negative[negIndex++];
            }
        }

        return result;
    }
};