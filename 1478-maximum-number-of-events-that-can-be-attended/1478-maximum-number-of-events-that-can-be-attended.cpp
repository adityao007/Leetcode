class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        
        int day = 0;
        int eventCount = 0; 
        int i = 0; 
        int n = events.size();

        for (day = 1; day <= 100000; day++) {
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]); 
                i++;
            }

            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();  
                eventCount++;  
            }
            if (i == n && pq.empty()) {
                break;
            }
        }

        return eventCount;
    }
};