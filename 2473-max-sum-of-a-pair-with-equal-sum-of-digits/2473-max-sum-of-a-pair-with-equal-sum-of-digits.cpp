class Solution {
private:
    // Function to compute sum of digits
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
        vector<int> maxNum(82, -1); // Stores the largest number for each digit sum

        for (int num : nums) {
            int sum = digitSum(num);

            if (maxNum[sum] != -1) {  // If a number with this sum exists
                maxsum = max(maxsum, num + maxNum[sum]);
            }

            maxNum[sum] = max(maxNum[sum], num);  // Store the max number for this sum
        }

        return maxsum;
    }
};