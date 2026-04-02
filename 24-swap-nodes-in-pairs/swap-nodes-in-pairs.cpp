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
    ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = head->next;  // new head will be 2nd node
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr && curr->next) {
        ListNode* nextPair = curr->next->next;
        ListNode* second = curr->next;
        // swap
        second->next = curr;
        curr->next = nextPair;
        // connect previous pair
        if (prev != NULL) {
            prev->next = second;
        }
        // move pointers forward
        prev = curr;
        curr = nextPair;
    }

    return newHead;
}
    
};