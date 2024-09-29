class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> result;

        for (int i = 0; i < k; i++) {
            pq.push(make_pair(nums[i], i));
        }

        result.push_back(pq.top().first);

        for (int i = k; i < nums.size(); i++) {
            while (!pq.empty() && pq.top().second <= (i - k)) {
                pq.pop();
            }

            pq.push(make_pair(nums[i], i));

            result.push_back(pq.top().first);
        }
        return result;
    }
};