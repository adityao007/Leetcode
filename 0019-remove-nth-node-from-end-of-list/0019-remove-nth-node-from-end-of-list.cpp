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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(0, head);
        
        ListNode* fastPointer = dummyNode;
        ListNode* slowPointer = dummyNode;

        for(int i = 0; i < n; i++) {
            fastPointer = fastPointer->next;
        }
        while (fastPointer->next != nullptr) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next;
        }

        slowPointer->next = slowPointer->next->next;
        ListNode* newHead = dummyNode->next;
        delete dummyNode;
        return newHead;
    }
};