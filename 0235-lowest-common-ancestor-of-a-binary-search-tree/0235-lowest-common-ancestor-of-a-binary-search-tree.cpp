/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    /**
     * Finds the lowest common ancestor (LCA) of two nodes in a Binary Search Tree.
     * 
     * @param root - The root node of the BST
     * @param p - First target node
     * @param q - Second target node
     * @return The lowest common ancestor node of p and q
     * 
     * Algorithm:
     * - Utilizes BST property: left subtree values < root value < right subtree values
     * - If both p and q values are less than current node, LCA must be in left subtree
     * - If both p and q values are greater than current node, LCA must be in right subtree
     * - Otherwise, current node is the LCA (split point or one of the nodes itself)
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Iterative approach to find LCA
        while (true) {
            // Both nodes are in the right subtree
            if (root->val < std::min(p->val, q->val)) {
                root = root->right;
            }
            // Both nodes are in the left subtree
            else if (root->val > std::max(p->val, q->val)) {
                root = root->left;
            }
            // Current node is the LCA (split point or equal to p or q)
            else {
                return root;
            }
        }
    }
};