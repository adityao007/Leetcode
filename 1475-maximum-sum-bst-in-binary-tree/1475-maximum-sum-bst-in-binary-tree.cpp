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
    int maxSum = 0;
    
    struct NodeInfo {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };
    
    NodeInfo dfs(TreeNode* root) {
        if (root==NULL) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        NodeInfo left = dfs(root->left);
        NodeInfo right = dfs(root->right);


        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currentSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currentSum);
            return {true, currentSum, min(root->val, left.minVal), max(root->val, right.maxVal)};
        }

        return {false, 0, 0, 0};
    }
    
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        dfs(root);
        return maxSum;
    }
};
