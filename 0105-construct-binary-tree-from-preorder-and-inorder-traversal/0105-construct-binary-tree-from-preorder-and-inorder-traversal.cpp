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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int totalNodes = preorder.size();
      
        // Create a map to store the index of each value in inorder array
        // This allows O(1) lookup when finding the root position in inorder
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < totalNodes; ++i) {
            inorderIndexMap[inorder[i]] = i;
        }
      
        // Recursive function to build the tree
        // Parameters:
        // - preorderStart: starting index in preorder array
        // - inorderStart: starting index in inorder array  
        // - subtreeSize: number of nodes in current subtree
        function<TreeNode*(int, int, int)> buildSubtree = [&](int preorderStart, int inorderStart, int subtreeSize) -> TreeNode* {
            // Base case: empty subtree
            if (subtreeSize <= 0) {
                return nullptr;
            }
          
            // The first element in preorder range is always the root
            int rootValue = preorder[preorderStart];
          
            // Find root's position in inorder array
            int rootIndexInInorder = inorderIndexMap[rootValue];
          
            // Calculate size of left subtree
            int leftSubtreeSize = rootIndexInInorder - inorderStart;
          
            // Recursively build left subtree
            // Left subtree in preorder: starts right after root
            // Left subtree in inorder: from inorderStart to rootIndexInInorder-1
            TreeNode* leftChild = buildSubtree(preorderStart + 1, inorderStart, leftSubtreeSize);
          
            // Recursively build right subtree
            // Right subtree in preorder: starts after root and left subtree
            // Right subtree in inorder: starts right after root
            // Right subtree size: total - 1(root) - leftSubtreeSize
            TreeNode* rightChild = buildSubtree(preorderStart + 1 + leftSubtreeSize, 
                                                rootIndexInInorder + 1, 
                                                subtreeSize - 1 - leftSubtreeSize);
          
            // Create and return the root node with its children
            return new TreeNode(rootValue, leftChild, rightChild);
        };
      
        // Build the entire tree starting from index 0 with all nodes
        return buildSubtree(0, 0, totalNodes);
    }
};