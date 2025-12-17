/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /**
     * Swaps every two adjacent nodes in a linked list recursively
     * @param head: pointer to the head of the linked list
     * @return: pointer to the new head after swapping pairs
     */
    ListNode* swapPairs(ListNode* head) {
        // Base case: if list is empty or has only one node, no swap needed
        if (!head || !head->next) {
            return head;
        }
      
        // Recursively swap the remaining pairs starting from the third node
        ListNode* remainingList = swapPairs(head->next->next);
      
        // Store the second node which will become the new head of this pair
        ListNode* newHead = head->next;
      
        // Perform the swap: second node points to first node
        newHead->next = head;
      
        // First node now points to the result of swapping remaining pairs
        head->next = remainingList;
      
        // Return the new head (originally the second node)
        return newHead;
    }
};
