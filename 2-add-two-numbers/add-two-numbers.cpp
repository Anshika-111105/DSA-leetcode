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
   ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (curr != nullptr) {
            next = curr->next; // Save the next node
            curr->next = prev; // Reverse the current node's pointer
            prev = curr;       // Move prev one step ahead
            curr = next;       // Move curr one step ahead
        }
        return prev;
    }

    // Function to add two numbers represented by linked lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* result = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get the values of the nodes, or 0 if the list has ended
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            // Calculate the sum and carry
            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            
            // Create a new node for the current digit
            ListNode* newNode = new ListNode(digit);
            
            // Append the new node to the result list
            if (result == nullptr) {
                result = newNode; // First node
            } else {
                tail->next = newNode; // Append to the tail
            }
            tail = newNode;
            
            // Move to the next nodes in the input lists
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        // Reverse the result list back to normal order
        return result;
    }
};