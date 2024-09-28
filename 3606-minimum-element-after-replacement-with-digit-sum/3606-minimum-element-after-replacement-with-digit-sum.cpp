class Solution {
public:
    int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum; 
}
    int minElement(vector<int>& nums) {
        int minimum = INT_MAX; 

        for (int i = 0; i < nums.size(); i++) {
            int digitSum=sumOfDigits(nums[i]);
            minimum=min(digitSum,minimum);
        }
        cout<<minimum;
        return minimum;
    }
};