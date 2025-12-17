class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals by their end points in ascending order
        // This greedy approach helps us keep intervals that end earlier
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
      
        // Initialize count of intervals to remove (start with total count)
        int intervalsToRemove = intervals.size();
      
        // Track the end point of the last non-overlapping interval
        int previousEnd = INT_MIN;
      
        // Iterate through sorted intervals
        for (const auto& interval : intervals) {
            int currentStart = interval[0];
            int currentEnd = interval[1];
          
            // If current interval doesn't overlap with previous one
            if (previousEnd <= currentStart) {
                // Keep this interval (decrement removal count)
                intervalsToRemove--;
                // Update the end point for next comparison
                previousEnd = currentEnd;
            }
            // If intervals overlap, skip current interval (keep removal count)
        }
      
        return intervalsToRemove;
    }
};
