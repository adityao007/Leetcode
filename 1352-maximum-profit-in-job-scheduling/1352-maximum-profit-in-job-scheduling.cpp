class Solution {
public:
    // Helper function to compare jobs by their end times
    static bool compare(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.first < b.first;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<int, pair<int, int>>> jobs;
        
        // Combine startTime, endTime, and profit into a single list of jobs
        for (int i = 0; i < n; i++) {
            jobs.push_back({endTime[i], {startTime[i], profit[i]}});
        }
        
        // Sort jobs by end time
        sort(jobs.begin(), jobs.end(), compare);
        
        // DP array to store maximum profit until the current job
        vector<int> dp(n, 0);
        dp[0] = jobs[0].second.second; // Profit of the first job
        
        // Binary search helper to find the latest job that doesn't overlap
        auto findLastNonConflictingJob = [&](int index) {
            int low = 0, high = index - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (jobs[mid].first <= jobs[index].second.first) {
                    if (jobs[mid + 1].first <= jobs[index].second.first) {
                        low = mid + 1;
                    } else {
                        return mid;
                    }
                } else {
                    high = mid - 1;
                }
            }
            return -1;
        };
        
        // Fill the DP array
        for (int i = 1; i < n; i++) {
            // Option 1: Exclude the current job
            int includeProfit = jobs[i].second.second;
            int lastNonConflictingJob = findLastNonConflictingJob(i);
            if (lastNonConflictingJob != -1) {
                includeProfit += dp[lastNonConflictingJob];
            }
            
            // Option 2: Include the current job
            dp[i] = max(dp[i - 1], includeProfit);
        }
        
        // The answer is the maximum profit we can achieve considering all jobs
        return dp[n - 1];
    }
};
