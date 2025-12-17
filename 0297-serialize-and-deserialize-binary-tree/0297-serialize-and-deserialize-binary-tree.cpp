/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    /**
     * Encodes a tree to a single string using level-order traversal (BFS).
     * Null nodes are represented as "#" in the serialized string.
     * @param root The root of the binary tree to serialize
     * @return A string representation of the tree
     */
    string serialize(TreeNode* root) {
        // Handle empty tree case
        if (!root) {
            return "";
        }
      
        // Use queue for level-order traversal
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        string serializedResult;
      
        // Process all nodes including nulls
        while (!nodeQueue.empty()) {
            TreeNode* currentNode = nodeQueue.front();
            nodeQueue.pop();
          
            if (currentNode) {
                // Append node value and add children to queue
                serializedResult += to_string(currentNode->val) + " ";
                nodeQueue.push(currentNode->left);
                nodeQueue.push(currentNode->right);
            } else {
                // Use "#" to represent null nodes
                serializedResult += "# ";
            }
        }
      
        // Remove trailing space
        serializedResult.pop_back();
        return serializedResult;
    }

    /**
     * Decodes the encoded string back to a binary tree.
     * Reconstructs the tree using level-order traversal.
     * @param data The serialized string representation of the tree
     * @return The root of the reconstructed binary tree
     */
    TreeNode* deserialize(string data) {
        // Handle empty tree case
        if (data.empty()) {
            return nullptr;
        }
      
        // Parse the serialized string
        stringstream stringStream(data);
        string token;
      
        // Create root node
        stringStream >> token;
        TreeNode* root = new TreeNode(stoi(token));
      
        // Use queue to track parent nodes for level-order reconstruction
        queue<TreeNode*> parentQueue;
        parentQueue.push(root);
      
        // Process remaining tokens to build tree
        while (!parentQueue.empty()) {
            TreeNode* parentNode = parentQueue.front();
            parentQueue.pop();
          
            // Process left child
            stringStream >> token;
            if (token != "#") {
                parentNode->left = new TreeNode(stoi(token));
                parentQueue.push(parentNode->left);
            }
          
            // Process right child
            stringStream >> token;
            if (token != "#") {
                parentNode->right = new TreeNode(stoi(token));
                parentQueue.push(parentNode->right);
            }
        }
      
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));