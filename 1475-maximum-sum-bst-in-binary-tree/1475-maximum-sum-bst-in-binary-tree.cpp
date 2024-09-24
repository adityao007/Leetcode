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
    int maxSum = 0; // To keep track of the maximum sum of valid BSTs
    
    struct NodeInfo {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };
    
    NodeInfo dfs(TreeNode* root) {
        if (!root) {
            // Empty subtree is considered a valid BST with sum 0, and extreme min/max values
            return {true, 0, INT_MAX, INT_MIN};
        }

        // Perform DFS on the left and right children
        NodeInfo left = dfs(root->left);
        NodeInfo right = dfs(root->right);

        // Check if current subtree rooted at `root` is a valid BST
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            // If valid BST, calculate the sum of this subtree
            int currentSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currentSum);
            return {true, currentSum, min(root->val, left.minVal), max(root->val, right.maxVal)};
        }

        // If not a valid BST, return invalid result
        return {false, 0, 0, 0};
    }
    
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        dfs(root);
        return maxSum;
    }
};
