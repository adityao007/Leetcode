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
    /**
     * Find the kth smallest element in a Binary Search Tree (BST)
     * Uses iterative in-order traversal to visit nodes in ascending order
     * 
     * @param root: The root node of the BST
     * @param k: The position of the smallest element to find (1-indexed)
     * @return: The value of the kth smallest element
     */
    int kthSmallest(TreeNode* root, int k) {
        // Stack to maintain nodes for iterative in-order traversal
        std::stack<TreeNode*> nodeStack;
      
        // Current node pointer for traversal
        TreeNode* currentNode = root;
      
        // Continue until we've processed all nodes or found the kth element
        while (currentNode != nullptr || !nodeStack.empty()) {
            // Traverse to the leftmost node, pushing all nodes along the path
            if (currentNode != nullptr) {
                nodeStack.push(currentNode);
                currentNode = currentNode->left;
            } 
            // Process the next node in in-order sequence
            else {
                // Pop the next node to process (smallest unprocessed node)
                currentNode = nodeStack.top();
                nodeStack.pop();
              
                // Decrement k and check if this is the kth smallest element
                k--;
                if (k == 0) {
                    return currentNode->val;
                }
              
                // Move to the right subtree to continue in-order traversal
                currentNode = currentNode->right;
            }
        }
      
        // This line should never be reached if k is valid
        return 0;
    }
};