class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ngeMap;  
        stack<int> s;

        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                ngeMap[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        while (!s.empty()) {
            ngeMap[s.top()] = -1;
            s.pop();
        }

        vector<int> result;
        for (int num : nums1) {
            result.push_back(ngeMap[num]);
        }

        return result;
    }
};