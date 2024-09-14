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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {
            int size = Q.size();
            vector<int> currentLevel;

            for (int i = 0; i < size; ++i) {
                TreeNode* curr = Q.front();
                Q.pop();
                currentLevel.push_back(curr->val);

                if (curr->left != nullptr) {
                    Q.push(curr->left);
                }

                if (curr->right != nullptr) {
                    Q.push(curr->right);
                }
            }

            result.push_back(currentLevel);
        }

        return result;
    }
};
