class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        //find the middle of the linkedList
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        //reverse 
        ListNode* prev = nullptr;
        while (slow) {
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        //checking
        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;        
    }
};