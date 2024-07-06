class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
    if (n < 3) {
        return 0;
    }

    int alternatingGroupsCount = 0;

    for (int i = 0; i < n; ++i) {
        int prev = colors[(i - 1 + n) % n];
        int current = colors[i];
        int next = colors[(i + 1) % n];

        if (current != prev && current != next && prev == next) {
            ++alternatingGroupsCount;
        }
    }

    return alternatingGroupsCount;
    }
};