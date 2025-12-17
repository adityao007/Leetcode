class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
      
        // Base case: only one house
        if (n == 1) {
            return nums[0];
        }
      
        // For circular arrangement, we have two scenarios:
        // 1. Rob houses from index 0 to n-2 (exclude last house)
        // 2. Rob houses from index 1 to n-1 (exclude first house)
        // Return the maximum of both scenarios
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }

private:
    int robRange(vector<int>& nums, int start, int end) {
        // Dynamic programming approach using two variables
        // prevMax: maximum money robbed up to the previous house
        // currMax: maximum money robbed up to the current house
        int prevMax = 0;
        int currMax = 0;
      
        // Iterate through the specified range of houses
        for (int i = start; i <= end; ++i) {
            // Calculate new maximum for current position
            // Either skip current house (take prevMax) or rob current house (prevMax + nums[i])
            int tempMax = max(prevMax, currMax);
            currMax = prevMax + nums[i];
            prevMax = tempMax;
        }
      
        // Return the maximum money that can be robbed
        return max(prevMax, currMax);
    }
};