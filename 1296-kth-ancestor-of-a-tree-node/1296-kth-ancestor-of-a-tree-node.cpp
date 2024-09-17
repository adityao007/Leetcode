class TreeAncestor {
private:
    vector<vector<int>> up;
    int LOG;

public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        up = vector<vector<int>>(n, vector<int>(LOG, -1));

        for (int i = 0; i < n; ++i) {
            up[i][0] = parent[i];
        }

        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                if (up[i][j-1] != -1) {
                    up[i][j] = up[up[i][j-1]][j-1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG; ++j) {
            if (k & (1 << j)) {
                node = up[node][j];
                if (node == -1) {
                    return -1;
                }
            }
        }
        return node;
    }
};
