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
        vector<int> maxnum(82, -1);

        for (int i=0;i<nums.size();i++) {
            int sum = digitSum(nums[i]);

            if (maxnum[sum] != -1) {
                maxsum = max(maxsum, nums[i] + maxnum[sum]);
            }
            maxnum[sum] = max(maxnum[sum], nums[i]); 
        }

        return maxsum;
    }
};