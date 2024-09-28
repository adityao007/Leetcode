class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end());
        
        // Initialize current height as the last (largest) value in the sorted array
        long long currentHeight = maximumHeight[maximumHeight.size() - 1];
        long long totalHeight = 0;

        // Traverse the array from the largest to the smallest element
        for (int i = maximumHeight.size() - 1; i >= 0; --i) {
            // Ensure current height doesn't exceed maximum height of the current tower
            currentHeight = min(currentHeight, (long long)maximumHeight[i]);

            // If the height goes below or equal to 0, return -1 as it's not valid
            if (currentHeight <= 0) {
                return -1;
            }

            // Add the current valid height to the total sum
            totalHeight += currentHeight;

            // Decrease the height for the next tower
            currentHeight--;
        }

        // Return the total sum of all assigned heights
        return totalHeight;
    }
};