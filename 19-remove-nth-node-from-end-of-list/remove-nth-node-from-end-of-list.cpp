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
        ListNode* t = head;
        int total = 0;
        while (t != NULL) {
            total ++;
            t = t->next;
        }
        int N = total-n+1;
        if (N == 1) {
            ListNode* x = head;
            head = head->next;
            x->next = NULL;
            return head;
        }
        int count = 1;
        ListNode* temp = head;
        while (count != N-1) {
            temp = temp->next;
            count ++;
        }
        ListNode* x = temp->next;
        temp->next = x->next;
        x->next = NULL;
        return head;
    }
};