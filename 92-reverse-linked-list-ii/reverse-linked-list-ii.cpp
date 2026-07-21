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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || left == right) return head;
        int c = 1;
        ListNode* temp = head;
        while (c != left) {
            c++;
            temp = temp->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        for (int i=left; i<=right; i++) {
            curr->next = temp;
            curr = temp;
            temp = temp->next;
        }
        curr->next = NULL;
        ListNode* current = dummy->next;
        dummy->next = NULL;
        ListNode* prev = NULL;
        while (current != NULL) {
            ListNode* front = current->next;
            current->next = prev;
            prev = current;
            current = front; 
        }
        if (left == 1) head = prev;
        else { 
            int count = 1;
            ListNode* x = head;
            while (count != left-1) {
                count ++;
                x = x->next;
            }
            x->next = prev;
        }
        ListNode* y = prev;
        while (y->next != NULL) {
            y = y->next;
        }
        y->next = temp;
        return head;
    }
};