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
    
TreeNode* getInorderSuccessor(TreeNode* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;//IS
}

TreeNode* deleteNode(TreeNode* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(val<root->val){
        root->left=deleteNode(root->left,val);
    }
    else if(val>root->val){
        root->right=deleteNode(root->right,val);
    }else{
        // root==val
        // case1 0children
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // case 2 1 child
        if(root->left==NULL || root->right==NULL){
            return root->left ==NULL ? root->right:root->left;
        }
        // case 3 2 children
        TreeNode* IS=getInorderSuccessor(root->right);
        root->val=IS->val;
        root->right=deleteNode(root->right,IS->val);
        return root;
    }
     return root;
}


};