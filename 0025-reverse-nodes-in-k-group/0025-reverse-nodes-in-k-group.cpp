class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Create a dummy node pointing to head for easier manipulation
        ListNode* dummyHead = new ListNode(0, head);
      
        // Pointer to track the node before the current group
        ListNode* prevGroupEnd = dummyHead;

        while (prevGroupEnd != nullptr) {
            // Check if there are at least k nodes remaining
            ListNode* currentNode = prevGroupEnd;
            for (int i = 0; i < k; i++) {
                currentNode = currentNode->next;
                if (currentNode == nullptr) {
                    // Less than k nodes remaining, return the result
                    return dummyHead->next;
                }
            }

            // Save pointers for the current group
            ListNode* groupStart = prevGroupEnd->next;  // First node of current group
            ListNode* nextGroupStart = currentNode->next;  // First node of next group
          
            // Disconnect the current group from the rest of the list
            currentNode->next = nullptr;
          
            // Reverse the current group and connect it back
            prevGroupEnd->next = reverseList(groupStart);
          
            // After reversal, groupStart becomes the last node of the reversed group
            groupStart->next = nextGroupStart;
          
            // Move prevGroupEnd to the end of the current reversed group
            prevGroupEnd = groupStart;
        }
      
        return dummyHead->next;
    }

private:
    // Helper function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        // Create a dummy node to simplify the reversal process
        ListNode* dummyNode = new ListNode();
        ListNode* current = head;
      
        // Iterate through the list and reverse connections
        while (current != nullptr) {
            ListNode* nextNode = current->next;  // Save the next node
            current->next = dummyNode->next;     // Point current to the previous reversed portion
            dummyNode->next = current;           // Update dummy to point to current
            current = nextNode;                  // Move to the next node
        }
      
        return dummyNode->next;
    }
};