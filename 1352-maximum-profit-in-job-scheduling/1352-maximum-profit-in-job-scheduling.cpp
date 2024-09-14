class Solution {
public:
    static bool compare(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.first < b.first;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<int, pair<int, int>>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({endTime[i], {startTime[i], profit[i]}});
        }

        sort(jobs.begin(), jobs.end(), compare);

        vector<int> dp(n, 0);
        dp[0] = jobs[0].second.second;

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
        
        for (int i = 1; i < n; i++) {
            int includeProfit = jobs[i].second.second;
            int lastNonConflictingJob = findLastNonConflictingJob(i);
            if (lastNonConflictingJob != -1) {
                includeProfit += dp[lastNonConflictingJob];
            }

            dp[i] = max(dp[i - 1], includeProfit);
        }

        return dp[n - 1];
    }
};
