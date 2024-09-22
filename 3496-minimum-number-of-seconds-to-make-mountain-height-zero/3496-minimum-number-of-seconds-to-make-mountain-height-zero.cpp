class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto canFinishInTime = [&](long long t) {
            long long total_height_reduced = 0;
            for (int wt : workerTimes) {
                long long height_by_worker = 0;
                long long time_spent = 0;
                long long x = 1; 
                
                while (time_spent + wt * x <= t) {
                    time_spent += wt * x;
                    height_by_worker += 1;
                    x++;
                }
                total_height_reduced += height_by_worker;
                if (total_height_reduced >= mountainHeight) {
                    return true;
                }
            }
            return total_height_reduced >= mountainHeight;
        };

        long long left = 1;
        long long right = static_cast<long long>(mountainHeight) * (mountainHeight + 1) / 2 * *max_element(workerTimes.begin(), workerTimes.end());
        
        while (left < right) {
            long long mid = (left + right) / 2;
            if (canFinishInTime(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
