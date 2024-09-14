/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> Q;
        Q.push(root);

        int maxSum = INT_MIN;
        int maxLevel = 0;
        int currentLevel = 0;

        while (!Q.empty()) {
            int levelSize = Q.size();
            int levelSum = 0;
            currentLevel++;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = Q.front();
                Q.pop();
                levelSum += node->val;

                if (node->left != nullptr) {
                    Q.push(node->left);
                }
                if (node->right != nullptr) {
                    Q.push(node->right);
                }
            }

            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = currentLevel;
            }
        }

        return maxLevel;
    }
};