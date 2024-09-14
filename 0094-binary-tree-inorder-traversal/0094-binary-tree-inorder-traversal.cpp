class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }

private:
    void inorderHelper(TreeNode* root,vector<int>& result) {
        if(root==NULL){
            return;
        }
        inorderHelper(root->left,result);
        result.push_back(root->val);
        inorderHelper(root->right,result);

    }
};