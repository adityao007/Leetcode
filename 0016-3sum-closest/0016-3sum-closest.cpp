class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort the array to enable two-pointer technique
        sort(nums.begin(), nums.end());
      
        // Initialize closest sum with a large value (2^30)
        int closestSum = 1 << 30;
        int n = nums.size();
      
        // Fix the first element and use two pointers for the remaining elements
        for (int i = 0; i < n; ++i) {
            // Initialize two pointers: left pointer starts after i, right pointer at the end
            int left = i + 1;
            int right = n - 1;
          
            // Use two-pointer technique to find the closest sum
            while (left < right) {
                // Calculate current sum of three elements
                int currentSum = nums[i] + nums[left] + nums[right];
              
                // If we found exact target, return immediately
                if (currentSum == target) {
                    return currentSum;
                }
              
                // Update closest sum if current sum is closer to target
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }
              
                // Move pointers based on comparison with target
                if (currentSum > target) {
                    // If sum is too large, move right pointer left to decrease sum
                    --right;
                } else {
                    // If sum is too small, move left pointer right to increase sum
                    ++left;
                }
            }
        }
      
        return closestSum;
    }
};
