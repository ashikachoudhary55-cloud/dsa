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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* t = head;
        int c = 1;
        ListNode* dN1 = new ListNode(-1);
        ListNode* dN2 = new ListNode(-1);
        ListNode* curr1 = dN1;
        ListNode* curr2 = dN2;

        while (t != NULL) {
            if (c%2 != 0) {
                ListNode* newNode = new ListNode(t->val);
                curr1->next = newNode;
                curr1 = newNode;
                c++;
                t = t->next;
            }
            else if (c%2 == 0) {
                ListNode* newNode = new ListNode(t->val);
                curr2->next = newNode;
                curr2 = newNode;
                c++;
                t = t->next;
            }
        }
        ListNode* temp = dN2->next;
        curr1->next = temp;
        dN2->next = NULL;
        return dN1->next;
    }
};