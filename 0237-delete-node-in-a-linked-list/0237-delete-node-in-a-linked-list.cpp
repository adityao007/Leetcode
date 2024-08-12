class Solution {
public:
    void deleteNode(ListNode* node) {
        // Since you can't delete the current node directly, copy the data from the next node.
        node->val = node->next->val;
        // Save the next node to delete it later.
        ListNode* temp = node->next;
        // Link to the node after the next node.
        node->next = node->next->next;
        // Delete the copied node.
        delete temp;
    }
};