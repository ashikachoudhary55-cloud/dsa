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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        int total = 0;
        while (temp != NULL) {
            total ++;
            temp = temp->next;
        }
        k = k%total;
        if (k == 0) return head;
        int n = total-k;
        temp = head;
        int c = 1;
        while (temp != NULL && c != n) {
            c++;
            temp = temp->next;
        }
        ListNode* x = temp->next;
        temp->next = NULL;
        ListNode* y = x;
        while (x->next != NULL) {
            x = x->next;
        }
        x->next = head;
        return y;
    }
};