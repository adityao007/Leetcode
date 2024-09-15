class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == NULL) {
            return -1;
        }

        queue<TreeNode*> Q;
        Q.push(root);
        vector<long long> levelSums; 

        while (!Q.empty()) {
            int levelSize = Q.size(); 
            long long levelSum = 0; 

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = Q.front();
                Q.pop();
                
                levelSum += curr->val;

                if (curr->left != nullptr) {
                    Q.push(curr->left);
                }

                if (curr->right != nullptr) {
                    Q.push(curr->right);
                }
            }

            levelSums.push_back(levelSum);
        }

        sort(levelSums.begin(), levelSums.end(), greater<long long>());

        if (k > levelSums.size()) {
            return -1; 
        }
        return levelSums[k - 1];
    }
};