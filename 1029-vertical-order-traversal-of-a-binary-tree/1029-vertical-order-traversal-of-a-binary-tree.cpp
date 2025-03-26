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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        map<int,vector<pair<int,int>>> columnMap;

        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

         while (!q.empty()) {
        auto front = q.front();
        q.pop();
        
        TreeNode* node = front.first;
        int vertical = front.second.first;
        int row = front.second.second;

        // Store in the map
        columnMap[vertical].push_back({row, node->val});

        // Push left and right children with updated vertical & row indices
        if (node->left)
            q.push({node->left, {vertical - 1, row + 1}});
        if (node->right)
            q.push({node->right, {vertical + 1, row + 1}});
    }
    vector<vector<int>> result;
    for (auto& [_, nodes] : columnMap) {
        // Sort by (row_level, value)
        sort(nodes.begin(), nodes.end());
        
        // Extract only values
        vector<int> column;
        for (auto& [_, value] : nodes) {
            column.push_back(value);
        }
        result.push_back(column);
    }

    return result;

    }
};