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
    bool validatehelper(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == NULL) {
            return true;
        }

        if (min != NULL && root->val <= min->val) {
            return false;
        }
        if (max != NULL && root->val >= max->val) {
            return false;
        }

        return validatehelper(root->left, min, root) &&  
               validatehelper(root->right, root, max);   
    }

    bool isValidBST(TreeNode* root) {
        return validatehelper(root, NULL, NULL); 
    }
};
