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
    ListNode* doubleIt(ListNode* head) {
        ListNode* a = head;
        ListNode* prev = NULL;
        while (a != NULL) {
            ListNode* front = a->next;
            a->next = prev;
            prev = a;
            a = front;
        }
        //prev=head;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0, prod = 1, sum = 0;
        while (prev != NULL) {
            sum = carry;
            prod = 2*(prev->val) + sum;
            ListNode* newNode = new ListNode(prod % 10);
            carry = prod / 10;
            curr->next = newNode;
            curr = newNode;
            prev = prev->next;
        }
        if (carry != 0) {
            ListNode* newNode = new ListNode(carry);
            curr->next  = newNode;
            curr = newNode;
        }
        ListNode* x = dummy->next;
        curr->next = NULL;
        dummy->next = NULL;
        ListNode* p = NULL;
        while (x != NULL) {
            ListNode* front = x->next;
            x->next = p;
            p = x;
            x = front;
        }
        return p;
    }
};