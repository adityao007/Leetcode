class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_set<int> suspiciousMethods;
        suspiciousMethods.insert(k);
        bool changed = true;

        while (changed) {
            changed = false;
            for (const auto& invocation : invocations) {
                int a = invocation[0];
                int b = invocation[1];
                if (suspiciousMethods.count(a) && !suspiciousMethods.count(b)) {
                    suspiciousMethods.insert(b);
                    changed = true;
                }
            }
        }

        for (const auto& invocation : invocations) {
            int a = invocation[0];
            int b = invocation[1];
            if (!suspiciousMethods.count(a) && suspiciousMethods.count(b)) {
                return createArray(n);
            }
        }

        vector<int> remainingMethods;
        for (int i = 0; i < n; i++) {
            if (!suspiciousMethods.count(i)) {
                remainingMethods.push_back(i);
            }
        }
        
        return remainingMethods;
    }

    vector<int> createArray(int n) {
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = i;
        }
        return result;
    }
};
