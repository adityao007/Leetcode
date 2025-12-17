/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // Map to store the mapping from original nodes to cloned nodes
        // This prevents infinite recursion and ensures each node is cloned only once
        unordered_map<Node*, Node*> originalToClone;
      
        // Recursive DFS function to clone the graph
        auto dfs = [&](this auto&& dfs, Node* currentNode) -> Node* {
            // Base case: if node is null, return null
            if (!currentNode) {
                return nullptr;
            }
          
            // If this node has already been cloned, return the cloned version
            // This handles cycles in the graph
            if (originalToClone.contains(currentNode)) {
                return originalToClone[currentNode];
            }
          
            // Create a new node with the same value as the original
            Node* clonedNode = new Node(currentNode->val);
          
            // Store the mapping before processing neighbors to handle cycles
            originalToClone[currentNode] = clonedNode;
          
            // Recursively clone all neighbors and add them to the cloned node
            for (auto& neighbor : currentNode->neighbors) {
                clonedNode->neighbors.push_back(dfs(neighbor));
            }
          
            return clonedNode;
        };
      
        // Start the DFS traversal from the given node
        return dfs(node);
    }
};
