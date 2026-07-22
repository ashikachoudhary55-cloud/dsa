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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* prev1 = NULL;
        ListNode* prev2 = NULL;
        while (t1 != NULL) {
            ListNode* front = t1->next;
            t1->next = prev1;
            prev1 = t1;
            t1 = front;
        } //prev1 stores the head
        while (t2 != NULL) {
            ListNode* front = t2->next;
            t2->next = prev2;
            prev2 = t2;
            t2 = front;
        } //prev2 stores the head
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        int sum = 0, carry = 0;
        while(prev1 != NULL || prev2 != NULL) {
            sum = carry;
            if (prev1 != NULL) sum = sum + prev1->val;
            if (prev2 != NULL) sum = sum + prev2->val;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = newNode;
            curr = newNode;
            if(prev1 != NULL) prev1 = prev1->next;
            if(prev2 != NULL) prev2 = prev2->next;
        }
        if (carry != 0) {
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
            curr = newNode;
        }
        curr->next = NULL;
        ListNode* x = dummy->next;
        dummy->next = NULL;
        ListNode* prev = NULL;
        while (x != NULL) {
            ListNode* front = x->next;
            x->next = prev;
            prev = x;
            x = front;
        }
        return prev;
    }
};