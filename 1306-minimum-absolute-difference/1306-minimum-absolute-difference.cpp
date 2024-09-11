class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> result;
        int absDiff = INT_MAX;

        for (int i = 1; i < arr.size(); i++) {
            absDiff = min(absDiff, arr[i] - arr[i - 1]);
        }

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == absDiff) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }
        return result;
    }
};
