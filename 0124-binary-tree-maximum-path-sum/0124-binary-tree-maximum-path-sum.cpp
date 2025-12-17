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
    int maxPathSum(TreeNode* root) {
        // Initialize the maximum path sum to the smallest possible value
        // (constraints: node values are in range [-1000, 1000])
        int maxSum = INT_MIN;
      
        // Define a recursive function to calculate the maximum path sum
        // Returns the maximum path sum starting from the current node and going down
        function<int(TreeNode*)> calculateMaxPath = [&](TreeNode* node) -> int {
            // Base case: if node is null, contribute 0 to the path
            if (!node) {
                return 0;
            }
          
            // Recursively get the maximum path sum from left and right subtrees
            // Use max(0, ...) to ignore negative paths (we can choose not to include them)
            int leftMaxPath = max(0, calculateMaxPath(node->left));
            int rightMaxPath = max(0, calculateMaxPath(node->right));
          
            // Calculate the maximum path sum that passes through the current node
            // This path includes both left and right subtrees plus the current node value
            int currentMaxPath = leftMaxPath + rightMaxPath + node->val;
          
            // Update the global maximum if the current path is larger
            maxSum = max(maxSum, currentMaxPath);
          
            // Return the maximum path sum starting from this node going down
            // We can only choose either left or right path (not both) when extending upward
            return node->val + max(leftMaxPath, rightMaxPath);
        };
      
        // Start the DFS traversal from the root
        calculateMaxPath(root);
      
        // Return the maximum path sum found
        return maxSum;
    }
};