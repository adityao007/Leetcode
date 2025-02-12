class Solution {
private:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        int maxsum = -1;
        vector<int> maxNum(82, -1);

        for (int i=0;i<nums.size();i++) {
            int sum = digitSum(nums[i]);

            if (maxNum[sum] != -1) {
                maxsum = max(maxsum, nums[i] + maxNum[sum]);
            }

            maxNum[sum] = max(maxNum[sum], nums[i]); 
        }

        return maxsum;
    }
};